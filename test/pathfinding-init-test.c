#include "../include/world/flowfield.h"
#include "../include/render/heightmap.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	map_t m;
	heightmap_t hm;
	pathfinding_t pf;

	if (map_read(&m, argv[1]))
	{
		printf("MAP FILE ERROR\n");
		return 0;
	}

	heightmap_init(&hm,&m);
	pathfinding_init(&pf,m);

	int i,j;
	FOR_EACH(cost_sector_t, s, pf.costs)
		for (i = 0; i < SECTOR_SIZE; i++)
		{
			for (j = 0; j < SECTOR_SIZE; j++)
				if (j == SECTOR_SIZE-1)
					printf("%d\n", (*s)[i][j]);
				else
					printf("%d\t", (*s)[i][j]);
		}
	END_FOR

	FOR_EACH(sector_node_t, s, pf.sectors)
		printf("%d ", (cost_sector_t*)s->cost - (cost_sector_t*) pf.costs.array);
	END_FOR

	printf("-----\n");

	for (i = 0; i < m.x * m.y; i++)
		if (i % m.x == m.y - 1)
			printf("%d\n", m.field[i].terrain);
		else
			printf("%d\t", m.field[i].terrain);

	printf("-----\n");

	for (i = 0; i < 2 * m.x * m.y; i=i+2)
		if (i % (2*m.x) == 2*m.y-2)
			printf("%.2f\n", m.areas[i]+m.areas[i+1]);
		else
			printf("%.2f ", m.areas[i]+m.areas[i+1]);
	
	printf("-----\n");

	i = 0;
	FOR_EACH(vertex_t, v, hm.vertices)
		if (v->position.z == 0)
			printf("    ");
		else
			printf("%.1f ", v->position.z);
		if (i % (m.x+1) == m.y)
			printf("\n");
		i++;
	END_FOR

	return 0;
}