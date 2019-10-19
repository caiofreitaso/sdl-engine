#include <game-engine/core/map.h>

GameEngine::Map GameEngine::Map::from_file(const char *filename) {
  Map ret;
  std::fstream file(filename, std::fstream::in);

  file >> ret.x;
  file >> ret.y;

  ret.field.reserve(ret.x * ret.y);

  for(int i = 0; i < ret.x; i++)
    for(int j = 0; j < ret.y; j++) {
      std::stringstream sstream;
      std::string point_string;
      int type;
      Map::Point point;

      file >> point_string;

      auto values = Util::split(point_string, ',');

      sstream.str(values[0]);
      sstream.clear();
      sstream >> point.height;
      sstream.str(values[1]);
      sstream.clear();
      sstream >> type;

      point.type = (Terrain)type;

      ret.field.push_back(point);
    }

  return ret;
}

GameEngine::Map GameEngine::Map::random(unsigned short x, unsigned short y) {
  static const unsigned terrain_types[8] = { 27, 26, 21, 11, 6, 5, 1, 0 };
  Map map;
  std::mt19937 random;

  map.x = x;
  map.y = y;
  map.field.reserve(map.x * map.y);

  for (int i = 0; i < map.x; i++) {
    for (int j = 0; j < map.y; j++) {
      auto point = Map::Point {
        .type = (Terrain) (terrain_types[random() % 8]),
        .height = random() % 128,
      };

      map.field.push_back(point);
    }
  }

  return map;
}
