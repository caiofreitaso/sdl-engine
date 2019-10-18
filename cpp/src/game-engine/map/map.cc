#include <game-engine/map/map.h>

GameEngine::Map GameEngine::Map::from_file(const char *filename) {
  Map ret;
  std::fstream file(filename, std::fstream::in);

  file >> ret.x;
  file >> ret.y;

  ret.field.reserve(ret.x * ret.y);

  for(int i = 0; i < ret.x; i++)
    for(int j = 0; j < ret.y; j++) {
      int type;
      file >> ret.field[i * ret.x + j].height;
      file >> type;
      ret.field[i * ret.x + j].type = (Terrain)type;
    }

  return ret;
}
