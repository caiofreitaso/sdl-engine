#pragma once
#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <game-engine/math/point.h>
#include <game-engine/graphics/color.h>

namespace Engine { namespace Graphics {

struct Vertex
{
	Point3 position;
	Point3 normal;
	Color color;
};

struct Face
{
	unsigned a,b,c;	
};

struct MeshGL
{
	unsigned VBO;
	unsigned EBO;
	unsigned reset;
	unsigned EBO_size;
};

struct Mesh
{
	std::vector<Vertex> VBO;
	std::vector<unsigned> EBO;
	unsigned reset;
};

}}

#endif