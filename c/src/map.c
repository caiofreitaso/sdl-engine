#include "../include/map/map.h"

int map_read(map_t* m, const char* f)
{
	FILE *file;

	file = fopen(f, "r");

	if (file == NULL)
		return -1;

	unsigned x, y;

	fscanf(file, "%d %d", &x, &y);

	m->x = x;
	m->y = y;

	array_init(&m->doodads, sizeof(char));
	
	m->field = (map_point_t*) malloc(m->x * m->y * sizeof(map_point_t));

	unsigned i, j;
	unsigned h,t;
	
	for (i = 0; i < m->x; i++)
		for (j = 0; j < m->y; j++)
		{
			fscanf(file, "%d,%d", &h, &t);
			m->field[i*m->y+j].height  = h;
			m->field[i*m->y+j].terrain = t;
		}

	m->areas = 0;

	return 0;
}

void map_free(map_t* m)
{
	free(m->field);
}