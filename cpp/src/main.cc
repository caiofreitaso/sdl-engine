#include <omp.h>

#include <sstream>

#include <game-engine/io/scene.h>
#include <game-engine/graphics/heightmap.h>
#include <game-engine/graphics/render.h>

using namespace GameEngine;



int
main(int argc, char **args) {
  auto &GAME_STATE = THE_GAME.state;
  Map map;

  if (argc > 1) {
    map = Map::from_file(args[1]);
  } else {
    map = Map::random(800, 800);
  }

  if (!THE_GAME.init("Engine Test")) {
    IO::Scene s;
    s.end = false;
    s.event_handler = IO::EventHandlers::NOP;
    s.update = IO::UpdateHandlers::WASD;

    s.camera = Graphics::DEFAULT_CAMERA;
    s.camera.position = { 0, 0, 10 };

    float angleDown = 10;

    s.camera.target[0] = 0;
    s.camera.target[1] = sin(angleDown * Graphics::FOV_ANGLE_RATIO);
    s.camera.target[2] -= cos(angleDown * Graphics::FOV_ANGLE_RATIO);
    s.camera.v_fov = 20;


    Graphics::HeightMap hm(map);

    Graphics::Renderer::init();
    Graphics::set_light(Graphics::DEFAULT_LIGHT, 0);

    s.init();
    s.attach(hm.vertices, hm.indices, hm.reset_index);

    while (!GAME_STATE.should_quit) {
      while (!s.end) {
        s.poll_events();
        s.update(&s);
        Graphics::Renderer::render(s.camera, s.VAO, s.meshes);

        std::stringstream sstream;
        sstream << "Engine Test (" << GAME_STATE.fps << " fps, frame #" << GAME_STATE.frame_count << ")";
        SDL_SetWindowTitle(GAME_STATE.window, sstream.str().c_str());

        if (GAME_STATE.diff_time <= THE_GAME.settings.event_delay) {
          SDL_Delay(THE_GAME.settings.event_delay);
        }
      }
    }
    s.destroy();
  }
  GameEngine::THE_GAME.quit();
  return 0;
}
