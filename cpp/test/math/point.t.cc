#include "../../include/game-engine/math/point.h"
#include "gtest/gtest.h"

using namespace GameEngine::Math;

namespace {

TEST(PointTest, Braces) {
  Point<float, 1> a;

  a[0] = 12345.0f;

  EXPECT_EQ(12345.0f, a[0]);
}

TEST(PointTest, SumAB) {
  Point<float, 1> a, b;

  a[0] = 2;
  b[0] = 1;
  a = a + b;

  EXPECT_EQ(3.0f, a[0]);
}

TEST(PointTest, SumBA) {
  Point<float, 1> a, b;

  a[0] = 2;
  b[0] = 1;
  a = b + a;

  EXPECT_EQ(3.0f, a[0]);
}

TEST(PointTest, SubtractionAB) {
  Point<float, 1> a, b;

  a[0] = 2;
  b[0] = 1;
  a = a - b;

  EXPECT_EQ(1.0f, a[0]);
}

TEST(PointTest, SubtractionBA) {
  Point<float, 1> a, b;

  a[0] = 2;
  b[0] = 1;
  a = b - a;

  EXPECT_EQ(-1.0f, a[0]);
}

TEST(PointTest, Multiplication2A) {
  Point<float, 1> a;

  a[0] = 1;
  a = 2.0f * a;

  EXPECT_EQ(2.0f, a[0]);
}

TEST(PointTest, MultiplicationA2) {
  Point<float, 1> a;

  a[0] = 1;
  a = a * 2.0f;

  EXPECT_EQ(2.0f, a[0]);
}

}

int main(int argc, char** argv) {
  return RUN_ALL_TESTS();
}
