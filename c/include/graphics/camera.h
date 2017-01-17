#ifndef CAMERA_H
#define CAMERA_H

#include "../math/point.h"

typedef struct {
	char perspective;
	union {
		struct {
			float    v_fov;
			point3_t position;
			point3_t target;
			point3_t up;
		};
		struct {
			float left;
			float right;
			float top;
			float bottom;
		};
	};
	float near;
	float far;
} camera_t;

extern const camera_t DEFAULT_CAMERA;

#endif