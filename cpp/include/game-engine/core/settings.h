#ifndef GAMEENGINE_CORE_SETTINGS_H_
#define GAMEENGINE_CORE_SETTINGS_H_

#include <SDL.h>

#include <game-engine/core/resolution.h>

namespace GameEngine {
enum WindowType {
  WT_FULLSCREEN = SDL_WINDOW_FULLSCREEN_DESKTOP,
  WT_WINDOW = SDL_WINDOW_OPENGL,
  WT_BORDERLESS = SDL_WINDOW_BORDERLESS
};

struct VideoSettings {
  Resolution size;
  WindowType mode;
  bool vsync;
  float gamma;
};

struct CameraSettings {
  float speed;
  float scroll;
  float drag;
};

struct ControlSettings {
  bool lock_mouse;
  CameraSettings camera;
};

struct Settings {
  VideoSettings video;
  ControlSettings controls;
  unsigned event_delay;
  unsigned render_delay;
};
}

#endif
