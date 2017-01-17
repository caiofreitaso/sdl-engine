#pragma once
#ifndef STATE_H
#define STATE_H

#include <SDL.h>
#include <functional>
#include <iostream>

#include <game-engine/settings.h>

namespace Engine {
	void startScene();
	void endScene();

	bool isSceneFinished();
	bool isGameFinished();

	void quit();

	namespace IO {
		struct State
		{
			int mouse_x;
			int mouse_y;
			int scroll;
			unsigned scroll_time;
			unsigned char clicks;
			unsigned char mouse[3];
			unsigned short mod;
			unsigned char keys[314];
		};

		struct Resolution { int width, height; };

		int initSDL(const char*);
		
		State const& state();

		Resolution windowSize();
		float windowRatio();
		void swapWindow();
		
		void handleEvent(SDL_Event);
		void update(std::function<void(State const&, SDL_Event)>);

		void inputLoop();
	}
}

#endif
