#ifndef POINT_H
#define POINT_H

typedef struct {
	float x, y;
} point2_t;

typedef struct {
	float x, y, z;
} point3_t;

unsigned eq2D    (point2_t, point2_t);
point2_t add2D   (point2_t, point2_t);
point2_t sub2D   (point2_t, point2_t);
point2_t mul2D   (point2_t, float);
point2_t div2D   (point2_t, float);
float    dot2D   (point2_t, point2_t);
float    length2D(point2_t);
float    dist2D  (point2_t, point2_t);
float    cross2D (point2_t, point2_t);

unsigned eq3D    (point3_t, point3_t);
point3_t add3D   (point3_t, point3_t);
point3_t sub3D   (point3_t, point3_t);
point3_t mul3D   (point3_t, float);
point3_t div3D   (point3_t, float);
float    dot3D   (point3_t, point3_t);
float    length3D(point3_t);
float    dist3D  (point3_t, point3_t);
float    cross3D (point3_t, point3_t);

#endif