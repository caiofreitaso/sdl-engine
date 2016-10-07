#include "../include/world/collision.h"

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
	{
		for (i = 0; i < 16; i++)
		{
			for (j = 0; j < 16; j++)
				if (j == 15)
					printf("%d\n", s->cost->tiles[i][j]);
				else
					printf("%d\t", s->cost->tiles[i][j]);
		}

	}

	printf("-----\n");

	for (i = 0; i < m.x * m.y; i++)
		if (i % m.x == m.y - 1)
			printf("%d\n", m.field[i].terrain);
		else
			printf("%d\t", m.field[i].terrain);

	return 0;
}