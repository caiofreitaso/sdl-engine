#include "../include/world/collision.h"

#include <unistd.h>

int main(int argc, char const *argv[])
{
	array_t all_map;
	array_init(&all_map, sizeof(cost_sector_t));

	unsigned i,j,k, c = 0;
	unsigned max = (4096/16)*(4096/16);

	printf("%lu\n", max);

	for (i = 0; i < max; i++)
	{
		array_add(&all_map, &CLEAR_SECTOR);
		for (j = 0; j < 16; j++)
			for (k = 0; k < 16; k++)
				c++;
	}
	printf("%lu %lu\n", i, c);
	printf("%d\n", all_map.reserved);
	sleep(10000);
	return 0;
}