#ifndef LIGHT_H
#define LIGHT_H

#include "render.h"

typedef struct {
	color_t  ambient;
	color_t  diffuse;
	color_t  specular;
	point4_t position;
	struct {
		point3_t direction;
		float    exponent;
		float    cutoff;
	} spot;
	float attenuation_const;
	float attenuation_linear;
	float attenuation_quad;
} light_t;

extern const light_t DEFAULT_LIGHT;

void light_set(light_t, unsigned);

#endif