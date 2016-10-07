#ifndef SETTINGS_H
#define SETTINGS_H

#include <SDL.h>

typedef struct {
	int width;
	int height;
} resolution_t;

typedef enum {
	FULLSCREEN = SDL_WINDOW_FULLSCREEN_DESKTOP,
	WINDOW = SDL_WINDOW_OPENGL,
	BORDERLESS_WINDOW = SDL_WINDOW_BORDERLESS
} window_t;

typedef struct {
	resolution_t resolution;
	window_t mode;
	SDL_bool vsync;
	float gamma;
} video_settings_t;

typedef struct {
	SDL_bool lock_mouse;
} control_settings_t;

typedef struct {
	video_settings_t display;
	control_settings_t controls;
} settings_t;


void settings_load(const char*, settings_t*);

SDL_Window* create_window(settings_t, const char*);

#endif