#include "../include/world/flowfield.h"

const cost_sector_t WATER_SECTOR = {
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 0, 0, 0, 0}
};

const cost_sector_t BLCKD_SECTOR = {
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1}
};

const cost_sector_t WORST_SECTOR = {
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4},
	{4, 4, 4, 4, 4, 4, 4, 4}
};

const cost_sector_t BAD_SECTOR = {
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10},
	{10, 10, 10, 10, 10, 10, 10, 10}
};

const cost_sector_t GOOD_SECTOR = {
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20},
	{20, 20, 20, 20, 20, 20, 20, 20}
};

const cost_sector_t BEST_SECTOR = {
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25},
	{25, 25, 25, 25, 25, 25, 25, 25}
};

void pathfinding_init(pathfinding_t* p, map_t m)
{
	p->x = m.x/SECTOR_SIZE;
	p->y = m.y/SECTOR_SIZE;

	array_init(&p->costs,   sizeof(cost_sector_t));
	array_init(&p->sectors, sizeof(sector_node_t));
	array_init(&p->flows,   sizeof(flow_sector_t));
	array_init(&p->portals, sizeof(sector_portal_t));
	array_init(&p->graph,   sizeof(unsigned));
	array_init(&p->paths,   sizeof(path_node_t));

	unsigned i;
	unsigned j;
	for (i = 0; i < m.x; i = i + SECTOR_SIZE)
		for (j = 0; j < m.y; j = j + SECTOR_SIZE)
			pathfinding_init_sector(p, m, i, j);
}

void pathfinding_init_sector(pathfinding_t* p, map_t m, unsigned x, unsigned y)
{
	sector_node_t new;

	new.dirty = 0;
	array_init(&new.portals, sizeof(sector_portal_t*));
	
	new.cost = malloc(sizeof(cost_sector_t));
	array_add(&p->costs, new.cost);

	unsigned i, j;
	unsigned different = 0;

	for (i = x; i < x + SECTOR_SIZE; i++)
		for (j = y; j < y + SECTOR_SIZE; j++)
		{
			switch(m.field[i*m.y+j].terrain)
			{
				case GRASS:
				case HARD_SAND:
					break;
				case TALL_GRASS:
					break;
				case DENSE_BUSHES:
					break;
				case SOFT_SAND:
				case SWAMP:
					break;
				case WATER:
				case DEEP_WATER:
					break;
			}
			(*(new.cost))[i-x][j-y] = 0;
		}

	array_add(&p->sectors, &new);
}

unsigned pathfinding_sector_index(pathfinding_t p, unsigned x, unsigned y)
{
	unsigned i = x/SECTOR_SIZE;
	unsigned j = y/SECTOR_SIZE;

	return i*p.y + j;
}

void pathfinding_sectorpath(pathfinding_t p, unsigned from_x, unsigned from_y, unsigned to_x, unsigned to_y)
{
	
}