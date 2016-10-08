#include "../include/world/flowfield.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	map_t m;

	if (map_read(&m, argv[1]))
	{
		printf("MAP FILE ERROR\n");
		return 0;
	}

	pathfinding_t pf;

	pathfinding_init(&pf,m);

	int i,j;
	FOR_EACH(sector_node_t, s, pf.sectors)
		for (i = 0; i < SECTOR_SIZE; i++)
		{
			for (j = 0; j < SECTOR_SIZE; j++)
				if (j == SECTOR_SIZE-1)
					printf("%d\n", (*s->cost)[i][j]);
				else
					printf("%d\t", (*s->cost)[i][j]);
		}

	END_FOR

	printf("-----\n");

	for (i = 0; i < m.x * m.y; i++)
		if (i % m.x == m.y - 1)
			printf("%d\n", m.field[i].terrain);
		else
			printf("%d\t", m.field[i].terrain);

	return 0;
}