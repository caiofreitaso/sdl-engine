#include "../include/contiguous.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	array_t arr;

	array_init(&arr,sizeof(int));

	int i;
	for (i = 0; i < 500; i++)
		array_add(&arr, &i);

	FOR_EACH(int, v, arr)
		printf("%d\n", *v);

	printf("r: %d\n", arr.reserved);
	printf("%d %d\n", sizeof(char), sizeof(int));

	return 0;
}