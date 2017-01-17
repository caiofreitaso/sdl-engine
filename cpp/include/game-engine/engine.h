#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <game-engine/graphics/render.h>
#include <game-engine/graphics/scene.h>
#include <omp.h>

namespace Engine {
	void setScene(Graphics::Scene*);
	void quitScene();

	void loop();
	void loopOMP();

	namespace IO {
		void update(std::function<void(State const&, SDL_Event)>);
		void inputLoop();
	}

	namespace Graphics {
		void renderLoop();
	}
}

#endif