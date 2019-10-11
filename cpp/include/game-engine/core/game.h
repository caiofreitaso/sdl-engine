#ifndef GAMEENGINE_CORE_GAME_H_
#define GAMEENGINE_CORE_GAME_H_

namespace GameEngine {
struct Game {
  SDL_Window *window;
  SDL_Surface *screen;
  SDL_GLContext context;
  SDL_bool quit;

  Settings settings;

  int init(const char *);
  void quit();
  void update();
  Resolution window();
}

extern Game THE_GAME;
}

#endif
