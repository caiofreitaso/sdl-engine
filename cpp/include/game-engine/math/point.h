#pragma once
#ifndef GAMEENGINE_MATH_POINT_H_
#define GAMEENGINE_MATH_POINT_H_

#include <array>
#include <cmath>

namespace GameEngine {
namespace Math {
extern const float POINT_PRECISION;

template <class S, unsigned N> struct Point {
  std::array<S, N> v;

public: // operators
  S &operator[](size_t i);
  constexpr S const &operator[](size_t i) const;

  Point operator+(Point rhs) const;
  Point operator-(Point rhs) const;
  Point operator*(S rhs) const;
  Point operator/(S rhs) const;

  constexpr bool operator==(Point const &rhs) const;
  constexpr bool operator!=(Point const &rhs) const;
public: // iterator functions
  typedef typename std::array<S, N>::iterator iterator;
  typedef typename std::array<S, N>::const_iterator const_iterator;

  iterator begin();
  iterator end();

  constexpr const_iterator cbegin() const;
  constexpr const_iterator cend() const;

  constexpr size_t size() const;

public: // functions
  S length() const;
  void normalize();

public: // friends
  template <class T, unsigned K>
  friend Point<T, K> operator*(T, Point<T, K> const &);
};

template <class S, unsigned N>
S dot(Point<S, N> a, Point<S, N> b);

template <class S>
Point<S, 3> cross(Point<S, 3> lhs, Point<S, 3> rhs);

template <class S>
Point<S, 3> normal(Point<S, 3> a, Point<S, 3> b, Point<S, 3> c);

template <class S>
S area(Point<S, 3> a, Point<S, 3> b, Point<S, 3> c);

template <class S>
Point<S, 4> homogenous(Point<S, 3> b);

template <class S, unsigned N>
Point<S, N> operator*(S k, Point<S, N> const &p);

typedef Math::Point<float, 2> Point2;
typedef Math::Point<float, 3> Point3;
typedef Math::Point<float, 4> Point4;
}
}

#endif
