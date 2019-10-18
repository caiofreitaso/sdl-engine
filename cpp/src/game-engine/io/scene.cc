#include <game-engine/io/scene.h>

void
GameEngine::IO::Scene::init() {
  glGenVertexArrays(1, &VAO);
  state.input.scroll.amount = 0;
}

void
GameEngine::IO::Scene::destroy() {
  for(auto& mesh : meshes) {
    glDeleteBuffers(1, &mesh.VBO);
    glDeleteBuffers(1, &mesh.EBO);
  }

  glDeleteVertexArrays(1, &VAO);
}

void
GameEngine::IO::Scene::attach(std::vector<GameEngine::Graphics::Vertex> VBO, std::vector<unsigned> EBO, unsigned index) {
  Graphics::Mesh mesh;
  auto vertex_size = sizeof(Graphics::Vertex);

  mesh.reset = index;
  mesh.EBO_size = EBO.size();

  glGenBuffers(1, &mesh.VBO);
  glGenBuffers(1, &mesh.EBO);

  glBindVertexArray(VAO);

  glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
  glBufferData(GL_ARRAY_BUFFER, VBO.size() * vertex_size, VBO.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertex_size, (GLvoid*)0);

  glEnableVertexAttribArray(1);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertex_size, (GLvoid*)offsetof(Graphics::Vertex, normal));

  glEnableVertexAttribArray(2);
  glVertexAttribPointer(2, 4, GL_FLOAT, GL_FLOAT, vertex_size, (GLvoid*)offsetof(Graphics::Vertex, color));

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, EBO.size() * sizeof(unsigned), EBO.data(), GL_STATIC_DRAW);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  meshes.push_back(mesh);
}

void
GameEngine::IO::Scene::poll_events() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_WINDOWEVENT:
      case SDL_QUIT:
      case SDL_KEYDOWN:
      case SDL_KEYUP:
      case SDL_MOUSEBUTTONDOWN:
      case SDL_MOUSEBUTTONUP:
      case SDL_MOUSEWHEEL:
        EventHandlers::BASIC(event, this);
        break;
      default:
        event_handler(event, this);
        break;
    }
  }
}

void
GameEngine::IO::EventHandlers::NOP(SDL_Event e, GameEngine::IO::Scene *scene) {
}

void
GameEngine::IO::EventHandlers::BASIC(SDL_Event e, GameEngine::IO::Scene *scene) {
  auto &state = scene->state;
  auto &input = state.input;
  auto &game_state = THE_GAME.state;
  auto &resolution = game_state.current_resolution;

  switch (e.type) {
    case SDL_WINDOWEVENT:
      switch (e.window.event) {
        case SDL_WINDOWEVENT_RESIZED:
        case SDL_WINDOWEVENT_SIZE_CHANGED:
          resolution.width  = e.window.data1;
          resolution.height = e.window.data2;
          break;
      }
      break;

    case SDL_QUIT:
      game_state.should_quit = scene->end = true;
      break;

    case SDL_KEYDOWN:
    case SDL_KEYUP: {
      auto scancode = e.key.keysym.scancode;
      input.keys[scancode] = e.key.state;
      break;
    }

    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP: {
      auto &mouseLeft = input.mouse.left;
      auto &mouseMiddle = input.mouse.middle;
      auto &mouseRight = input.mouse.right;

      switch(e.button.button) {
        case SDL_BUTTON_LEFT:
          mouseLeft.state = e.button.state;
          mouseLeft.clicks = e.button.clicks;
          break;
        case SDL_BUTTON_MIDDLE:
          mouseMiddle.state = e.button.state;
          mouseMiddle.clicks = e.button.clicks;
          break;
        case SDL_BUTTON_RIGHT:
          mouseRight.state = e.button.state;
          mouseRight.clicks = e.button.clicks;
          break;
      }

      input.mouse.x = e.button.x;
      input.mouse.y = e.button.y;
      break;
    }
    case SDL_MOUSEWHEEL:
      input.scroll.amount = e.wheel.y;
      input.scroll.time = e.wheel.timestamp;
      break;
  }
}

namespace {
  bool pressed_key(GameEngine::IO::Scene *scene, unsigned char key) {
    return scene->state.input.keys[key] == SDL_PRESSED;
  }

  float value_to_add(GameEngine::IO::Scene *scene, unsigned char positive, unsigned char negative, float base_value) {
    if (pressed_key(scene, positive)) return base_value;
    if (pressed_key(scene, negative)) return -base_value;
    return 0.0f;
  }
}

void
GameEngine::IO::UpdateHandlers::WASD(GameEngine::IO::Scene *scene) {
  auto &game_state = THE_GAME.state;
  auto &settings = THE_GAME.settings;
  auto &input = scene->state.input;
  auto delta_pos = settings.controls.camera.speed * game_state.delta_time;

  Point3f camera_delta = {
    value_to_add(scene, SDL_SCANCODE_W, SDL_SCANCODE_S, delta_pos),
    value_to_add(scene, SDL_SCANCODE_D, SDL_SCANCODE_A, delta_pos),
    0.0f
  };

  scene->camera.position += camera_delta;
  scene->camera.target += camera_delta;

  if (pressed_key(scene, SDL_SCANCODE_E)) scene->camera.v_fov++;
  if (pressed_key(scene, SDL_SCANCODE_Q)) scene->camera.v_fov--;

  if (game_state.last_time - input.scroll.time <= settings.event_delay) {
    auto scroll_delta = input.scroll.amount * settings.controls.camera.scroll * game_state.delta_time;
    auto newpos = scene->camera.position[2] - scroll_delta;

    if (newpos > 200) {
      scene->camera.position[2] = 200;
      scene->camera.target[2] = 200 - cos(10 * Graphics::FOV_ANGLE_RATIO);
    } else if (newpos < 100) {
      scene->camera.position[2] = 100;
      scene->camera.target[2] = 100 - cos(10 * Graphics::FOV_ANGLE_RATIO);
    } else {
      scene->camera.position[2] -= scroll_delta;
      scene->camera.target[2] -= scroll_delta;
    }
  }
}
