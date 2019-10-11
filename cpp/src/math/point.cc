#include "../../include/game-engine/math/point.h"

template <class S, unsigned N>
S& GameEngine::Math::Point<S, N>::operator[](size_t i)
{
  return v[i];
}

template <class S, unsigned N>
constexpr S const& GameEngine::Math::Point<S, N>::operator[](size_t i) const
{
  return v[i];
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N>
GameEngine::Math::Point<S, N>::operator+(GameEngine::Math::Point<S, N> rhs) const
{
  for (size_t i = 0; i < N; i++)
    rhs.v[i] = v[i] + rhs.v[i];
  return rhs;
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N>
GameEngine::Math::Point<S, N>::operator-(GameEngine::Math::Point<S, N> rhs) const
{
  for (size_t i = 0; i < N; i++)
    rhs.v[i] = v[i] - rhs.v[i];
  return rhs;
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N> GameEngine::Math::Point<S, N>::operator*(S rhs) const
{
  GameEngine::Math::Point<S,N> r;
  for (size_t i = 0; i < N; i++)
    r.v[i] = v[i] * rhs;
  return r;
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N>
GameEngine::Math::Point<S, N>::operator/(S rhs) const
{
  GameEngine::Math::Point<S,N> r;
  for (size_t i = 0; i < N; i++)
    r.v[i] = v[i] / rhs;
  return r;
}

template <class S, unsigned N>
constexpr bool
GameEngine::Math::Point<S, N>::operator==(GameEngine::Math::Point<S, N> const& rhs) const
{
  for (size_t i = 0; i < N; i++)
    if (v[i] != rhs.v[i])
      return false;
  return true;
}

template <class S, unsigned N>
constexpr bool
GameEngine::Math::Point<S, N>::operator!=(GameEngine::Math::Point<S, N> const& rhs) const
{
  for (size_t i = 0; i < N; i++)
    if (v[i] != rhs.v[i])
      return true;
  return false;
}

template <class S, unsigned N>
typename GameEngine::Math::Point<S, N>::iterator
GameEngine::Math::Point<S, N>::begin()
{
  return v.begin();
}
template <class S, unsigned N>
typename GameEngine::Math::Point<S, N>::iterator
GameEngine::Math::Point<S, N>::end()
{
  return v.begin();
}

template <class S, unsigned N>
constexpr
typename GameEngine::Math::Point<S, N>::const_iterator
GameEngine::Math::Point<S, N>::cbegin() const
{
  return v.cbegin();
}

template <class S, unsigned N>
constexpr
typename GameEngine::Math::Point<S, N>::const_iterator
GameEngine::Math::Point<S, N>::cend() const
{
  return v.cbegin();
}

template <class S, unsigned N>
constexpr size_t
GameEngine::Math::Point<S, N>::size() const
{
  return N;
}

template <class S, unsigned N>
S
GameEngine::Math::Point<S, N>::length() const
{
  S ret{};
  for (size_t i = 0; i < N; i++)
    ret = ret + v[i] * v[i];
  return sqrt(ret);
}

template <class S, unsigned N>
void
GameEngine::Math::Point<S, N>::normalize()
{
  S len = length();
  for (size_t i = 0; i < N; i++)
    v[i] = v[i] / len;
}

template <class S, unsigned N>
S
dot(GameEngine::Math::Point<S, N> a, GameEngine::Math::Point<S, N> b)
{
  S ret{};
  for (size_t i = 0; i < N; i++)
    ret = ret + a.v[i] * b.v[i];
  return ret;
}

template <class S>
GameEngine::Math::Point<S, 3> cross(GameEngine::Math::Point<S, 3> lhs, GameEngine::Math::Point<S, 3> rhs)
{
  GameEngine::Math::Point<S, 3> ret;

  ret[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
  ret[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
  ret[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];

  return ret;
}

template <class S>
GameEngine::Math::Point<S, 3> normal(GameEngine::Math::Point<S, 3> a, GameEngine::Math::Point<S, 3> b, GameEngine::Math::Point<S, 3> c)
{
  GameEngine::Math::Point<S, 3> ret = cross(b - a, c - a);

  ret.normalize();

  return ret;
}
template <class S>
S area(GameEngine::Math::Point<S, 3> a, GameEngine::Math::Point<S, 3> b, GameEngine::Math::Point<S, 3> c)
{
  GameEngine::Math::Point<S, 3> ret = cross(a - b, a - c);

  return ret.length() / 2;
}

template <class S>
GameEngine::Math::Point<S, 4> homogenous(GameEngine::Math::Point<S, 3> a)
{
  GameEngine::Math::Point<S, 4> ret;

  ret[0] = a[0];
  ret[1] = a[1];
  ret[2] = a[2];
  ret[3] = 1.0f;
}

template <class S, unsigned N>
GameEngine::Math::Point<S, N> operator*(S k, GameEngine::Math::Point<S, N> const& p)
{
  return p * k;
}
