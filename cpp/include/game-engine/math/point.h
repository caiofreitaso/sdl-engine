#pragma once
#ifndef GAMEENGINE_MATH_POINT_H_
#define GAMEENGINE_MATH_POINT_H_

#include <array>
#include <cmath>
#include <type_traits>

namespace GameEngine {
namespace Math {
extern const float POINT_PRECISION;

template <class S, unsigned N>
struct Point {
  std::array<S, N> v;

// operators
  S& operator[](size_t i) { return v[i]; }
  constexpr S const& operator[](size_t i) const { return v[i]; }

  Point operator+(Point rhs) const {
    for (size_t i = 0; i < N; i++)
      rhs.v[i] = v[i] + rhs.v[i];
    return rhs;
  }

  Point operator-(Point rhs) const {
    for (size_t i = 0; i < N; i++)
      rhs.v[i] = v[i] - rhs.v[i];
    return rhs;
  }

  Point operator*(S const &rhs) const {
    Point r;
    for (size_t i = 0; i < N; i++)
      r.v[i] = v[i] * rhs;
    return r;
  }

  Point operator/(S const &rhs) const {
    Point r;
    for (size_t i = 0; i < N; i++)
      r.v[i] = v[i] / rhs;
    return r;
  }

// assignment operators
  Point& operator+=(Point const &rhs) {
    for (size_t i = 0; i < N; i++)
      v[i] = v[i] + rhs.v[i];
    return *this;
  }

  Point& operator-=(Point const &rhs) {
    for (size_t i = 0; i < N; i++)
      v[i] = v[i] - rhs.v[i];
    return *this;
  }

  Point& operator*=(S const &rhs) {
    for (size_t i = 0; i < N; i++)
      v[i] = v[i] * rhs;
    return *this;
  }

  Point& operator/=(S const &rhs) {
    for (size_t i = 0; i < N; i++)
      v[i] = v[i] / rhs;
    return *this;
  }

// comparison operators
  constexpr bool operator==(Point const &rhs) const {
    for (size_t i = 0; i < N; i++)
      if (v[i] != rhs.v[i])
        return false;
    return true;
  }

  constexpr bool operator!=(Point const &rhs) const {
    for (size_t i = 0; i < N; i++)
      if (v[i] != rhs.v[i])
        return true;
    return false;
  }

// iterator functions
  typedef typename std::array<S, N>::iterator iterator;
  typedef typename std::array<S, N>::const_iterator const_iterator;

  iterator begin() { return v.begin(); }
  iterator end() { return v.end(); }

  constexpr const_iterator cbegin() const { return v.cbegin(); }
  constexpr const_iterator cend() const { return v.cend(); }

  constexpr size_t size() const { return v.size(); }

// data functions
  constexpr S* data() { return v.data(); }
  constexpr S const* data() const { return v.data(); }

// point functions
  S length() const {
    S ret{};
    for (size_t i = 0; i < N; i++)
      ret = ret + v[i] * v[i];
    return sqrt(ret);
  }

  S dot(Point rhs) const {
    S ret{};
    for (size_t i = 0; i < N; i++)
      ret = ret + v[i] * rhs[i];
    return ret;
  }

  Point normalized() {
    Point ret;
    S len = length();
    for (size_t i = 0; i < N; i++)
      ret.v[i] = v[i] / len;
    return ret;
  }

  static S area(Point r1, Point r2, Point r3) {
    auto a = (r1 - r2).length();
    auto b = (r2 - r3).length();
    auto c = (r3 - r1).length();
    auto s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
  }

// 3D functions
#define ONLY_3D  template<unsigned M = N, typename std::enable_if<M == 3, int>::type = 0>
  ONLY_3D
  Point cross(Point rhs) const {
    Point ret;

    ret[0] = this->v[1]*rhs[2] - this->v[2]*rhs[1];
    ret[1] = this->v[2]*rhs[0] - this->v[0]*rhs[2];
    ret[2] = this->v[0]*rhs[1] - this->v[1]*rhs[0];

    return ret;
  }

  ONLY_3D
  Point<S, 4> homogenous() const {
    return Point<S, 4> { this->v[0], this->v[1], this->v[2], 1.0f };
  }

  ONLY_3D
  static Point normal(Point a, Point b, Point c) {
    Point ret = (b - a).cross(c - a);

    return ret.normalized();
  }
#undef ONLY_3D

// friends
  template <class T, unsigned K>
  friend Point<T, K> operator*(T, Point<T, K> const &);
};

}
typedef Math::Point<float, 2> Point2f;
typedef Math::Point<float, 3> Point3f;
typedef Math::Point<float, 4> Point4f;
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N> operator*(S k, GameEngine::Math::Point<S, N> const &p);

#endif
