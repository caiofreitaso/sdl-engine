#ifndef RENDER_H
#define RENDER_H

#include <GL/gl.h>
#include <GL/glu.h>

#include "camera.h"
#include "../game/game.h"

struct renderer {
	double   fps;
	double   deltaTime;
	unsigned frameCount;
	unsigned lastTime;
	unsigned diffTime;
};

extern struct renderer RENDERER;

void render_init();
void render_clear();
void render_camera(camera_t);
void render_update();

#endif