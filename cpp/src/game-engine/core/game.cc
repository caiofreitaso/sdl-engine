#include <game-engine/core/game.h>

int
GameEngine::Game::init(const char *title) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return -1;
  } else {
    auto video = this->settings.video;

    state.window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, video.size.width,
                                    video.size.height, video.mode);

    if (state.window == NULL) {
      printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
      return -2;
    } else {
      SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

      state.screen = SDL_GetWindowSurface(state.window);
      state.context = SDL_GL_CreateContext(state.window);

      return 0;
    }
  }
}

void
GameEngine::Game::quit() {
  SDL_GL_DeleteContext(state.context);
  SDL_DestroyWindow(state.window);
  SDL_Quit();
}

void
GameEngine::Game::update() {}

GameEngine::Resolution
GameEngine::Game::window_size() {
  Resolution ret;
  SDL_GetWindowSize(state.window, &ret.width, &ret.height);
  return ret;
}

GameEngine::Game GameEngine::THE_GAME = {
  .settings = {
    .video = {
      .size = { 1024, 768 },
      .mode = WT_WINDOW,
      .vsync = false,
      .gamma = 1.0
    },
    .controls = {
      .lock_mouse = false,
      .camera = { .speed = 100, .scroll = 800, .drag = 1, },
    },
    .event_delay = 16,
    .render_delay = 1
  },

  .state = {
    .window = nullptr,
    .screen = nullptr,
    .context = 0,
    .should_quit = false,
    .current_resolution = { 1024, 768 },
  },
};
