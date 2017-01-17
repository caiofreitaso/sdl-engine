#include "../include/point.h"
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void diff(float* a, float* b, float* c, int size)
{
	int i;
	for (i = 0; i < size; i++)
		a[i] = b[i] - c[i];
}

void set(float* a, int size, float value)
{
	int i;
	for (i = 0; i < size; i++)
		a[i] = value;
}

int main(int argc, char const *argv[])
{
	point3_t *points, *targets, *result;

	points  = (point3_t*) malloc(800 * sizeof(point3_t));
	targets = (point3_t*) malloc(800 * sizeof(point3_t));
	result  = (point3_t*) malloc(800 * sizeof(point3_t));

	set((float*)targets,2400,2);
	set((float*)points, 2400,0);

	diff((float*)result,(float*)targets,(float*)points,2400);


	return 0;
}