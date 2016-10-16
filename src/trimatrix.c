#include "../include/trimatrix.h"

unsigned matrix_size(unsigned side)
{
	return (side*side + side)/2;
}

void matrix_init(trimatrix_t* target, unsigned side)
{
	target->side  = side;
	target->size  = matrix_size(side);
	target->array = calloc(target->size, sizeof(float));
}

float* matrix_at (trimatrix_t target, unsigned i, unsigned j)
{
	if (i > j)
	{
		unsigned k = j;
		j = i;
		i = k;
	}

	//row-based matrix
	//return &target.array[i*target.side - (i*i-i)/2 + j];

	//column-based
	return &target.array[matrix_size(j) + i];
}

int matrix_copy(trimatrix_t receiver, trimatrix_t giver)
{
	if (receiver.side < giver.side)
		return MATRIX_SMALLER_COPY;

	unsigned smaller = receiver.size < giver.size ? receiver.size : giver.size;

	memcpy(receiver.array, giver.array, smaller);

	return MATRIX_OK;
}

int matrix_del(trimatrix_t* target, unsigned j)
{
	if (j >= target->side)
		return MATRIX_OUT_OF_BOUNDS;

	unsigned i,k;
	unsigned offset   = matrix_size(j);
	unsigned elements = j+1;

	for (i = offset+elements; i < target->size; i++)
		target->array[i-elements] = target->array[i];

	target->size -= elements;

	for (i = j+1; i < target->side; i++)
	{
		offset += i-j-1;
		for (k = offset; k < target->size; k++)
			target->array[k] = target->array[k+1];
		offset += elements;

		target->size--;
	}

	target->side--;
}

void matrix_free(trimatrix_t target)
{
	free(target.array);
}
