#ifndef FLOWFIELD_H
#define FLOWFIELD_H

#include "map.h"
#include "../point.h"
#include "../contiguous.h"

#define SECTOR_SIZE 8

typedef enum {
	BEST_TERR  = 25,
	GOOD_TERR  = 20,
	BAD_TERR   = 10,
	WORST_TERR = 4,
	BLCKD_TERR = 1,
	WATER_TERR = 0
} movement_cost_e;

typedef enum {
	BLOCKED,
	EAST,
	NORTHEAST,
	NORTH,
	NORTHWEST,
	WEST,
	SOUTHWEST,
	SOUTH,
	SOUTHEAST
} direction_e;

typedef unsigned short cost_sector_t[SECTOR_SIZE][SECTOR_SIZE];

typedef struct {

} integ_sector_t;

typedef unsigned char flow_sector_t[SECTOR_SIZE][SECTOR_SIZE];


extern const cost_sector_t WATER_SECTOR;
extern const cost_sector_t BLCKD_SECTOR;
extern const cost_sector_t WORST_SECTOR;
extern const cost_sector_t BAD_SECTOR;
extern const cost_sector_t GOOD_SECTOR;
extern const cost_sector_t BEST_SECTOR;

// Sector portal
// =============
//
// Each sector is connected to others through portals.
// Those portals are on the edge of their sectors.
// They begin and end at walls on either side.
// There is one portal for each side.
// Each portal center is a node in a N-way graph
// with edges that connect to pathable, same sector
// portals.

typedef enum {
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
} edge_e;

struct sector_node;

typedef struct sector_portal {
	unsigned edge  :2; //which edge the portal is from side A
	unsigned start :3; //start position of the portal [0-7] from top/left to bottom/right
	unsigned size  :3; //size of the portal minus one [0-7]

	struct sector_node *side_A; //top/left sector 
	struct sector_node *side_B; //bottom/right sector
} sector_portal_t;

typedef struct sector_node {
	unsigned char   dirty;       //dirty bit, for when buildings change the landscape
	array_t         portals;     //array of portals, updated when buildings are placed
	flow_sector_t   portal_dist; //distance matrix for sector's portals
	cost_sector_t  *cost;        //pointer to the sector, since many will be flat
} sector_node_t;

typedef struct {
	sector_portal_t *to;
	sector_node_t   *where;
	flow_sector_t   *flow;
} path_node_t;

typedef struct {
	array_t costs;
	array_t sectors;
	array_t flows;
	array_t portals;
	array_t paths;
} pathfinding_t;

void     pathfinding_init(pathfinding_t*, map_t);
void     pathfinding_init_sector(pathfinding_t*, map_t, unsigned, unsigned);
unsigned pathfinding_sector_index(pathfinding_t, unsigned, unsigned);

void     pathfinding_get_sectorpath(pathfinding_t, unsigned from_x, unsigned from_y, unsigned to_x, unsigned to_y);


#endif