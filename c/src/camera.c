#include "../include/graphics/camera.h"

const camera_t DEFAULT_CAMERA =
{
	.perspective = 1,
	.v_fov  = 110.0,
	.position.v = { 8,0,15 },
	.target.v   = { 8,8,0 },
	.up.v       = { 0,0,1 },
	.near = 1.0,
	.far  = 10000.0
};
