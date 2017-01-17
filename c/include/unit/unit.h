#ifndef UNIT_H
#define UNIT_H

#include "../math/point.h"
#include "../util/contiguous.h"
#include <omp.h>

typedef struct
{
	point3_t *position;
	point3_t *target;
	float    *speed;

	unsigned *health;
	unsigned *armor;
	unsigned *damage;

	unsigned *type;

	unsigned reserved;
	unsigned size;
} units_t;



void units_update(units_t *u);

#endif