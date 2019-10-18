#include <game-engine/util/string.h>

std::vector<std::string> GameEngine::Util::split(std::string const &base, char delim) {
  std::vector<std::string> elements;
  std::stringstream sstream(base);
  std::string item;

  while(std::getline(sstream, item, delim)) {
    elements.push_back(std::move(item));
  }

  return elements;
}
