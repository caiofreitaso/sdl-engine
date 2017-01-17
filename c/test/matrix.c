#include "../include/trimatrix.h"
#include "../include/sparse.h"
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

////////

	unsigned x[10];
	for (i = 0; i < 10; i++)
		x[i] = i;

	array_shift(x,sizeof(unsigned),10,3,1);

	sparse_t s;
	sparse_init(&s, 7);

	float k = 0;
	for (j = 0; j < 7; j++)
		for (i = 0; i <= j; i++, k++)
			sparse_set(&s, i, j, k);
	
	for (i = 0; i < s.size; i++)
		printf("%.0f ", s.values[i]);
	printf("\n");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.indices[i]);
	printf("\n");
	for (i = 0; i < s.side; i++)
		printf("%d ", s.columns[i]);
	printf("\n");

	sparse_del(&s, 1);

	for (i = 0; i < s.size; i++)
		printf("%.0f ", s.values[i]);
	printf("\n");
	for (i = 0; i < s.size; i++)
		printf("%d ", s.indices[i]);
	printf("\n");
	for (i = 0; i < s.side; i++)
		printf("%d ", s.columns[i]);
	printf("\n");

	return 0;
}