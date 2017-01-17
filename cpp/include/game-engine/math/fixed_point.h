#pragma once
#ifndef FIXED_POINT_H
#define FIXED_POINT_H

#include <game-engine/math/fixed.h>
#include <game-engine/math/point.h>

namespace Engine { namespace Math {

	typedef Point<FixedPoint,2> Point2f;
	typedef Point<FixedPoint,3> Point3f;

	typedef Point<HalfFixed,2> Point2h;
	typedef Point<HalfFixed,3> Point3h;

}}

#endif
