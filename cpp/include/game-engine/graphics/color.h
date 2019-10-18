#ifndef GAMEENGINE_GRAPHICS_COLOR_H_
#define GAMEENGINE_GRAPHICS_COLOR_H_

namespace GameEngine {
namespace Graphics {
union Color {
  float v[4];
  struct {
    float r, g, b, a;
  };
};

extern const Color COLOR_CLIFF;
extern const Color COLOR_DEEP_WATER;
extern const Color COLOR_WATER;
extern const Color COLOR_SWAMP;
extern const Color COLOR_SOFT_SAND;
extern const Color COLOR_DENSE_BUSHES;
extern const Color COLOR_TALL_GRASS;
extern const Color COLOR_HARD_SAND;
extern const Color COLOR_GRASS;

extern const Color LIGHT_GRAY;
extern const Color LIGHT_RED;
extern const Color LIGHT_GREEN;
extern const Color LIGHT_BLUE;
extern const Color LIGHT_CYAN;
extern const Color LIGHT_MAGENTA;
extern const Color LIGHT_YELLOW;

extern const Color WHITE;
extern const Color GRAY;
extern const Color BLACK;
extern const Color RED;
extern const Color GREEN;
extern const Color BLUE;
extern const Color CYAN;
extern const Color MAGENTA;
extern const Color YELLOW;
}
}

#endif
