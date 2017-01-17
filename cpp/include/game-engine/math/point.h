#pragma once
#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <array>

#include <game-engine/core/variadic.h>

namespace Engine {
	namespace Math {
		extern const float POINT_PRECISION;

		template<class S, unsigned N>
		struct Point
		{
			std::array<S,N> v;

		public: //operators
			S&
			operator[](size_t i) { return v[i]; }

			constexpr S const&
			operator[](size_t i) const { return v[i]; }

			Point
			operator+(Point rhs) const
			{
				for (size_t i = 0; i < N; i++)
					rhs.v[i] = v[i] + rhs.v[i];
				return rhs;
			}

			Point
			operator-(Point rhs) const
			{
				for (size_t i = 0; i < N; i++)
					rhs.v[i] = v[i] - rhs.v[i];
				return rhs;
			}

			Point
			operator*(S rhs) const
			{
				Point r;
				for (size_t i = 0; i < N; i++)
					r.v[i] = v[i] * rhs;
				return r;
			}

			Point
			operator/(S rhs) const
			{
				Point r;
				for (size_t i = 0; i < N; i++)
					r.v[i] = v[i] / rhs;
				return r;
			}

			constexpr bool
			operator==(Point const& rhs) const
			{
				for (size_t i = 0; i < N; i++)
					if (v[i] != rhs.v[i])
						return false;
				return true;
			}

			constexpr bool
			operator!=(Point const& rhs) const
			{
				for (size_t i = 0; i < N; i++)
					if (v[i] != rhs.v[i])
						return true;
				return false;
			}

		public: //iterator functions
			typename std::array<S,N>::iterator
			begin() { return v.begin(); }

			typename std::array<S,N>::iterator
			end() { return v.begin(); }

			constexpr typename std::array<S,N>::const_iterator
			cbegin() const { return v.cbegin(); }

			constexpr typename std::array<S,N>::const_iterator
			cend() const { return v.cbegin(); }

			constexpr size_t
			size() const { return N; }

		public: //functions
			S
			length() const
			{
				S ret{};
				for (size_t i = 0; i < N; i++)
					ret = ret + v[i]*v[i];
				return sqrt(ret);
			}

			void
			normalize()
			{
				S len = length();
				for (size_t i = 0; i < N; i++)
					v[i] = v[i]/len;
			}

		public: //friends
			template<class T, unsigned K>
			friend Point<T,K> operator*(T,Point<T,K> const&);

		};

		template<class S, unsigned N>
		S dot(Point<S,N> a, Point<S,N> b)
		{
			S ret{};
			for (size_t i = 0; i < N; i++)
				ret = ret + a.v[i] * b.v[i];
			return ret;
		}

		template<class S>
		Point<S,3> cross(Point<S,3> lhs, Point<S,3> rhs)
		{
			Point<S,3> ret;

			ret[0] = lhs[1]*rhs[2] - lhs[2]*rhs[1];
			ret[1] = lhs[2]*rhs[0] - lhs[0]*rhs[2];
			ret[2] = lhs[0]*rhs[1] - lhs[1]*rhs[0];
			
			return ret;
		}

		template<class S, unsigned N>
		Point<S,N> operator*(S k, Point<S,N> const& p) { return p*k; }
	}

	typedef Math::Point<float,2> Point2;
	typedef Math::Point<float,3> Point3;

}

#endif