#ifndef GAMEENGINE_CORE_GAME_H_
#define GAMEENGINE_CORE_GAME_H_

#include <cstdio>

#include <game-engine/core/settings.h>

namespace GameEngine {
struct GlobalState {
  SDL_Window *window;
  SDL_Surface *screen;
  SDL_GLContext context;

  bool should_quit;
  Resolution current_resolution;

  double fps;
  double delta_time;

  unsigned frame_count;
  unsigned last_time;
  unsigned diff_time;
};

struct Game {
  Settings settings;
  GlobalState state;

  int init(const char *);
  void quit();
  void update();
  Resolution window_size();
};

extern Game THE_GAME;
}

#endif
