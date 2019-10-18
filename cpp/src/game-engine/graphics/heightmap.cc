#include <game-engine/graphics/heightmap.h>

GameEngine::Graphics::HeightMap::HeightMap(GameEngine::Map const &map)
    : reset_index((map.x + 1) * (map.y + 1))
    , vertices((map.x + 1) * (map.y + 1))
    , indices((map.y + 1) * map.x * 2 + map.x - 1) {
  set_vertices(map);
  set_indices(map);
  set_normals(map);
}

GameEngine::Graphics::Color GameEngine::Graphics::HeightMap::from_terrain(GameEngine::Terrain terrain) {
  switch (terrain) {
    case T_GRASS: return COLOR_GRASS;
    case T_HARD_SAND: return COLOR_HARD_SAND;
    case T_TALL_GRASS: return COLOR_TALL_GRASS;
    case T_DENSE_BUSHES: return COLOR_DENSE_BUSHES;
    case T_SOFT_SAND: return COLOR_SOFT_SAND;
    case T_SWAMP: return COLOR_SWAMP;
    case T_WATER: return COLOR_WATER;
    case T_DEEP_WATER: return COLOR_DEEP_WATER;
  }
}

float height_at(GameEngine::Map const &map, size_t index) {
  return map.field[index].height * GameEngine::Graphics::HeightMap::HEIGHT_SCALE;
}

void GameEngine::Graphics::HeightMap::set_vertices(GameEngine::Map const &map) {
  vertices[0].position = { 0.0f, 0.0f, height_at(map, 0) };
  vertices[0].color = from_terrain(map.field[0].type);

  for (size_t i = 0; i < map.y + 1; i++) {
    vertices[i].position = { 0.0f, i, height_at(map, i) };
    vertices[i].color = from_terrain(map.field[i].type);
  }

  for (size_t i = 1; i < map.x + 1; i++) {
    for (size_t j = 0; j < map.y + 1; j++) {
      auto index = i * (map.y + 1) + j;
      auto previous = (i - 1) * map.y + j;
      auto &vertex = vertices[index];

      if (j > 0) {
        vertex.position = { i, j, height_at(map, previous - 1) };
        vertex.color = from_terrain(map.field[previous - 1].type);
      } else {
        vertex.position = { i, j, 0.0f };
        vertex.color = from_terrain(map.field[previous].type);
      }
    }
  }
}

void GameEngine::Graphics::HeightMap::set_indices(GameEngine::Map const &map) {
  auto *face_pointer = &indices[0];
  for (int i = 0; i < map.x; i++) {
    for (int j = 0; j < map.y + 1; j++) {
      *face_pointer = i * (map.y + 1) + j;
      face_pointer++;
      *face_pointer = (i + 1) * (map.y + 1) + j;
      face_pointer++;
    }
    if (i < map.x - 1) {
      *face_pointer = reset_index;
      face_pointer++;
    }
  }
}

void GameEngine::Graphics::HeightMap::set_normals(GameEngine::Map const &map) {
  std::vector<Point3f> face_normals;

  for (int i = 0; i < indices.size() - 2; i++) {
    if (indices[i + 2] == vertices.size()) {
      i += 2;
    }

    auto a = vertices[indices[i]].position;
    auto b = vertices[indices[i + 1]].position;
    auto c = vertices[indices[i + 2]].position;

    auto normal = Point3f::normal(a, b, c);
    auto area = Point3f::area(a, b, c);

    if (normal[2] < 0.0f) {
      normal *= -1.0f;
    }

    face_normals.push_back(normal);
  }

  //first
  vertices[0].normal = face_normals[0].normalized();

  //last of first row
  vertices[map.y].normal = (face_normals[2 * map.y - 1]
    + face_normals[2 * map.y - 2]).normalized();

  //first row
  for (size_t i = 1; i < map.y; i++) {
    for (size_t j = 0; j < 3; j++) {
      vertices[i].normal += face_normals[2 * i - j];
    }
    vertices[i].normal = vertices[i].normal.normalized();
  }

  //first column
  for (size_t i = 1; i < map.x; i++) {
    vertices[i * (map.y + 1)].normal = (face_normals[2 * (i-1) * map.y]
      + face_normals[2 * (i-1) * map.y + 1] + face_normals[i * map.y])
      .normalized();
  }

  //last column
  for (size_t i = 1; i < map.x; i++) {
    vertices[i * (map.y + 1) + map.y].normal = (face_normals[2 * i * map.y - 1]
      + face_normals[2 * (i+1) * map.y - 1] + face_normals[2 * (i+1) * map.y - 2])
      .normalized();
  }

  //last row
  for (size_t i = 1; i < map.y; i++) {
    auto index = map.x * (map.y + 1) + i;
    for (int k = -1; k < 2; k++) {
      vertices[index].normal += face_normals[face_normals.size() - map.y + 2 * i + k];
    }
    vertices[index].normal = vertices[index].normal.normalized();
  }

  //middle
  for (size_t i = 1; i < map.x; i++) {
    for (size_t j = 1; j < map.y; j++) {
      auto &normal = vertices[i * (map.y + 1) + j].normal;

      for (int k = -2; k < 1; k++)
        normal += face_normals[2 * i * map.x + 2 * j + k];

      for (int k = -1; k < 2; k++)
        normal += face_normals[2 * (i-1) * map.x + 2 * j + k];
      normal = normal.normalized();
    }
  }

  //first of last row
  vertices[vertices.size() - map.y - 1].normal = (face_normals[face_normals.size() - 2 * map.y]
    + face_normals[face_normals.size() - 2 * map.y + 1])
    .normalized();

  //last of all
  vertices[vertices.size() - 1].normal = face_normals[face_normals.size() - 1].normalized();
}
