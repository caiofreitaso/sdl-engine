#include "../include/world/flowfield.h"

const cost_sector_t WATER_SECTOR = {{0}};
const cost_sector_t BLCKD_SECTOR = {{1}};
const cost_sector_t WORST_SECTOR = {{4}};
const cost_sector_t BAD_SECTOR   = {{10}};
const cost_sector_t GOOD_SECTOR  = {{20}};
const cost_sector_t BEST_SECTOR  = {{25}};

unsigned eq_cost_sector(cost_sector_t a, cost_sector_t b)
{
	unsigned i, j;
	for (i = 0; i < SECTOR_SIZE; i++)
		for (j = 0; j < SECTOR_SIZE; j++)
			if (a[i][j] != b[i][j])
				return 0;
	return 1;
}

cost_sector_t* get_cost(pathfinding_t p, sector_node_t s)
{
	return &((cost_sector_t*)p.costs.array)[s.cost];
}

void pf_init(pathfinding_t* p, map_t m)
{
	p->x = m.x/SECTOR_SIZE;
	p->y = m.y/SECTOR_SIZE;

	array_init(&p->costs,   sizeof(cost_sector_t));
	array_init(&p->sectors, sizeof(sector_node_t));
	array_init(&p->flows,   sizeof(flow_sector_t));
	array_init(&p->portals, sizeof(sector_portal_t));
	array_init(&p->paths,   sizeof(path_node_t));


	unsigned i, j;

	for (i = 0; i < m.x; i = i + SECTOR_SIZE)
		for (j = 0; j < m.y; j = j + SECTOR_SIZE)
			pf_init_sector(p, m, i, j);

	for (i = 0; i < p->x; i++)
		for (j = 0; j < p->y; j++)
			pf_add_portals(p, i, j);

	sparse_init(&p->graph, p->portals.size);
	pf_update_nodes(p);

}

void pf_init_sector(pathfinding_t* p, map_t m, unsigned x, unsigned y)
{
	sector_node_t new;
	cost_sector_t cost;

	new.dirty = 0;
	new.cost = 0;
	array_init(&new.portals, sizeof(sector_portal_t*));
	
	array_add(&p->costs, cost);
	new.cost = p->costs.size-1;
	cost_sector_t *n_cost = get_cost(*p, new);

	unsigned i, j;

	for (i = x; i < x + SECTOR_SIZE; i++)
		for (j = y; j < y + SECTOR_SIZE; j++)
		{
			//TERRAIN
			switch(m.field[i*m.y+j].terrain)
			{
				case GRASS:
				case HARD_SAND:
					(*(n_cost))[i-x][j-y] = BEST_TERR;
					break;
				case TALL_GRASS:
					(*(n_cost))[i-x][j-y] = GOOD_TERR;
					break;
				case DENSE_BUSHES:
					(*(n_cost))[i-x][j-y] = BAD_TERR;
					break;
				case SOFT_SAND:
				case SWAMP:
					(*(n_cost))[i-x][j-y] = WORST_TERR;
					break;
				case WATER:
				case DEEP_WATER:
					(*(n_cost))[i-x][j-y] = WATER_TERR;
					break;
			}

			//AREAS
			{
				unsigned a, b, wouldbe;
				a = 2*i*m.y+2*j;
				b = a + 1;
				wouldbe = i*m.y+j;
				
				float area = m.areas[2*i*m.y+2*j] + m.areas[2*i*m.y+2*j+1];

				if (area > 1.313) //grade 100% or 45°
				{
					if ((*(n_cost))[i-x][j-y] != WATER_TERR)
						(*(n_cost))[i-x][j-y] = BLCKD_TERR;
				}
				else if (area >= 1.0288) //grade 25% or 14°
					switch((*(n_cost))[i-x][j-y])
					{
						case BEST_TERR:
							(*(n_cost))[i-x][j-y] = BAD_TERR;
							break;
						case GOOD_TERR:
							(*(n_cost))[i-x][j-y] = WORST_TERR;
							break;
						case BAD_TERR:
						case WORST_TERR:
							(*(n_cost))[i-x][j-y] = BLCKD_TERR;
							break;
					}
				else if (area >= 1.0049) //grade 10% or 5.71°
					switch((*(n_cost))[i-x][j-y])
					{
						case BEST_TERR:
							(*(n_cost))[i-x][j-y] = GOOD_TERR;
							break;
						case GOOD_TERR:
							(*(n_cost))[i-x][j-y] = BAD_TERR;
							break;
						case BAD_TERR:
							(*(n_cost))[i-x][j-y] = WORST_TERR;
							break;
						case WORST_TERR:
							(*(n_cost))[i-x][j-y] = BLCKD_TERR;
							break;
					}
			}
		}

	//verifying existence of an equal matrix in the array
	FOR_EACH(cost_sector_t, s, p->costs)
		if (s != n_cost)
		{
			if (eq_cost_sector(*s, *get_cost(*p, new)))
			{
				array_pop(&p->costs);
				new.cost = s - ((cost_sector_t*)p->costs.array);
				break;
			}
		}
	END_FOR

	array_add(&p->sectors, &new);
}

