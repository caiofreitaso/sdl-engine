#include "../include/graphics/render.h"

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
	glClearColor(0,0,0,0.8);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void render_clear()
{
	resolution_t window = game_window();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, window.width, window.height);
}

void render_camera(camera_t cam)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (cam.perspective)
	{
		resolution_t window = game_window();

		float ratio = ((float) window.width)/window.height;
		float fov   = (360/3.14159265) * atan(tan(cam.v_fov*3.14159265/180) * ratio);

		gluPerspective(fov, ratio, cam.near, cam.far);
		gluLookAt(cam.position.x, cam.position.y, cam.position.z,
				  cam.target.x  , cam.target.y  , cam.target.z,
				  cam.up.x      , cam.up.y      , cam.up.z);
	} else
		glOrtho(cam.left, cam.right, cam.bottom, cam.top, cam.near, cam.far);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void render_update()
{
	unsigned actual = SDL_GetTicks();

	RENDERER.diffTime  = actual - RENDERER.lastTime;
	RENDERER.deltaTime = ((double)(RENDERER.diffTime))/1000.0;
	RENDERER.fps       = 1/RENDERER.deltaTime;
	RENDERER.lastTime  = actual;
	RENDERER.frameCount++;
}