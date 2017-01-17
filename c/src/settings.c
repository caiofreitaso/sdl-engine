#include "../include/game/settings.h"

void settings_load(const char* filename, settings_t* s)
{
	
}

resolution_t window_size(SDL_Window* window)
{
	resolution_t ret;
	SDL_GetWindowSize(window, &ret.width, &ret.height);
	return ret;
}

SDL_Window* create_window(settings_t settings, const char* name)
{
	return SDL_CreateWindow(name,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		settings.video.size.width, settings.video.size.height,
		settings.video.mode);
}