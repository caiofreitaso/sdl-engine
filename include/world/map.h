#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include "../contiguous.h"

typedef struct {
	unsigned short height;
	unsigned char  terrain;
} map_point_t;

typedef enum {
	GRASS     = 27,
	HARD_SAND = 26,

	TALL_GRASS = 21,

	DENSE_BUSHES = 11,

	SOFT_SAND = 6,
	SWAMP = 5,

	WATER      = 1,
	DEEP_WATER = 0,
} terrain_e;

typedef struct {
	unsigned short x :14;
	unsigned short y :14;

	array_t doodads;

	map_point_t* field;
} map_t;

int  map_read(map_t*, const char*);
void map_free(map_t*);

#endif