#ifndef HEIGHTMAP_H
#define HEIGHTMAP_H

#include "../world/map.h"
#include "../vertex.h"
#include "../scene/scene.h"
#include "render.h"
#include <stddef.h>
#include <GL/gl.h>

extern const float HEIGHT_SCALE;

typedef struct {
	GLuint r_index;

	array_t vertices; //vertex coords
	array_t indices;  //vertex index for triangles
} heightmap_t;

float* heightmap_init(heightmap_t*, map_t);
point3_t face_normal(heightmap_t, face_t);
float    face_area  (heightmap_t, face_t);

#endif