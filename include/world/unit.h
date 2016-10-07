#ifndef UNIT_H
#define UNIT_H

#include "../point.h"
#include "../contiguous.h"

typedef struct
{
	point2_t position;

	float unit_radius;
	float los;
	float speed;
	
	unsigned hp;
	unsigned armor;
	unsigned shield;
	unsigned hit;
	
	unsigned food;
	unsigned iron;
	unsigned wood;

	array_t attacks;
} unit_combat_t;



#endif