void pf_add_portals(pathfinding_t* p, unsigned x, unsigned y)
{
	unsigned i;

	unsigned size = 0, position = SECTOR_SIZE;
	sector_node_t *A = at(p->sectors, x*p->y+y,     sector_node_t);
	sector_node_t *B = 0;
	sector_node_t *C = 0;

	cost_sector_t *cA = get_cost(*p, *A);
	cost_sector_t *cB = 0;
	cost_sector_t *cC = 0;

	//HORIZONTAL
	if (x < p->x-1)
	{
		B  = at(p->sectors, (x+1)*p->y+y, sector_node_t);
		cB = get_cost(*p, *B);
	
		for (i = 0; i < SECTOR_SIZE; i++)
		{
			if (((*cA)[SECTOR_SIZE-1][i] != BLCKD_TERR) && ((*cB)[0][i] != BLCKD_TERR))
			{
				if (position == SECTOR_SIZE)
				{
					position = i;
					size = 1;
				} else
					size++;
			}
			else if (position < SECTOR_SIZE)
			{
				sector_portal_t portal;
				portal.edge  = BOTTOM;
				portal.start = position;
				portal.size  = size-1;
				portal.sideA = A;
				portal.sideB = B;

				array_add(&p->portals, &portal);

				position = SECTOR_SIZE;
				size = 0;
			}
		}
		if (position < SECTOR_SIZE)
		{
			sector_portal_t portal;
			portal.edge  = BOTTOM;
			portal.start = position;
			portal.size  = size-1;
			portal.sideA = A;
			portal.sideB = B;

			array_add(&p->portals, &portal);

			position = SECTOR_SIZE;
			size = 0;
		}
	}

	//VERTICAL
	if (y < p->y-1)
	{
		C  = at(p->sectors, x*p->y+y+1, sector_node_t);
		cC = get_cost(*p, *C);

		for (i = 0; i < SECTOR_SIZE; i++)
		{
			if (((*cA)[i][SECTOR_SIZE-1] != BLCKD_TERR) && ((*cC)[i][0] != BLCKD_TERR))
			{
				if (position == SECTOR_SIZE)
				{
					position = i;
					size = 1;
				} else
					size++;
			}
			else if (position < SECTOR_SIZE)
			{
				sector_portal_t portal;
				portal.edge  = RIGHT;
				portal.start = position;
				portal.size  = size-1;
				portal.sideA = A;
				portal.sideB = C;

				array_add(&p->portals, &portal);

				position = SECTOR_SIZE;
				size = 0;
			}
		}
		if (position < SECTOR_SIZE)
		{
			sector_portal_t portal;
			portal.edge  = RIGHT;
			portal.start = position;
			portal.size  = size-1;
			portal.sideA = A;
			portal.sideB = C;

			array_add(&p->portals, &portal);

			position = SECTOR_SIZE;
			size = 0;
		}
	}
}

void pf_update_nodes(pathfinding_t* p)
{
	//for ()
}

unsigned pf_sector_index(pathfinding_t p, unsigned x, unsigned y)
{
	unsigned i = x/SECTOR_SIZE;
	unsigned j = y/SECTOR_SIZE;

	return i*p.y + j;
}

void pf_sectorpath(pathfinding_t p, unsigned from_x, unsigned from_y, unsigned to_x, unsigned to_y)
{
	
}