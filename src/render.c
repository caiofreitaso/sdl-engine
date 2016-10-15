#include "../include/render/render.h"

const color_t COLOR_DEEP_WATER   = { .v = {.05,.19,.34} };
const color_t COLOR_WATER        = { .v = {.39,.77,.84} };
const color_t COLOR_SOFT_SAND    = { .v = {.98,1.0,.78} };
const color_t COLOR_HARD_SAND    = { .v = {.89,.72,.46} };
const color_t COLOR_CLIFF        = { .v = {.44,.49,.49} };
const color_t COLOR_GRASS        = { .v = {.11,.62,0.0} };
const color_t COLOR_DENSE_BUSHES = { .v = {.15,.12,.02} };
const color_t COLOR_SWAMP        = { .v = {.30,.47,.24} };
const color_t COLOR_TALL_GRASS   = { .v = {.09,.30,.03} };


const color_t LIGHT_GRAY    = { .v = {.8,.8,.8,1} };
const color_t LIGHT_RED     = { .v = { 1,.8,.8,1} };
const color_t LIGHT_GREEN   = { .v = {.8, 1,.8,1} };
const color_t LIGHT_BLUE    = { .v = {.8,.8, 1,1} };
const color_t LIGHT_CYAN    = { .v = {.8, 1, 1,1} };
const color_t LIGHT_MAGENTA = { .v = { 1,.8, 1,1} };
const color_t LIGHT_YELLOW  = { .v = { 1, 1,.8,1} };

const color_t BLACK   = { .v = {0,0,0,1} };
const color_t GRAY    = { .v = {.5,.5,.5,1} };
const color_t WHITE   = { .v = {1,1,1,1} };
const color_t RED     = { .v = {1,0,0,1} };
const color_t GREEN   = { .v = {0,1,0,1} };
const color_t BLUE    = { .v = {0,0,1,1} };
const color_t CYAN    = { .v = {0,1,1,1} };
const color_t MAGENTA = { .v = {1,0,1,1} };
const color_t YELLOW  = { .v = {1,1,0,1} };

const camera_t DEFAULT_CAMERA =
{
	.perspective = 1,
	.fov  = 110.0,
	.position.v = { 8,0,15 },
	.target.v   = { 8,8,0 },
	.up.v       = { 0,0,1 },
	.near = 1.0,
	.far  = 1000.0
};

struct renderer RENDERER =
{
	.fps = 0.0,
	.deltaTime = 0,
	.frameCount = 0,
	.lastTime = 0
};

void render_init()
{
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0,0,0,0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void render_clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void render_camera(camera_t cam)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (cam.perspective)
	{
		int w,h;
		SDL_GetWindowSize(GAME.window, &w,&h);

		float ratio = ((float) w)/h;

		gluPerspective(cam.fov, ratio, cam.near, cam.far);
		gluLookAt(cam.position.x, cam.position.y, cam.position.z,
				  cam.target.x  , cam.target.y  , cam.target.z,
				  cam.up.x      , cam.up.y      , cam.up.z);
	} else
		glOrtho(cam.left, cam.right, cam.bottom, cam.top, cam.near, cam.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(35.264f, 1.0f, 0.0f, 0.0f);
	//glRotatef(-45.0f, 0.0f, 1.0f, 0.0f);
}

unsigned render_diff()
{
	static unsigned delay = 0;
	unsigned actual = SDL_GetTicks();
	unsigned diff = actual - RENDERER.lastTime;
	RENDERER.frameCount++;
	if (diff)
	{
		RENDERER.deltaTime = ((float)(diff))/1000.0;
		RENDERER.fps = delay ? delay/RENDERER.deltaTime : 1/RENDERER.deltaTime;
		RENDERER.lastTime = actual;
		delay = 0;
	} else
		delay++;
	return diff;
}