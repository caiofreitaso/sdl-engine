#pragma once
#ifndef FIXED_SIMD_H
#define FIXED_SIMD_H

#include <game-engine/math/fixed.h>
#include <game-engine/core/simd.h>

namespace Engine { namespace SIMD {
	template<Math::IntegerType T, unsigned P>
	struct canMul<Math::fixed<T,P>>
	{
		static inline bool test(Size s) { return s != AVX; }
	};

	template<class T>
	inline constexpr char get_char(T const& v, const size_t i)
	{
		return ((char*)&v)[i];
	}

	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#define AS_2CHARS(a) get_char(int16_t(a),0), get_char(int16_t(a),1)
	#define AS_4CHARS(a) get_char(int32_t(a),0), get_char(int32_t(a),1), \
		get_char(int32_t(a),2), get_char(int32_t(a),3)
	#define AS_8CHARS(a) get_char(int64_t(a),0), get_char(int64_t(a),1), \
		get_char(int64_t(a),2), get_char(int64_t(a),3), \
		get_char(int64_t(a),4), get_char(int64_t(a),5), \
		get_char(int64_t(a),6), get_char(int64_t(a),7)
	#define _MM_SETR_EPI8(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,aa,ab,ac,ad,ae,af) { \
		char(a0),char(a1),char(a2),char(a3), \
		char(a4),char(a5),char(a6),char(a7), \
		char(a8),char(a9),char(aa),char(ab), \
		char(ac),char(ad),char(ae),char(af) }
	#define _MM_SETR_EPI16(a0,a1,a2,a3,a4,a5,a6,a7) { \
		AS_2CHARS(a0),AS_2CHARS(a1),AS_2CHARS(a2),AS_2CHARS(a3), \
		AS_2CHARS(a4),AS_2CHARS(a5),AS_2CHARS(a6),AS_2CHARS(a7) }
	#define _MM_SETR_EPI32(a0,a1,a2,a3) { \
		AS_4CHARS(a0),AS_4CHARS(a1),AS_4CHARS(a2),AS_4CHARS(a3) }
	#define _MM_SETR_EPI64(a0,a1) { AS_8CHARS(a0),AS_8CHARS(a1) }

	#define _MM_SET1_EPI16(a) { \
		AS_2CHARS(a),AS_2CHARS(a),AS_2CHARS(a),AS_2CHARS(a), \
		AS_2CHARS(a),AS_2CHARS(a),AS_2CHARS(a),AS_2CHARS(a) }
	#define _MM_SET1_EPI32(a) { AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a) }
	#define _MM_SET1_EPI64(a) { AS_8CHARS(a),AS_8CHARS(a) }

	#define _MM256_SETR_EPI32(a0,a1,a2,a3,a4,a5,a6,a7) { \
		AS_4CHARS(a0),AS_4CHARS(a1),AS_4CHARS(a2),AS_4CHARS(a3), \
		AS_4CHARS(a4),AS_4CHARS(a5),AS_4CHARS(a6),AS_4CHARS(a7) }
	#define _MM256_SETR_EPI64(a0,a1,a2,a3) { \
		AS_8CHARS(a0),AS_8CHARS(a1),AS_8CHARS(a2),AS_8CHARS(a3) }

	#define _MM256_SET1_EPI32(a) { \
		AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a), \
		AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a),AS_4CHARS(a) }
	#define _MM256_SET1_EPI64(a) {  AS_8CHARS(a),AS_8CHARS(a),AS_8CHARS(a),AS_8CHARS(a) }
	#else
	#define CHAR_AS_LONGLONG(a) (((long long)a) & 0xFF)
	#define SHORT_AS_LONGLONG(a) (((long long)a) & 0xFFFF)
	#define INT_AS_LONGLONG(a) (((long long)a) & 0xFFFFFFFF)
	#define LL_SETR_EPI8(a, b, c, d, e, f, g, h) \
		(CHAR_AS_LONGLONG(a)) | (CHAR_AS_LONGLONG(b) << 8) | \
		(CHAR_AS_LONGLONG(c) << 16) | (CHAR_AS_LONGLONG(d) << 24) | \
		(CHAR_AS_LONGLONG(e) << 32) | (CHAR_AS_LONGLONG(f) << 40) | \
		(CHAR_AS_LONGLONG(g) << 48) | (CHAR_AS_LONGLONG(h) << 56)
	#define LL_SETR_EPI16(a, b, c, d) \
		(SHORT_AS_LONGLONG(a)) | (SHORT_AS_LONGLONG(b) << 16) | \
		(SHORT_AS_LONGLONG(c) << 32) | (SHORT_AS_LONGLONG(d) << 48)
	#define LL_SETR_EPI32(a, b) \
		(INT_AS_LONGLONG(a)) | (INT_AS_LONGLONG(b) << 32)

	#define _MM_SETR_EPI16(a0,a1,a2,a3,a4,a5,a6,a7) \
		{ LL_SETR_EPI16(a0,a1,a2,a3),LL_SETR_EPI16(a4,a5,a6,a7) }
	#define _MM_SETR_EPI32(a0,a1,a2,a3) \
		{ LL_SETR_EPI32(a0,a1),LL_SETR_EPI32(a2,a3) }
	#define _MM_SETR_EPI64(a0,a1) { a0,a1 }

	#define _MM_SET1_EPI64(a) __m128i{ a,a }

	#define _MM256_SET1_EPI16(a) { \
		LL_SETR_EPI16(a,a,a,a),LL_SETR_EPI16(a,a,a,a), \
		LL_SETR_EPI16(a,a,a,a),LL_SETR_EPI16(a,a,a,a) }
	#define _MM256_SET1_EPI32(a) { \
		LL_SETR_EPI32(a,a),LL_SETR_EPI32(a,a), \
		LL_SETR_EPI32(a,a),LL_SETR_EPI32(a,a) }
	#define _MM256_SET1_EPI64(a) __m256i{ a,a,a,a }

	#endif

	template<unsigned P>
	struct Packet<Math::fixed<Math::INT32,P>,AVX>
	{
		union {
			__m256i simd;
			typename Math::fixed<Math::INT32,P>::base data[8];
		};

		static constexpr size_t size() { return 8; }

		void load(Math::fixed<Math::INT32, P> const* a) { simd = _mm256_loadu_si256((__m256i*)a); }
		void store(Math::fixed<Math::INT32, P>* a) const { _mm256_storeu_si256((__m256i*)a,simd); }

		Packet operator+(Packet rhs) const { return Packet{_mm256_add_epi32(simd,rhs.simd)}; }
		Packet operator-(Packet rhs) const { return Packet{_mm256_sub_epi32(simd,rhs.simd)}; }
		Packet operator*(Packet rhs) const
		{
			__m256i low,hi;
			low = _mm256_mul_epi32(_mm256_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0)),
				_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
			hi  = _mm256_mul_epi32(_mm256_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2)),
				_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

			low = _mm256_add_epi64(low, _MM256_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));
			hi  = _mm256_add_epi64(hi, _MM256_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));

			low = _mm256_srli_epi64(low,P);
			hi  = _mm256_srli_epi64(hi,P);

			return Packet{_mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(low),
				_mm256_castsi256_ps(hi), _MM_SHUFFLE(2,0,2,0)))};
		}

		Packet& operator+=(Packet rhs) { simd = _mm256_add_epi32(simd,rhs.simd); return *this; }
		Packet& operator-=(Packet rhs) { simd = _mm256_sub_epi32(simd,rhs.simd); return *this; }
		Packet& operator*=(Packet rhs)
		{
			__m256i low,hi;
			low = _mm256_mul_epi32(_mm256_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0)),
				_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
			hi  = _mm256_mul_epi32(_mm256_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2)),
				_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

			low = _mm256_add_epi64(low, _MM256_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));
			hi  = _mm256_add_epi64(hi, _MM256_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));

			low = _mm256_srli_epi64(low,P);
			hi  = _mm256_srli_epi64(hi,P);

			simd = _mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(low),
				_mm256_castsi256_ps(hi), _MM_SHUFFLE(2,0,2,0)));
			return *this;
		}
	};

	template<unsigned P>
	struct Packet<Math::fixed<Math::INT32,P>, SSE>
	{
		union {
			__m128i simd;
			typename Math::fixed<Math::INT32,P>::base data[4];
		};

		static constexpr size_t size() { return 4; }

		void load(Math::fixed<Math::INT32, P> const* a) { simd = _mm_loadu_si128((__m128i*)a); }
		void store(Math::fixed<Math::INT32, P>* a) const { _mm_storeu_si128((__m128i*)a,simd); }

		Packet operator+(Packet rhs) const { return Packet{_mm_add_epi32(simd,rhs.simd)}; }
		Packet operator-(Packet rhs) const { return Packet{_mm_sub_epi32(simd,rhs.simd)}; }
		Packet operator*(Packet rhs) const
		{
			__m128i low,hi;
			low = _mm_mul_epi32(_mm_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0)),
				_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
			hi  = _mm_mul_epi32(_mm_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2)),
				_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

			low = _mm_add_epi64(low, _MM_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));
			hi  = _mm_add_epi64(hi, _MM_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));

			low = _mm_srli_epi64(low,P);
			hi  = _mm_srli_epi64(hi,P);

			return Packet{_mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(low),
				_mm_castsi128_ps(hi), _MM_SHUFFLE(2,0,2,0)))};
		}

		Packet& operator+=(Packet rhs) { simd = _mm_add_epi32(simd,rhs.simd); return *this; }
		Packet& operator-=(Packet rhs) { simd = _mm_sub_epi32(simd,rhs.simd); return *this; }
		Packet& operator*=(Packet rhs)
		{
			__m128i low,hi;
			low = _mm_mul_epi32(_mm_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0)),
				_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
			hi  = _mm_mul_epi32(_mm_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2)),
				_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

			low = _mm_add_epi64(low, _MM_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));
			hi  = _mm_add_epi64(hi, _MM_SET1_EPI64((Math::fixed<Math::INT32,P>::ROUND)));

			low = _mm_srli_epi64(low,P);
			hi  = _mm_srli_epi64(hi,P);

			simd = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(low), _mm_castsi128_ps(hi),
				_MM_SHUFFLE(2,0,2,0)));
			return *this;
		}
	};
}}

#endif
