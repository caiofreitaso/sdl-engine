#include "../include/math/sparse.h"

int sparse_comp(const void *k, const void *e)
{
	if (*(unsigned*)k <  *(unsigned*)e) return -1;
	if (*(unsigned*)k == *(unsigned*)e) return  0;
	if (*(unsigned*)k >  *(unsigned*)e) return  1;
}

void sparse_init(sparse_t* target, unsigned side)
{
	target->side     = side;
	target->size     = 0;
	target->reserved = ARRAY_INITIAL_RESERVE;
	target->indices  = (unsigned*) calloc(ARRAY_INITIAL_RESERVE, sizeof(unsigned));
	target->values   = (float*)    calloc(ARRAY_INITIAL_RESERVE, sizeof(float));
	target->columns  = (unsigned*) calloc(side, sizeof(unsigned));
}

int sparse_set(sparse_t* target, unsigned i, unsigned j, float value)
{
	if (i > target->side || j > target->side)
		return SPARSE_OUT_OF_BOUNDS;

	unsigned k;
	if (i > j)
	{
		k = j;
		j = i;
		i = k;
	}

	unsigned *begin = &target->indices[target->columns[j]];
	unsigned *end   = &target->indices[target->size];

	if (j < target->side-1)
		end = &target->indices[target->columns[j+1]];

	//if there is already a non-zero value for this element
	if (begin = bsearch(&i, begin, end-begin, sizeof(unsigned), sparse_comp))
	{
		//remove value and index if new value is zero
		if (value == 0)
		{
			unsigned index = begin - target->indices;
			
			memmove(begin, begin+1, target->size - index - 1);
			memmove(&target->values[index], &target->values[index+1], target->size - index - 1);

			target->size--;

			return SPARSE_OK;
		}
		else
			target->values[begin-target->indices] = value;
		return SPARSE_OK;
	}

	//do nothing if new value is zero, else
	if (value != 0)
	{
		begin = &target->indices[target->columns[j]];

		//go to the value's biggest neighbor
		for (; begin != end && *begin < i; begin++)
			;

		unsigned index = begin - target->indices;

		//if there is no more space in the arrays, realloc
		if (target->reserved == target->size)
		{
			unsigned  size  = target->reserved * 2;
			float    *new_f = (float*)    realloc(target->values,  sizeof(float)    * size);
			unsigned *new_i = (unsigned*) realloc(target->indices, sizeof(unsigned) * size);

			if (new_f == NULL || new_i == NULL)
				return SPARSE_UNKNOWN;

			target->values   = new_f;
			target->indices  = new_i;
			target->reserved = size;
		}
		
		//shift all arrays one position to the right
		if (target->size)
		{
			memmove(&target->values [index+1], &target->values [index], target->size-index);
			memmove(&target->indices[index+1], &target->indices[index], target->size-index);
		}

		//put the new values in the correct position
		target->values [index] = value;
		target->indices[index] = i;
		
		//update column start indices
		unsigned next_start = j < target->side-1 ? target->columns[j+1] : target->size;
		
		if (target->columns[j] == next_start)
			target->columns[j] = index;

		for (k = j+1; k < target->side; k++)
			target->columns[k]++;

		target->size++;
	}

	return SPARSE_OK;
}

float sparse_at(sparse_t target, unsigned i, unsigned j)
{
	if (i > j)
	{
		unsigned k = j;
		j = i;
		i = k;
	}

	unsigned *begin = &target.indices[target.columns[j]];
	unsigned *end   = &target.indices[target.size];

	if (j < target.side-1)
		end = &target.indices[target.columns[j+1]];

	//search for the index inside the j-th column
	if (begin = bsearch(&i, begin, begin-end, sizeof(unsigned), sparse_comp))
		return target.values[begin-target.columns];
	return 0;
}

int sparse_del(sparse_t* target, unsigned j)
{
	if (j > target->side)
		return SPARSE_OUT_OF_BOUNDS;

	unsigned i, k;
	unsigned *begin, *end;

	//shift values from columns of index greater than j
	for (i = target->side-1; i > j; i--)
	{
		begin = &target->indices[target->columns[i]];
		end   = &target->indices[target->size];

		if (i < target->side-1)
			end = &target->indices[target->columns[i+1]];

		//if there is a 'j' referenced
		if (begin = bsearch(&j, begin, end-begin, sizeof(unsigned), sparse_comp))
		{
			unsigned start_pos = begin - target->indices;

			array_shift(target->indices,sizeof(unsigned),target->size,start_pos,1);
			array_shift(target->values, sizeof(float),   target->size,start_pos,1);

			target->size--;

			if (start_pos == target->columns[i])
				k = i;
			else
				k = i+1;
			for(; k < target->side; k++)
				target->columns[k]--;
		}
	}

	//then delete and shift the values of the column j
	begin = &target->indices[target->columns[j]];
	end   = &target->indices[target->size];

	if (j < target->side-1)
		end = &target->indices[target->columns[j+1]];

	//if there are elements aij, where i <= j
	if (begin != end)
	{
		unsigned size      = end - begin;
		unsigned start_pos = begin - target->indices;
		array_shift(target->indices,sizeof(unsigned),target->size,start_pos,size);
		array_shift(target->values, sizeof(float),   target->size,start_pos,size);

		target->size -= size;
		
		for(k = i+1; k < target->side; k++)
			target->columns[k] -= size;
	}

	array_shift(target->columns, sizeof(unsigned), target->side, j, 1);
	target->side--;

	for (i = 0; i < target->size; i++)
		if (target->indices[i] > j)
			target->indices[i]--;

	return SPARSE_OK;
}

void sparse_free(sparse_t target)
{
	free(target.columns);
	free(target.indices);
	free(target.values);
}
