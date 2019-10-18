#ifndef GAMEENGINE_MAP_MAP_H
#define GAMEENGINE_MAP_MAP_H

#include <fstream>
#include <vector>

namespace GameEngine {
enum Terrain {
  T_GRASS = 27,
  T_HARD_SAND = 26,

  T_TALL_GRASS = 21,

  T_DENSE_BUSHES = 11,

  T_SOFT_SAND = 6,
  T_SWAMP = 5,

  T_WATER = 1,
  T_DEEP_WATER = 0,
};
struct Map {
  struct Point {
    Terrain type;
    unsigned short height;
  };

  unsigned short x;
  unsigned short y;

  std::vector<Point> field;

  static Map from_file(const char *);
};
}

#endif
