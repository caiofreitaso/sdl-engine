#include "../include/settings.h"

void settings_load(const char* filename, settings_t* s)
{
	
}

SDL_Window* create_window(settings_t settings, const char* name)
{
	return SDL_CreateWindow(name,
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		settings.display.resolution.width, settings.display.resolution.height,
		settings.display.mode);
}