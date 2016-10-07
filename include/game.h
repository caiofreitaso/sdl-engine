#ifndef GAME_H
#define GAME_H

#include "contiguous.h"
#include "settings.h"
#include <stdio.h>

struct game_t;

typedef void (*game_upd)(struct game_t);

typedef struct game_t {
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_GLContext context;

	settings_t settings;

	game_upd update;
} Game;

int  game_init(const char*, Game*);
void game_quit(Game*);

#endif