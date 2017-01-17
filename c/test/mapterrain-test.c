#include "../include/world/map.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	map_t m;

	read_map(&m, argv[1]);

	int i;
	for (i = 0; i < m.x * m.y; i++)
		if (i % m.x == m.y - 1)
			printf("%d\n", m.field[i].terrain);
		else
			printf("%d\t", m.field[i].terrain);

	return 0;
}