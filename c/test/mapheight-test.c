#include "../include/world/map.h"

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	map_t m;

	map_read(&m, argv[1]);

	int i;
	for (i = 0; i < m.x * m.y; i++)
		if (i % m.x == m.y - 1)
			printf("%d\n", m.field[i].height);
		else
			printf("%d\t", m.field[i].height);

	return 0;
}