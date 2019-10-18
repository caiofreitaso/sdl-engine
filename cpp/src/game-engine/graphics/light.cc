#include <game-engine/graphics/light.h>

void
GameEngine::Graphics::set_light(GameEngine::Graphics::Light light, unsigned number) {
  unsigned light_number = GL_LIGHT0 + number;

  glEnable(GL_LIGHTING);
  glEnable(light_number);

  glLightfv(light_number, GL_AMBIENT,  light.ambient.v);
  glLightfv(light_number, GL_DIFFUSE,  light.diffuse.v);
  glLightfv(light_number, GL_SPECULAR, light.specular.v);
  glLightfv(light_number, GL_POSITION, light.position.data());

  glLightf(light_number, GL_CONSTANT_ATTENUATION,  light.attenuation.constant);
  glLightf(light_number, GL_LINEAR_ATTENUATION,    light.attenuation.linear);
  glLightf(light_number, GL_QUADRATIC_ATTENUATION, light.attenuation.quadratic);
}

const GameEngine::Graphics::Light GameEngine::Graphics::DEFAULT_LIGHT = {
  .ambient = { 1, 1, 1, 1 },
  .diffuse = { 1, 1, 1, 1 },
  .specular = { 1, 1, 1, 1 },

  .position = { 3, 3, 20, 1 },

  .spot = {
    .direction = { 0.0f, 0.0f, 0.0f },
    .exponent = 0,
    .cutoff = 0
  },

  .attenuation = {
    .constant = 1,
    .linear = 0,
    .quadratic = 1,
  }
};
