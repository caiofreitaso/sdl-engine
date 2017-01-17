#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <GL/gl.h>
#include <SDL.h>
#include <vector>
#include <functional>
#include <game-engine/graphics/camera.h>
#include <game-engine/graphics/vertex.h>
#include <game-engine/core/container.h>

namespace Engine {
	namespace IO { struct State; }
	namespace Graphics {
		struct Scene
		{
			unsigned VAO;
			std::vector<MeshGL> objects;

			Camera camera;
			std::function<void(IO::State const&, SDL_Event)> handler;
			std::function<void(IO::State const&)> update;

			Scene();
			Scene(Camera);
			Scene(Camera, std::function<void(IO::State const&, SDL_Event)>);
			Scene(Camera, std::function<void(IO::State const&, SDL_Event)>, std::function<void(IO::State const&)>);
			~Scene();

			void attach(Mesh);
			void dettach(size_t);

			static void nop_handler(IO::State const&, SDL_Event) { }
			static void nop_update(IO::State const&) { }
		};
	}
}

#endif