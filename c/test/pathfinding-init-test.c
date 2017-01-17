#include "../include/world/flowfield.h"
#include "../include/render/heightmap.h"
#include <time.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	unsigned random = (argc == 1);
	int i,j;

	map_t m;
	heightmap_t hm;
	pathfinding_t pf;

	if (!random)
	{
		if (map_read(&m, argv[1]))
		{
			printf("MAP FILE ERROR\n");
			return 0;
		}
	} else
	{
		unsigned terrains[8] = {27,26,21,11,6,5,1,0};

		srand(time(NULL));

		m.x     = 32;
		m.y     = 32;
		m.field = (map_point_t*) malloc(sizeof(map_point_t) * m.x * m.y);
		m.areas = 0;
		array_init(&m.doodads, sizeof(char));

		for (i = 0; i < m.x; i++)
			for (j = 0; j < m.y; j++)
			{
				m.field[i*m.y+j].height  = rand() % 20;
				m.field[i*m.y+j].terrain = terrains[rand() % 6];
			}
	}

	heightmap_init(&hm,&m);
	pf_init(&pf,m);

//	FOR_EACH(cost_sector_t, s, pf.costs)
//		for (i = 0; i < SECTOR_SIZE; i++)
//		{
//			for (j = 0; j < SECTOR_SIZE; j++)
//				if (j == SECTOR_SIZE-1)
//					printf("%d\n", (*s)[i][j]);
//				else
//					printf("%d\t", (*s)[i][j]);
//		}
//	END_FOR
//
//	FOR_EACH(sector_node_t, s, pf.sectors)
//		printf("%d ", ((cost_sector_t*)get_cost(pf,*s)) - ((cost_sector_t*) pf.costs.array));
//	END_FOR
//
//	printf("-----\n");
//
//	for (i = 0; i < m.x * m.y; i++)
//		if (i % m.x == m.y - 1)
//			printf("%d\n", m.field[i].terrain);
//		else
//			printf("%d\t", m.field[i].terrain);
//
//	printf("-----\n");
//
//	for (i = 0; i < 2 * m.x * m.y; i=i+2)
//		if (i % (2*m.x) == 2*m.y-2)
//			printf("%.2f\n", m.areas[i]+m.areas[i+1]);
//		else
//			printf("%.2f ", m.areas[i]+m.areas[i+1]);
//
//	printf("-----\n");
//
	i = 0;
	FOR_EACH(vertex_t, v, hm.vertices)
		if (v->position.x < 10)
			printf("( %.0f,", v->position.x);
		else
			printf("(%.0f,", v->position.x);
		if (v->position.y < 10)
			printf(" %.0f) ", v->position.y);
		else
			printf("%.0f) ", v->position.y);
		if (i % (m.x+1) == m.y)
			printf("\n");
		i++;
	END_FOR

	FOR_EACH(vertex_t, v, hm.vertices)
		if (v->position.z == 0)
			printf("    ");
		else
			printf("%.1f ", v->position.z);
		if (i % (m.x+1) == m.y)
			printf("\n");
		i++;
	END_FOR
//
//	printf("-----\n");
//
//	FOR_EACH(sector_portal_t, p, pf.portals)
//		printf("e:%d p:%d s:%d A:%d B:%d\n", p->edge, p->start, p->size, p->sideA - ((sector_node_t*)pf.sectors.array), p->sideB - ((sector_node_t*)pf.sectors.array));
//	END_FOR

	printf("NUMBER OF PORTALS: %d\n", pf.portals.size);
	printf("NUMBER OF DIFFERENT SECTORS: %d\n", pf.costs.size);
	printf("NUMBER OF ALL SECTORS: %d\n", pf.sectors.size);
	printf("NUMBER OF VERTICES: %d\n", hm.vertices.size);

	return 0;
}