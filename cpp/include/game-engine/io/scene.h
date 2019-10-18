#ifndef GAMEENGINE_IO_SCENE_H_
#define GAMEENGINE_IO_SCENE_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>

#include <vector>

#include <game-engine/core/game.h>
#include <game-engine/core/state.h>
#include <game-engine/graphics/camera.h>
#include <game-engine/graphics/light.h>
#include <game-engine/graphics/mesh.h>

namespace GameEngine {
namespace IO {
struct Scene;

typedef void (*UpdateHandler)(Scene*);
typedef void (*EventHandler)(SDL_Event, Scene*);

struct Scene {
  unsigned VAO;
  std::vector<Graphics::Mesh> meshes;

  Graphics::Camera camera;
  bool end;

  State state;

  UpdateHandler update;
  EventHandler event_handler;

  void init();
  void attach(std::vector<Graphics::Vertex> VBO, std::vector<unsigned> EBO, unsigned index);
  void destroy();
  void poll_events();
};

namespace EventHandlers {
extern void NOP(SDL_Event, Scene*);
extern void BASIC(SDL_Event, Scene*);
}

namespace UpdateHandlers {
extern void WASD(Scene*);
}
}
}

#endif
