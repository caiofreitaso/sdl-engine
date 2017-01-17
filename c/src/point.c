#include "../include/math/point.h"

const float POINT_PRECISION = 0.00001;

const point3_t origin3D = { .v = { 0, 0, 0 } };
const point2_t origin2D = { .v = { 0, 0 } };

unsigned eq2D(point2_t a, point2_t b)
{
	return (a.x-b.x)+(a.y-b.y) < POINT_PRECISION;
}

point2_t add2D(point2_t a, point2_t b)
{
	a.x += b.x;
	a.y += b.y;
	return a;
}

point2_t sub2D(point2_t a, point2_t b)
{
	a.x -= b.x;
	a.y -= b.y;
	return a;
}

point2_t mul2D(point2_t a, float b)
{
	a.x *= b;
	a.y *= b;
	return a;
}

point2_t div2D(point2_t a, float b)
{
	a.x /= b;
	a.y /= b;
	return a;
}

float dot2D(point2_t a, point2_t b)
{
	return a.x*b.x + a.y*b.y;
}

float length2D(point2_t a)
{
	return sqrt(a.x*a.x + a.y*a.y);
}

float dist2D(point2_t a, point2_t b)
{
	float x = a.x-b.x;
	float y = a.y-b.y;
	return sqrt(x*x+y*y);
}

unsigned eq3D(point3_t a, point3_t b)
{
	return (a.x-b.x)+(a.y-b.y)+(a.z-b.z) < POINT_PRECISION;
}

point3_t add3D(point3_t a, point3_t b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return a;
}

point3_t sub3D(point3_t a, point3_t b)
{
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

point3_t mul3D(point3_t a, float b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return a;
}

point3_t div3D(point3_t a, float b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	return a;
}

float dot3D(point3_t a, point3_t b)
{
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}

float length3D(point3_t a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

float dist3D(point3_t a, point3_t b)
{
	float x = a.x-b.x;
	float y = a.y-b.y;
	float z = a.z-b.z;
	return sqrt(x*x+y*y+z*z);
}

point3_t cross3D(point3_t a, point3_t b)
{
	point3_t r;
	r.x = a.y*b.z - a.z*b.y;
	r.y = a.z*b.x - a.x*b.z;
	r.z = a.x*b.y - a.y*b.x;
	return r;
}

point2_t normalize2D(point2_t a)
{
	return div2D(a,length2D(a));
}
point3_t normalize3D(point3_t a)
{
	return div3D(a,length3D(a));
}


point3_t normal3D(point3_t a, point3_t b, point3_t c)
{
	point3_t r = cross3D(sub3D(b,a),sub3D(c,a));
	r = normalize3D(r);
	return r;
}

float area3D(point3_t a, point3_t b, point3_t c)
{
	return 0.5*length3D(cross3D(sub3D(a,b),sub3D(a,c)));
}

point4_t homogeneous(point3_t p)
{
	point4_t r;
	r.v[0] = p.v[0];
	r.v[1] = p.v[1];
	r.v[2] = p.v[2];
	r.v[3] = 1.0;
}
