#ifndef GAMEENGINE_GRAPHICS_LIGHT_H_
#define GAMEENGINE_GRAPHICS_LIGHT_H_

#include <GL/gl.h>

#include <game-engine/graphics/color.h>
#include <game-engine/math/point.h>

namespace GameEngine {
namespace Graphics {
struct Light {
  struct Spot {
    Point3f direction;
    float exponent;
    float cutoff;
  };
  struct Attenuation {
    float constant;
    float linear;
    float quadratic;
  };

  Color ambient;
  Color diffuse;
  Color specular;
  Point4f position;
  Spot spot;
  Attenuation attenuation;
};

extern const Light DEFAULT_LIGHT;

void set_light(Light, unsigned);
}
}

#endif
