#include "../include/world/map.h"

#include <unistd.h>

int main(int argc, char const *argv[])
{
	map_t m;

	m.x = m.y = 4096;

	array_init(&m.doodads, sizeof(char));
	
	printf("%u\n", sizeof(map_point_t));

	m.field = (map_point_t*) malloc(m.x * m.y * sizeof(map_point_t));

	unsigned i,j;
	unsigned h,t;
	
	for (i = 0; i < m.x; i++)
		for (j = 0; j < m.y; j++)
		{
			m.field[i*m.x+j].height  = 0;
			m.field[i*m.x+j].terrain = 0;
		}

	sleep(10000);
	return 0;
}