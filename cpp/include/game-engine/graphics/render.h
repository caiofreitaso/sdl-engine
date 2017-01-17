#pragma once
#ifndef RENDER_H
#define RENDER_H

#include <GL/glu.h>
#include <vector>
#include <game-engine/graphics/camera.h>
#include <game-engine/graphics/vertex.h>
#include <game-engine/io/state.h>

namespace Engine { namespace Graphics {
	double fps();
	double dTime();
	unsigned frameCount();
	unsigned time();
	unsigned diff();

	void initGL();
	void clear();
	void camera(Camera);
	void render(Camera, unsigned, std::vector<MeshGL> const&);
	void update();
}}

#endif