#ifndef GAME_H
#define GAME_H

#include "contiguous.h"
#include "settings.h"
#include <stdio.h>
#include <omp.h>

typedef struct {
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_GLContext context;

	settings_t settings;
} game_t;

extern game_t GAME;

int  game_init(const char*);
void game_quit();

void game_update();

#endif