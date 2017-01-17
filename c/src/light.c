#include "../include/graphics/light.h"

const light_t DEFAULT_LIGHT =
{
	.ambient = { .v = { 1, 1, 1, 1 } },
	.diffuse = { .v = { 1, 1, 1, 1 } },
	.specular = { .v = { 1, 1, 1, 1 } },

	.position = { .v = { 3, 3, 20 } },

	.spot =
	{
		.direction = { .v = { 0, 0, 0 } },
		.exponent = 0,
		.cutoff = 0
	},

	.attenuation_const  = 1,
	.attenuation_linear = 0,
	.attenuation_quad   = 1,
};

void light_set(light_t l, unsigned number)
{
	unsigned light = GL_LIGHT0 + number;
	glEnable(GL_LIGHTING);
	glEnable(light);

	glLightfv(light, GL_AMBIENT,  l.ambient.v);
	glLightfv(light, GL_DIFFUSE,  l.diffuse.v);
	glLightfv(light, GL_SPECULAR, l.specular.v);
	glLightfv(light, GL_POSITION, l.position.v);

	glLightf(light, GL_CONSTANT_ATTENUATION,  l.attenuation_const);
	glLightf(light, GL_LINEAR_ATTENUATION,    l.attenuation_linear);
	glLightf(light, GL_QUADRATIC_ATTENUATION, l.attenuation_quad);
}