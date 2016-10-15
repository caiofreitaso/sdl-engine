#ifndef TRIMATRIX
#define TRIMATRIX

#include <stdlib.h>
#include <stddef.h>

typedef struct {
	float    *array;
	unsigned  side;
	unsigned  size;
} trimatrix_t;

enum MATRIX_RETURN
{
	MATRIX_OK,
	MATRIX_OUT_OF_BOUNDS = -1,
	MATRIX_SMALLER_COPY = -2
};

void     matrix_init(trimatrix_t* target, unsigned side);
float*   matrix_at  (trimatrix_t  target, unsigned i, unsigned j);
int      matrix_copy(trimatrix_t  receiver, trimatrix_t giver);
void     matrix_free(trimatrix_t  target);
unsigned matrix_size(unsigned side);

#endif