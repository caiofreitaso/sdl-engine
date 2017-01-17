#pragma once
#ifndef UTIL_H
#define UTIL_H

#include <type_traits>

namespace Engine { namespace Math {

constexpr int abs(int a)
{
	return a < 0 ? -a : a;
}

constexpr int gcd(int a, int b)
{
	return b == 0 ? abs(a) : gcd(b, a%b);
}

constexpr int lcm(int a, int b)
{
	return abs((a/gcd(a,b))*b);
}


}}

#endif