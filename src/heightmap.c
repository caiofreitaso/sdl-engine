#include "../include/render/heightmap.h"

const float HEIGHT_SCALE = 0.03125;

float* heightmap_init(heightmap_t* h, map_t m)
{
	//memory allocation
	unsigned f_size = m.x * m.y * 2;
	unsigned v_size = (m.x + 1) * (m.y + 1);
	unsigned i_size = ((m.y + 1) * 2) * m.x + m.x - 1;
	
	h->r_index = m.x*m.y;

	h->vertices.increment = sizeof(vertex_t);
	h->vertices.reserved  = h->vertices.size = v_size;
	h->vertices.array     = malloc(v_size * sizeof(vertex_t));

	h->indices.increment = sizeof(unsigned);
	h->indices.reserved  = h->indices.size = i_size;
	h->indices.array     = malloc(i_size * sizeof(unsigned));

	//get vertex positions
	at(h->vertices,0, vertex_t)->position.x = 0;
	at(h->vertices,0, vertex_t)->position.y = 0;
	at(h->vertices,0, vertex_t)->position.z = m.field[0].height*HEIGHT_SCALE;

	unsigned i, j;
	for (i = 1; i < m.y+1; i++)
	{
		at(h->vertices,i, vertex_t)->position.x = 0;
		at(h->vertices,i, vertex_t)->position.y = i;
		at(h->vertices,i, vertex_t)->position.z = m.field[i-1].height*HEIGHT_SCALE;
	}

	for (i = 1; i < m.x+1; i++)
		for (j = 0; j < m.y+1; j++)
		{
			at(h->vertices,i*(m.y+1)+j, vertex_t)->position.x = i;
			at(h->vertices,i*(m.y+1)+j, vertex_t)->position.y = j;
			if (j)
				at(h->vertices,i*(m.y+1)+j, vertex_t)->position.z =
					m.field[((i-1)*m.y)+j-1].height * HEIGHT_SCALE;
			else
				at(h->vertices,i*(m.y+1)+j, vertex_t)->position.z =
					m.field[((i-1)*m.y)+j].height * HEIGHT_SCALE;
		}


	for(i = 0; i < m.x; i++)
		for(j = 0; j < m.y; j++)
			fprintf(stderr, "%.0f\n", m.field[i*m.y+j].height);

	FOR_EACH(vertex_t, v, h->vertices)
		fprintf(stderr, "%.0f %.0f %.0f\n",
				v->position.x,
				v->position.y,
				v->position.z);
	END_FOR

	//get triangles
	unsigned *face_ptr = (unsigned*)h->indices.array;
	for (i = 0; i < m.x; i++)
	{
		for (j = 0; j < m.y+1; j++)
		{
			*face_ptr = i*(m.y+1)+j;
			face_ptr++;
			*face_ptr = (i+1)*(m.y+1)+j;
			face_ptr++;
		}
		if (i < m.x-1)
		{
			*face_ptr = h->r_index;
			face_ptr++;
		}
	}

	//get face normals
	point3_t *normals = malloc(f_size * sizeof(point3_t));
	float    *areas   = malloc(f_size * sizeof(float));

	face_ptr = (unsigned*)h->indices.array;
	i = 0;
	do
	{
		face_t face = *((face_t*) face_ptr);

		if (face.c == face.b)
			face_ptr += 2;
		else
		{
			normals[i] = face_normal(*h,face);
			areas  [i] = face_area(*h,face);
			normals[i] = mul3D(normals[i], areas[i]);
			i++;
		}

		face_ptr++;
	} while (i < f_size);

	//get vertices normals
	{
		point3_t *normal;

		//first
		at(h->vertices,0,vertex_t)->normal = normalize3D(normals[0]);
		//last of 1st row
		normal = &at(h->vertices,m.y,vertex_t)->normal;
		*normal = normalize3D(add3D(normals[2*m.y-1], normals[2*m.y-2]));


		//first row
		for (i = 1; i < m.y; i++)
		{
			normal = &at(h->vertices,i,vertex_t)->normal;
			*normal = origin3D;
			for (j = 0; j < 3; j++)
				*normal = add3D(*normal, normals[2*i-j]);
			*normal = normalize3D(*normal);
		}

		//first column
		for (i = 1; i < m.x; i++)
		{
			normal = &at(h->vertices,i*(m.y+1),vertex_t)->normal;
			*normal = add3D(normals[2*(i-1)*m.y],normals[2*(i-1)*m.y+1]);
			*normal = add3D(*normal,normals[i*m.y]);
			*normal = normalize3D(*normal);
		}

		//last column
		for (i = 1; i < m.x; i++)
		{
			normal = &at(h->vertices,i*(m.y+1)+m.y,vertex_t)->normal;
			*normal = add3D(normals[2*i*m.y-1],normals[2*(i+1)*m.y-1]);
			*normal = add3D(*normal,normals[2*(i+1)*m.y-2]);
			*normal = normalize3D(*normal);
		}

		//last row
		for (i = 1; i < m.y; i++)
		{
			normal = &at(h->vertices,m.x*(m.y+1)+i,vertex_t)->normal;
			*normal = origin3D;
			int k;
			for (k = -1; k < 2; k++)
				*normal = add3D(*normal, normals[f_size-m.y+2*i+k]);
			*normal = normalize3D(*normal);
		}

		//middle
		for (i = 1; i < m.x; i++)
			for (j = 1; j < m.y; j++)
			{
				normal = &at(h->vertices,i*(m.y+1)+j,vertex_t)->normal;
				*normal =
					add3D(
						add3D(
							add3D(
								normals[2*i*m.x+2*j],
								normals[2*i*m.x+2*j-1]
							),
							add3D(
								normals[2*i*m.x+2*j-2],
								normals[2*(i-1)*m.x+2*j-1]
							)
						),
						add3D(
							normals[2*(i-1)*m.x+2*j],
							normals[2*(i-1)*m.x+2*j+1]
						)
					);
				*normal = normalize3D(*normal);
			}

		//first of last row
		normal = &at(h->vertices,v_size-m.y-1,vertex_t)->normal;
		*normal = normalize3D(add3D(normals[f_size-2*m.y], normals[f_size-2*m.y+1]));
		//last of all
		normal = &at(h->vertices,h->vertices.size-1,vertex_t)->normal;
		*normal = normalize3D(normals[f_size-1]);
	}

	free(normals);

	return areas;
}

point3_t face_normal(heightmap_t h, face_t f)
{
	point3_t normal = normal3D(at(h.vertices,f.b,vertex_t)->position,
						at(h.vertices,f.a,vertex_t)->position,
						at(h.vertices,f.c,vertex_t)->position);
	if (normal.v[1] < 0)
		normal = mul3D(normal,-1.0f);
	return normal;
}

float face_area(heightmap_t h, face_t f)
{
	return area3D(at(h.vertices,f.a,vertex_t)->position,
			at(h.vertices,f.b,vertex_t)->position,
			at(h.vertices,f.c,vertex_t)->position);
}