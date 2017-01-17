#ifndef GAME_H
#define GAME_H

#include "settings.h"
#include <stdio.h>

typedef struct {
	SDL_Window    *window;
	SDL_Surface   *screen;
	SDL_GLContext context;

	SDL_bool quit;

	settings_t settings;
} game_t;

extern game_t GAME;

int  game_init(const char*);
void game_quit();
void game_update();

resolution_t game_window();


#endif