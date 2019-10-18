#include <gtest/gtest.h>
#include <game-engine/util/string.h>

using namespace GameEngine;

class StringFixture : public ::testing::Test {
protected:
  static constexpr char *TEST_STRING = "a,b,c";
  std::vector<std::string> values;

  void SetUp() {
    values = Util::split(std::string(TEST_STRING), ',');
  }
};

TEST_F(StringFixture, SplitSize) {
  EXPECT_EQ(3, values.size());
}

TEST_F(StringFixture, SplitContent_0) {
  EXPECT_EQ(std::string("a"), values[0]);
}

TEST_F(StringFixture, SplitContent_1) {
  EXPECT_EQ(std::string("b"), values[1]);
}

TEST_F(StringFixture, SplitContent_2) {
  EXPECT_EQ(std::string("c"), values[2]);
}

