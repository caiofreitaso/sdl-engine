#ifndef GAMEENGINE_GRAPHICS_LIGHT_H_
#define GAMEENGINE_GRAPHICS_LIGHT_H_

#include <game-engine/graphics/color.h>
#include <game-engine/math/point.h>

namespace GameEngine {
namespace Graphics {
struct Light {
  struct Spot {
    Math::Point3 direction;
    float exponent;
    float cutoff;
  } struct Attenuation {
    float constant;
    float linear;
    float quadratic;
  }

  Color ambient;
  Color diffuse;
  Color specular;
  Math::Point4 position;
  Spot spot;
  Attenuation attenuation;
}

extern const Light DEFAULT_LIGHT;

void set_light(Light, unsigned);
}
}

#endif
