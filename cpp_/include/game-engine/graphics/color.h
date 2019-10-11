#pragma once
#ifndef COLOR_H
#define COLOR_H

namespace Engine { namespace Graphics {

union Color
{
	float v[4];
	struct { float r,g,b,a; };
};

extern const Color COLOR_CLIFF;
extern const Color COLOR_DEEP_WATER;
extern const Color COLOR_WATER;
extern const Color COLOR_SWAMP;
extern const Color COLOR_SOFT_SAND;
extern const Color COLOR_DENSE_BUSHES;
extern const Color COLOR_TALL_GRASS;
extern const Color COLOR_HARD_SAND;
extern const Color COLOR_GRASS;

}}

#endif