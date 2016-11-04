#ifndef FLOWFIELD_H
#define FLOWFIELD_H

#include "map.h"
#include "../point.h"
#include "../contiguous.h"
#include "../sparse.h"

#define SECTOR_SIZE 16

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

unsigned eq_cost_sector(cost_sector_t, cost_sector_t);

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
	BOTTOM,
	RIGHT
} edge_e;

typedef enum {
	CLEAN  = 0,
	DIRTY  = 1,
	NEEDED = 2
} dirty_e;

struct sector_node;

typedef struct sector_portal {
	unsigned edge;  //which edge the portal is from side A
	unsigned start; //start position of the portal from top/left to bottom/right
	unsigned size;  //size of the portal minus one

	struct sector_node *sideA; //pointer to the top/left sector 
	struct sector_node *sideB; //pointer to the bottom/right sector
} sector_portal_t;

typedef struct sector_node {
	unsigned dirty;   //dirty bit, for when buildings change the landscape
	array_t  portals; //array of pointers to portals
	unsigned cost;    //index of the sector, since many will be flat
} sector_node_t;

typedef struct {
	sector_node_t *where; //pointer to the flow's sector
	flow_sector_t *flow;  //pointer to the actual flow

	unsigned flags;       //
	union {
		sector_portal_t *portal; //pointer to flow's destination
		struct {                 //location of destination
			short x;
			short y;
		};
	} to;
} path_node_t;

typedef struct {
	unsigned x;      //size of the map (horizontal)
	unsigned y;      //size of the map (vertical)
	sparse_t graph;  //distance matrix for all portals
	array_t costs;   //array of cost_sector
	array_t sectors; //array of sector_node
	array_t portals; //array of sector_portal
	array_t flows;   //array of flow_sector* for future free()
	array_t paths;   //array 
} pathfinding_t;

void     pf_init(pathfinding_t*, map_t);
void     pf_free(pathfinding_t*);
void     pf_init_sector(pathfinding_t*, map_t, unsigned x, unsigned y);
void     pf_add_portals(pathfinding_t*, unsigned x, unsigned y);
void     pf_update_nodes(pathfinding_t* p);
unsigned pf_sector_index(pathfinding_t, unsigned x, unsigned y);
cost_sector_t* get_cost(pathfinding_t, sector_node_t);

void     pf_sectorpath(pathfinding_t, unsigned from_x, unsigned from_y, unsigned to_x, unsigned to_y);

#endif