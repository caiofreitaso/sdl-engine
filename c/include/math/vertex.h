#ifndef VERTEX_H
#define VERTEX_H

#include "point.h"

typedef struct {
	point3_t position;
	point3_t normal;
	color_t  color;
} vertex_t;

typedef struct {
	unsigned a;
	unsigned b;
	unsigned c;
} face_t;

typedef struct {
	unsigned VBO;
	unsigned EBO;
	unsigned reset;
	unsigned EBO_size;
} mesh_t;

#endif