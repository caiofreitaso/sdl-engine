#ifndef RENDER_H
#define RENDER_H

#ifdef _WIN32
  #include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glu.h>

#include "../point.h"
#include "../game.h"

typedef struct {
	char perspective;
	union {
		struct {
			float    fov;
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


struct renderer {
	float fps;
	float deltaTime;
	unsigned frameCount;
	unsigned lastTime;
};

extern const color_t COLOR_CLIFF;
extern const color_t COLOR_DEEP_WATER;
extern const color_t COLOR_WATER;
extern const color_t COLOR_SWAMP;
extern const color_t COLOR_SOFT_SAND;
extern const color_t COLOR_DENSE_BUSHES;
extern const color_t COLOR_TALL_GRASS;
extern const color_t COLOR_HARD_SAND;
extern const color_t COLOR_GRASS;

extern const color_t LIGHT_GRAY;
extern const color_t LIGHT_RED;
extern const color_t LIGHT_GREEN;
extern const color_t LIGHT_BLUE;
extern const color_t LIGHT_CYAN;
extern const color_t LIGHT_MAGENTA;
extern const color_t LIGHT_YELLOW;

extern const color_t WHITE;
extern const color_t GRAY;
extern const color_t BLACK;
extern const color_t RED;
extern const color_t GREEN;
extern const color_t BLUE;
extern const color_t CYAN;
extern const color_t MAGENTA;
extern const color_t YELLOW;

extern const camera_t DEFAULT_CAMERA;

extern struct renderer RENDERER;

void     render_init();
void     render_clear();
void     render_camera(camera_t);
unsigned render_diff();

#endif