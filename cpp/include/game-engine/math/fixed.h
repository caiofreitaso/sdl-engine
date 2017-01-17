#pragma once
#ifndef FIXED_H
#define FIXED_H

#include <cstdint>
#include <tuple>
#include <type_traits>
#include <limits>
#include <iostream>

#include <game-engine/core/variadic.h>

//Fixed-Point Class
// (a) from 8-bit to 64-bit representation
// (b) prone to overflow
// (c) cannot take types different those from cstdint
// (d)
//
// Based on John McFarlane's proposal for <fixed_point>


namespace Engine { namespace Math {

	enum IntegerType
	{
		INT64  = -4,
		INT32  = -3,
		INT16  = -2,
		INT8   = -1,
		UINT8  = 1,
		UINT16 = 2,
		UINT32 = 3,
		UINT64 = 4
	};

	namespace {
		constexpr auto unsigned_family =
			std::make_tuple<std::uint8_t,std::uint16_t,std::uint32_t,std::uint64_t>(8,16,32,64);

		constexpr auto signed_family =
			std::make_tuple<std::int8_t,std::int16_t,std::int32_t,std::int64_t>(8,16,32,64);

		constexpr int abs(int x) { return x < 0 ? -x : x; }

		#define get_pure_type(a,b) typename pure_type<decltype(std::get<a>(b))>::type

		template<int I, bool Signed>
		struct typefit;

		template<int I>
		struct typefit<I, true>
		{
			using type = get_pure_type(I,signed_family);
			using next = get_pure_type(I+1,signed_family);
		};

		template<int I>
		struct typefit<I, false>
		{
			using type = get_pure_type(I,unsigned_family);
			using next = get_pure_type(I+1,unsigned_family);
		};

		#undef get_pure_type

		template<>
		struct typefit<3,true>
		{
			using type = std::int64_t;
			using next = std::int64_t;
		};

		template<>
		struct typefit<3,false>
		{
			using type = std::uint64_t;
			using next = std::uint64_t;
		};

		template<class T>
		constexpr T pow2(int power)
		{
			return (power >= 8
						? T(256) * pow2<T>(power-8)
						: power > 0
							? T(2) * pow2<T>(power-1)
							: power == 0
								? T(1)
								: power > -8
									? T(0.5) * pow2<T>(power+1)
									: T(0.00390625) * pow2<T>(power+8)
									);
		}
	}

	//32-bit Constants
	//Q2.30
	constexpr std::uint32_t PI_32 = 3373259426;
	constexpr std::uint32_t E_32 = 2918732888;

	//base class and number of precision bits.
	template<IntegerType B, unsigned P>
	class fixed
	{
	public: //types
		typedef typename typefit<abs(B)-1, B < 0>::type base;
		typedef typename typefit<abs(B)-1, B < 0>::next result_type;

	public: //constants
		static constexpr bool SIGNED = (B < 0);
		static constexpr unsigned PRECISION = P;
		static constexpr unsigned BITS = (sizeof(base) * 8);
		static constexpr base MASK = (~(-1 << P));
		static constexpr result_type ROUND = (1 << (P-1));

	public: //constructors
		constexpr fixed() : m_value(base()) {}
		constexpr fixed(fixed const& d) : m_value(d.m_value) {}
		fixed(fixed&& d) : m_value(std::move(d.m_value)) {}

		//copy from another fixed-type
		template<IntegerType Type, unsigned Precision,
		typename std::enable_if<(Precision != P), int>::type D = 0>
		constexpr fixed(fixed<Type,Precision> const& d) : m_value(convert(d)) {}

		//initialize from integer
		template<class I,
		typename std::enable_if<std::numeric_limits<I>::is_integer, int>::type D = 0>
		constexpr fixed(I d) : m_value(d << P) {}

		//initialize from floating point
		template<class F,
		typename std::enable_if<std::is_floating_point<F>::value, int>::type D = 0>
		constexpr fixed(F d) : m_value(d*pow2<F>(P)){}

		constexpr fixed(base b, int) : m_value(b) { }

	public: //operators
		constexpr fixed
		operator+(fixed rhs) const { return fixed(m_value + rhs.m_value, 0); }

		constexpr fixed
		operator-(fixed rhs) const { return fixed(m_value - rhs.m_value, 0); }

		constexpr fixed
		operator*(fixed rhs) const
		{ return fixed((base)((((result_type)m_value * rhs.m_value) + ROUND) >> P), 0); }

		constexpr fixed
		operator/(fixed rhs) const { return fixed(((result_type)m_value << P) / rhs.m_value, 0); }

		constexpr fixed
		operator<<(unsigned rhs) const { return fixed(m_value << rhs, 0); }

		constexpr fixed
		operator>>(unsigned rhs) const { return fixed(m_value >> rhs, 0); }

		constexpr bool
		operator<(fixed rhs) const { return m_value < rhs.m_value; }

		constexpr bool
		operator>(fixed rhs) const { return m_value > rhs.m_value; }

		constexpr bool
		operator<=(fixed rhs) const { return m_value <= rhs.m_value; }

		constexpr bool
		operator>=(fixed rhs) const { return m_value >= rhs.m_value; }

		constexpr bool
		operator==(fixed const& rhs) const { return m_value == rhs.m_value; }

		constexpr bool
		operator!=(fixed const& rhs) const { return m_value != rhs.m_value; }

		fixed&
		operator=(fixed const& rhs) { m_value = rhs.m_value; return *this; }

	public: //friends
		template<IntegerType TYPE, unsigned PBITS, typename std::enable_if<(PBITS < 24),int>::type D>
		friend std::ostream& operator<<(std::ostream& o, fixed<TYPE,PBITS> f);

		template<IntegerType TYPE, unsigned PBITS, typename std::enable_if<(PBITS > 23),int>::type D>
		friend std::ostream& operator<<(std::ostream& o, fixed<TYPE,PBITS> f);

	private:
		base m_value;
	};

	template<IntegerType TYPE, unsigned PBITS,
	typename std::enable_if<(PBITS < 24),int>::type D = 0>
	std::ostream& operator<<(std::ostream& o, fixed<TYPE,PBITS> f)
	{
		return (o << (((float)f.m_value) / pow2<float>(PBITS)));
	}

	template<IntegerType TYPE, unsigned PBITS,
	typename std::enable_if<(PBITS > 23),int>::type D = 0>
	std::ostream& operator<<(std::ostream& o, fixed<TYPE,PBITS> f)
	{
		return (o << (((double)f.m_value) / pow2<double>(PBITS)));
	}

	typedef fixed<UINT16, 5>  HalfFixed;
	typedef fixed<UINT32, 12> Fixed;
}}

template<Engine::Math::IntegerType B, unsigned P>
Engine::Math::fixed<B,P> sqrt(Engine::Math::fixed<B,P> s)
{
	Engine::Math::fixed<B,P> ret = s/2;
	Engine::Math::fixed<B,P> previous = s;

	for (typename Engine::Math::fixed<B,P>::base i = 0; previous != ret && i < 10; i++)
	{
		previous = ret;
		ret = (ret + s/ret) >> 1;
	}

	return ret;
}


#endif
