#ifndef UNIT_H
#define UNIT_H

#include "unit-type.h"
#include "../point.h"

typedef struct {
	point2_t     position;
	
	double       firing_height;
	unsigned     max_health;
	armor_type_e armor;
	attack_t     attacks[2];
	unsigned     skill;
	double       speed;
	double       line_of_sight;

} unit_t;

#endif