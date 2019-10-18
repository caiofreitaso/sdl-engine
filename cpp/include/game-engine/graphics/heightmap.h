#ifndef GAMEENGINE_GRAPHICS_HEIGHTMAP_H_
#define GAMEENGINE_GRAPHICS_HEIGHTMAP_H_

#include <vector>

#include <game-engine/core/map.h>
#include <game-engine/graphics/mesh.h>

namespace GameEngine {
namespace Graphics {
struct HeightMap {
  unsigned reset_index;
  std::vector<Vertex> vertices;
  std::vector<unsigned> indices;

  HeightMap(Map const&);

  static constexpr float HEIGHT_SCALE = 0.03125;
  static Color from_terrain(Terrain);

private:
  void set_vertices(Map const&);
  void set_indices(Map const&);
  void set_normals(Map const&);
};
}
}

#endif
