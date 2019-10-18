#ifndef GAMEENGINE_GRAPHICS_MESH_H_
#define GAMEENGINE_GRAPHICS_MESH_H_

#include <game-engine/math/point.h>
#include <game-engine/graphics/color.h>

namespace GameEngine {
namespace Graphics {
struct Vertex {
  Point3f position;
  Point3f normal;
  Color color;
};

struct Face { unsigned a, b, c; };

struct Mesh {
  unsigned VBO;
  unsigned EBO;
  unsigned reset;
  unsigned EBO_size;
};
}
}

#endif
