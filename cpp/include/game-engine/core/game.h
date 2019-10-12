#ifndef GAMEENGINE_CORE_GAME_H_
#define GAMEENGINE_CORE_GAME_H_

#include <cstdio>

#include <game-engine/core/settings.h>

namespace GameEngine {
struct Game {
  SDL_Window *window;
  SDL_Surface *screen;
  SDL_GLContext context;
  bool should_quit;

  Settings settings;

  int init(const char *);
  void quit();
  void update();
  Resolution window_size();
};

extern Game THE_GAME;
}

#endif
