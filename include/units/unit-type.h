#ifndef UNITTYPE_H
#define UNITTYPE_H

#include "../economy/economy.h"

const double HIT_CHANCE[] = { 0.5, 1.9, 4.6, 9.3, 16.2, 25.9, 37.5, 50, 62.5, 74.1, n83.8, 90.7, 95.4, 98.1 };

typedef enum {
	ARMOR_LIGHT,
	ARMOR_HEAVY
} armor_type_e;

typedef enum {
	UNIT_WORKER = 0,
	UNIT_SWORD = 1,
	UNIT_SPEAR = 2,
	UNIT_BOW = 4,
	UNIT_JAVELIN = 8,
	UNIT_CROSSBOW = 16,
	UNIT_CAVALRY = 32,
	UNIT_CATAPULT = 64,
	UNIT_RAM = 128,
	UNIT_LADDER = 256,
	UNIT_TRANSPORT = 512,
	UNIT_BOAT = 1024
} unit_type_e;

typedef enum {
	ATTACK_NONE,
	// Swing damage
	ATTACK_CUTTING,
	// Thrust damage
	ATTACK_IMPALLING
} attack_type_e;

typedef struct {
	unsigned weight;
	unsigned strength;
} projectile_t;

typedef struct {
	attack_type_e type;
	unsigned      range;
	unsigned      dmg_bonus;
	double        cooldown;
	projectile_t* projectile;
	unsigned      num_attacks;
} attack_t;

typedef struct {
	unsigned     max_health;
	armor_type_e armor;
	attack_t     attacks[2];
	unsigned     skill;
	double       speed;
	double       line_of_sight;
} unit_combat_t;

typedef struct {
	resource_t cost;
	resource_t supply;
} unit_economy_t;

typedef struct {
	unit_combat_t  combat;
	unit_economy_t economy;
} unit_type_t;

void unit_type_init(unit_type_t*);



#endif