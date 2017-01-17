#ifndef SPARSEH
#define SPARSEH

#include "../util/contiguous.h"

//Sparse SYMMETRIC Matrix
//Stores only the upper triangular matrix
//Useful for non-directed graphs

typedef struct {
	float    *values;
	unsigned *indices;
	unsigned *columns;
	unsigned  side;
	unsigned  size;
	unsigned  reserved;
} sparse_t;

enum SPARSE_RETURN
{
	SPARSE_OK,
	SPARSE_OUT_OF_BOUNDS = -1,
	SPARSE_UNKNOWN = -2
};

void  sparse_init(sparse_t*, unsigned side);
int   sparse_set (sparse_t*, unsigned i, unsigned j, float value);
float sparse_at  (sparse_t,  unsigned i, unsigned j);
int   sparse_del (sparse_t*, unsigned j);
void  sparse_free(sparse_t);

int   sparse_comp(const void *k, const void *e);

#endif