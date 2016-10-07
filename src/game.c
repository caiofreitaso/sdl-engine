#include "../include/game.h"

int game_init(const char* name, Game* g)
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{
		g->window = create_window(g->settings, name);
		if( g->window == NULL )
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -2;
		}
		else
		{
			g->screen = SDL_GetWindowSurface(g->window);
			g->context = SDL_GL_CreateContext(g->window);

			return 0;
		}
	}
}

void game_quit(Game* g)
{
	SDL_GL_DeleteContext(g->context);
	SDL_DestroyWindow(g->window);
	SDL_Quit();
}