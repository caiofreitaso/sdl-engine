#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL.h>

typedef struct {
	int width;
	int height;
} resolution_t;

typedef enum {
	FULLSCREEN = SDL_WINDOW_FULLSCREEN_DESKTOP,
	WINDOW     = SDL_WINDOW_OPENGL,
	BORDERLESS = SDL_WINDOW_BORDERLESS
} window_e;

typedef struct {
	resolution_t resolution;
	window_e     mode;
	SDL_bool     vsync;
	float        gamma;
} video_settings_t;

typedef struct {
	SDL_bool lock_mouse;
	float    cam_speed;
	float    cam_scroll;
	float    cam_drag;
} control_settings_t;

typedef struct {
	video_settings_t   display;
	control_settings_t controls;
	unsigned event_delay;
	unsigned render_delay;
} settings_t;


void settings_load(const char*, settings_t*);

SDL_Window* create_window(settings_t, const char*);

#endif