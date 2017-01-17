#include "../include/unit/unit.h"

void units_update(units_t *u)
{
	unsigned i;

	#pragma omp parallel for simd
	for (i = 0; i < u->size; i++)
	{
		
	}
}