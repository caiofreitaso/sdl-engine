#include "../include/trimatrix.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	trimatrix_t m;

	matrix_init(&m, 7);

	unsigned i,j;
	for (i = 0; i < m.size; i++)
		m.array[i] = i;

	for (i = 0; i < m.size; i++)
		printf("%.0f ", m.array[i]);
	printf("\n");

	matrix_del(&m, 1);

	for (i = 0; i < m.size; i++)
		printf("%.0f ", m.array[i]);
	printf("\n");

	return 0;
}