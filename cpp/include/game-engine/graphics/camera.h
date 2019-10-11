#ifndef GAMEENGINE_GRAPHICS_CAMERA_H_
#define GAMEENGINE_GRAPHICS_CAMERA_H_

namespace GameEngine {
namespace Graphics {
struct Camera {
  bool perspective;
  union {
    struct {
      float v_fov;
    };
    struct {
      float left;
      float right;
      float top;
      float bottom;
    };
  } float near;
  float far;
}

extern const Camera DEFAULT_CAMERA;
}
}

#endif
