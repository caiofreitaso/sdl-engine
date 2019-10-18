#include <gtest/gtest.h>
#include <game-engine/core/map.h>
#include <fstream>
#include <cstdio>

using namespace GameEngine;

bool file_exists(const char *filename) {
  return std::ifstream(filename).good();
}

class MapFixture : public ::testing::Test {
public:
  static constexpr char *FILE_NAME = "test.map";
  static constexpr char *MAP_CONTENT =
"16 16\n"
"\n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21 10,27 80,21 10,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21 10,21 30,27 60,21 30,21 10,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21 10,21 40,27 40,21 40,21 10,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21 10,27 20,21 10,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21 10,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21 \n"
"0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  0,21  1,11 \n";

protected:
  void SetUp() {
    if (file_exists(FILE_NAME))
      return;

    std::fstream file(FILE_NAME, std::fstream::out);
    file << MAP_CONTENT;
    file.close();
  }

  void TearDown() {
    if (!file_exists(FILE_NAME))
      return;

    std::remove(FILE_NAME);
  }
};

TEST_F(MapFixture, ReadX) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(16, m.x);
}

TEST_F(MapFixture, ReadY) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(16, m.y);
}

TEST_F(MapFixture, ReadField_Size) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(256, m.field.size());
}

TEST_F(MapFixture, ReadField_First_Height) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(0, m.field[0].height);
}

TEST_F(MapFixture, ReadField_First_Type) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(T_TALL_GRASS, m.field[0].type);
}

TEST_F(MapFixture, ReadField_Middle_Height) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(10, m.field[18].height);
}

TEST_F(MapFixture, ReadField_Middle_Type) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(T_GRASS, m.field[18].type);
}

TEST_F(MapFixture, ReadField_Last_Height) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(1, m.field[255].height);
}

TEST_F(MapFixture, ReadField_Last_Type) {
  Map m = Map::from_file(FILE_NAME);

  EXPECT_EQ(T_DENSE_BUSHES, m.field[255].type);
}
