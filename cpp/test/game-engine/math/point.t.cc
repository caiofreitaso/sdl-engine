#include <gtest/gtest.h>
#include <game-engine/math/point.h>

using namespace GameEngine::Math;

namespace {
TEST(PointTest, Braces) {
  Point<float, 1> a;

  a[0] = 12345.0f;

  EXPECT_EQ(12345.0f, a[0]);
}

TEST(PointTest, SumAB) {
  Point<float, 1> a, b;

  a[0] = 2.0f;
  b[0] = 1.0f;
  a = a + b;

  EXPECT_EQ(3.0f, a[0]);
}

TEST(PointTest, SumBA) {
  Point<float, 1> a, b;

  a[0] = 2.0f;
  b[0] = 1.0f;
  a = b + a;

  EXPECT_EQ(3.0f, a[0]);
}

TEST(PointTest, SubtractionAB) {
  Point<float, 1> a, b;

  a[0] = 2.0f;
  b[0] = 1.0f;
  a = a - b;

  EXPECT_EQ(1.0f, a[0]);
}

TEST(PointTest, SubtractionBA) {
  Point<float, 1> a, b;

  a[0] = 2.0f;
  b[0] = 1.0f;
  a = b - a;

  EXPECT_EQ(-1.0f, a[0]);
}

TEST(PointTest, Multiplication2A) {
  Point<float, 1> a;

  a[0] = 1.0f;
  a = a * (float)2.0f;

  EXPECT_EQ(2.0f, a[0]);
}

TEST(PointTest, MultiplicationA2) {
  Point<float, 1> a;

  a[0] = 1.0f;
  a = a * 2.0f;

  EXPECT_EQ(2.0f, a[0]);
}

TEST(PointTest, BracesInitializer) {
  Point<float, 3> a = { 0.1f, 0, 0 };

  EXPECT_EQ(0.1f, a[0]);
  EXPECT_EQ(0.0f, a[1]);
  EXPECT_EQ(0.0f, a[2]);
}

TEST(PointTest, Length1D) {
  Point<float, 1> a;

  a[0] = 5.0f;

  EXPECT_EQ(5.0f, a.length());
}

TEST(PointTest, Length2D) {
  Point<float, 2> a;

  a[0] = a[1] = 1.0f;

  EXPECT_GE(POINT_PRECISION, abs(sqrt(2) - a.length()));
}

TEST(PointTest, Dot2D) {
  Point<float, 2> a, b;

  a[0] = a[1] = 1.0f;
  b[0] = b[1] = 5.0f;

  EXPECT_EQ(10.0f, a.dot(b));
}

}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
