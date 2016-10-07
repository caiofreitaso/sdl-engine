#include "../include/contiguous.h"

const int ARRAY_INITIAL_RESERVE = 16;

void array_init(array_t* target, size_t type_size)
{
	target->increment = type_size;
	target->reserved  = ARRAY_INITIAL_RESERVE;
	target->size      = 0;
	target->array     = malloc(type_size * ARRAY_INITIAL_RESERVE);
}

void* array_at(array_t target, int index)
{
	return &target.array[index * target.increment];
}

int array_add(array_t* target, void const* value)
{
	if (target->reserved == target->size)
	{
		
		void* new_array = realloc(target->array, target->reserved * target->increment * 2);
		
		if (new_array == NULL)
			return ARRAY_UNKNOWN;
		else
		{
			target->reserved <<= 1;
			target->array = new_array;
			memcpy(array_at(*target, target->size), value, target->increment);
			target->size++;

			return ARRAY_OK;
		}
	}
	else
	{
		memcpy(array_at(*target, target->size), value, target->increment);
		target->size++;

		return ARRAY_OK;
	}
}

int array_del(array_t* target, int index)
{
	if (index >= target->size)
		return ARRAY_OUT_OF_BOUNDS;

	target->size--;

	unsigned i;
	for (i = index; i < target->size; i++)
		target->array[i] = target->array[i+1];
}

void array_free(array_t* target)
{
	free(target->array);
}