#include <game-engine/graphics/camera.h>

const float GameEngine::Graphics::FOV_ANGLE_RATIO = 3.14159265 / 180;
const float GameEngine::Graphics::FOV_INTO_ANGLE = 360 / 3.14159265;

const GameEngine::Graphics::Camera GameEngine::Graphics::DEFAULT_CAMERA = {
  .perspective = true,
  {{
    .v_fov = 110.0,
    .position = { 8.0f, 0.0f, 15.0f },
    .target = { 8.0f, 8.0f, 0.0f },
    .up = { 0.0f, 0.0f, 1.0f }
  }},
  .near = 1.0f,
  .far = 10000.0f
};
