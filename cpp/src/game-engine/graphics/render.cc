#include <game-engine/graphics/render.h>

void
GameEngine::Graphics::Renderer::init() {
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0, 0, 0, 0.8);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void
GameEngine::Graphics::Renderer::clear(GameEngine::Resolution window) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0, 0, window.width, window.height);
}

void
GameEngine::Graphics::Renderer::set_camera(GameEngine::Graphics::Camera camera, GameEngine::Resolution window) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (camera.perspective) {
    float ratio = ((float)window.width) / window.height;
    float fov = FOV_INTO_ANGLE * atan(tan(camera.v_fov * FOV_ANGLE_RATIO) * ratio);

    gluPerspective(fov, ratio, camera.near, camera.far);
    gluLookAt(camera.position[0], camera.position[1], camera.position[2], camera.target[0], camera.target[1],
              camera.target[2], camera.up[0], camera.up[1], camera.up[2]);
  } else
    glOrtho(camera.left, camera.right, camera.bottom, camera.top, camera.near, camera.far);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void
GameEngine::Graphics::Renderer::update() {
  auto actual = SDL_GetTicks();
  auto &state = THE_GAME.state;

  state.diff_time = actual - state.last_time;
  state.delta_time = ((double)state.diff_time)/1000.0;
  state.fps = 1/state.delta_time;
  state.last_time = actual;
  state.frame_count++;
}

void
GameEngine::Graphics::Renderer::render(GameEngine::Graphics::Camera camera, unsigned VAO, std::vector<GameEngine::Graphics::Mesh> const &meshes) {
  auto resolution = THE_GAME.state.current_resolution;
  auto window = THE_GAME.state.window;

  clear(resolution);
  set_camera(camera, resolution);

  glBindVertexArray(VAO);

  for (auto& mesh : meshes) {
    glBindBuffer(GL_ARRAY_BUFFER, mesh.VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh.EBO);

    glEnable(GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex(mesh.reset);

    glDrawElements(GL_TRIANGLE_STRIP, mesh.EBO_size, GL_UNSIGNED_INT, 0);
  }

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  SDL_GL_SwapWindow(window);

  update();
}


