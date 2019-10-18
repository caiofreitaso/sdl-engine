#ifndef GAMEENGINE_GRAPHICS_CAMERA_H_
#define GAMEENGINE_GRAPHICS_CAMERA_H_

#include <game-engine/math/point.h>

namespace GameEngine {
namespace Graphics {
struct Camera {
  bool perspective;
  union {
    struct {
      float v_fov;
      Point3f position;
      Point3f target;
      Point3f up;
    };
    struct {
      float left;
      float right;
      float top;
      float bottom;
    };
  };
  float near;
  float far;
};

extern const Camera DEFAULT_CAMERA;
extern const float FOV_ANGLE_RATIO;
extern const float FOV_INTO_ANGLE;
}
}

#endif
