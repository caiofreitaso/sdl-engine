#include "../include/sparse.h"

void sparse_init(sparse_t* target, unsigned side)
{
	target->size = 0;
	target->indices = 0;
	target->values = 0;

	target->columns = (unsigned*) calloc(side, sizeof(unsigned));

	target->side = side;
}

void sparse_set(sparse_t* target, unsigned i, unsigned j, float value)
{
	if (i > j)
	{
		unsigned k = j;
		j = i;
		i = k;
	}

	unsigned k;
	for (k = 0;)
}

float sparse_at(sparse_t target, unsigned i, unsigned j)
{
	if (i > j)
	{
		unsigned k = j;
		j = i;
		i = k;
	}

	unsigned *column = &target.indices[target.columns[j]];
	unsigned *end = &target.indices[target.size];

	if (j < side-1)
		end = &target.indices[target.columns[j+1]];

	for (; column != end; column++)
		if (*column == i)
			return target.values[column-target.columns];
	return 0;
}

void sparse_del(sparse_t* target, unsigned j)
{

}

void sparse_free(sparse_t target)
{

}
