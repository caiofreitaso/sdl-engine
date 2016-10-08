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
	GLuint  r_index;  //reset index

	array_t vertices; //vertex coords
	array_t indices;  //vertex index for triangles

	float  *areas;    //areas for all faces
} heightmap_t;

void heightmap_init(heightmap_t*, map_t);
void heightmap_free(heightmap_t);

void heightmap_set_vert(heightmap_t*, map_t);
void heightmap_set_idx (heightmap_t*, map_t);

struct face_ext {
	point3_t *normals;
	float    *areas;
};

struct face_ext heightmap_faces(heightmap_t*, unsigned);
void heightmap_normals(heightmap_t*, map_t, point3_t*, unsigned);

point3_t face_normal(heightmap_t, face_t);
float    face_area  (heightmap_t, face_t);

#endif