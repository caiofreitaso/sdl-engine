#include "../include/render/heightmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if (argc == 1)
	{
		printf("NEED MAP FILE\n");
		return 0;
	}

	heightmap_t h;
	map_t m;

	map_read(&m, argv[1]);
	heightmap_init(&h,m);

	printf("MAP = %d, %d\n", m.x, m.y);
	printf("HEIGHTMAP = %d, %d\n", h.vertices.size, h.indices.size);

	FOR_EACH(unsigned, i, h.indices)
		printf("%d ", *i);
	END_FOR
	
	printf("\n");


	sleep(1000);

	return 0;
}