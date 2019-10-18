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
