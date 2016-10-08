#include "../include/game.h"

game_t GAME =
{
	.window = 0,
	.screen = 0,
	.context = 0,
	.settings =
	{
		.display =
		{
			.resolution =
			{
				.width = 1024,
				.height = 768
			},
			.mode = WINDOW,
			.vsync = SDL_FALSE,
			.gamma = 1.0
		},
		.controls =
		{
			.lock_mouse = SDL_FALSE
		}
	}
};

int game_init(const char* name)
{
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{
		GAME.window = create_window(GAME.settings, name);
		if( GAME.window == NULL )
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return -2;
		}
		else
		{
			GAME.screen = SDL_GetWindowSurface(GAME.window);
			GAME.context = SDL_GL_CreateContext(GAME.window);

			return 0;
		}
	}
}

void game_quit()
{
	SDL_GL_DeleteContext(GAME.context);
	SDL_DestroyWindow(GAME.window);
	SDL_Quit();
}

void game_update()
{
	static unsigned count = 0;
	
	#pragma omp sections
	{
		#pragma omp section
		{
		}

		#pragma omp section
		{

		}
	}
}