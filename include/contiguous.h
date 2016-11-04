#ifndef CONTIGUOUS
#define CONTIGUOUS

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

extern const int ARRAY_INITIAL_RESERVE;

#define as(a, t) ((t) a)
#define at(a, i, t) ((t*) array_at(a, i))
#define FOR_EACH(t, v, a) { t* v; for(v = ((t*)a.array); v != ((t*) array_at(a,a.size)); v++) {
#define END_FOR }}

typedef struct {
	size_t   increment;
	unsigned reserved;
	unsigned size;
	char*    array;
} array_t;

enum ARRAY_RETURN
{
	ARRAY_OK = 0,
	ARRAY_OUT_OF_BOUNDS = -1,
	ARRAY_UNKNOWN = -2
};

void  array_init(array_t* target, size_t type_size);
void* array_at  (array_t  target, int index);
void* array_last(array_t  target);
int   array_add (array_t* target, void const* value);
int   array_del (array_t* target, int index);
int   array_pop (array_t* target);
void  array_free(array_t  target);

void  array_shift (void* ptr, size_t element, unsigned size, unsigned start, unsigned pos);
#endif