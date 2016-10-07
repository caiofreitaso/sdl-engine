#ifndef POINT_H
#define POINT_H

#include <math.h>

typedef union {
	float v[2];
	struct {
		float x, y;
	};
} point2_t;

typedef union {
	float v[3];
	struct {
		float x, y, z;
	};
} point3_t;

typedef union {
	float v[4];
	struct {
		float x, y, z, w;
	};
} point4_t;

typedef union
{
	float v[4];
	struct {
		float r,g,b,a;
	};
} color_t;

extern const float POINT_PRECISION;
extern const point3_t origin3D;
extern const point2_t origin2D;

unsigned eq2D    (point2_t, point2_t);
point2_t add2D   (point2_t, point2_t);
point2_t sub2D   (point2_t, point2_t);
point2_t mul2D   (point2_t, float);
point2_t div2D   (point2_t, float);
float    dot2D   (point2_t, point2_t);
float    length2D(point2_t);
float    dist2D  (point2_t, point2_t);

unsigned eq3D    (point3_t, point3_t);
point3_t add3D   (point3_t, point3_t);
point3_t sub3D   (point3_t, point3_t);
point3_t mul3D   (point3_t, float);
point3_t div3D   (point3_t, float);
float    dot3D   (point3_t, point3_t);
float    length3D(point3_t);
float    dist3D  (point3_t, point3_t);
point3_t cross3D (point3_t, point3_t);

point2_t normalize2D(point2_t);
point3_t normalize3D(point3_t);

point3_t normal3D(point3_t, point3_t, point3_t);
float    area3D  (point3_t, point3_t, point3_t);

point4_t homogeneous(point3_t);

#endif