#ifndef SPARSEH
#define SPARSEH

//Sparse TRIANGULAR Matrix

typedef struct {
	float    *values;
	unsigned *indices;
	unsigned *columns;
	unsigned  size;
	unsigned  side;
} sparse_t;

void  sparse_init(sparse_t*, unsigned side);
void  sparse_set (sparse_t*, unsigned i, unsigned j, float value);
float sparse_at  (sparse_t,  unsigned i, unsigned j);
void  sparse_del (sparse_t*, unsigned j);
void  sparse_free(sparse_t);

#endif