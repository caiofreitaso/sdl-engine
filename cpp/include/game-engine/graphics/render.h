#ifndef GAMEENGINE_GRAPHICS_RENDER_H_
#define GAMEENGINE_GRAPHICS_RENDER_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

#include <vector>

#include <game-engine/core/game.h>
#include <game-engine/graphics/camera.h>
#include <game-engine/graphics/mesh.h>

namespace GameEngine {
namespace Graphics {
namespace Renderer {
  void init();
  void clear(Resolution);
  void set_camera(Camera, Resolution);
  void render(Camera, unsigned, std::vector<Mesh> const&);
  void update();
};
}
}

#endif
