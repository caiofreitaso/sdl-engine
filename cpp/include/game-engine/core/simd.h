#pragma once
#ifndef SIMD_H
#define SIMD_H

#ifdef _MSC_VER
#include <intrin.h>
#else
#include <cpuid.h>
#include <x86intrin.h>
#endif
#include <bitset>
#include <vector>
#include <omp.h>
#include <thread>
#include <iostream>
//#include <functional>

namespace Engine {
	namespace Processor {
		bool hasSSE();
		bool hasSSE2();
		bool hasSSE3();
		bool hasSSE41();
		bool hasSSE42();

		bool hasSSSE3();

		bool hasAVX();
		bool hasAVX2();
	}

	namespace SIMD {
		enum Size {
			SSE = 16,
			AVX = 32
		};

		template<class T>
		inline void prefetch(T* s) { _mm_prefetch((char*)s, _MM_HINT_T0); }

		template<class T> struct canAdd { static inline bool test(Size s) { return false; } };
		template<class T> struct canSub { static inline bool test(Size s) { return false; } };
		template<class T> struct canMul { static inline bool test(Size s) { return false; } };
		template<class T> struct canDiv { static inline bool test(Size s) { return false; } };

		template<> struct canAdd<double> { static inline bool test(Size s) { return true; } };
		template<> struct canAdd<float> { static inline bool test(Size s) { return true; } };
		template<>
		struct canAdd<int>
		{
			static inline bool test(Size s) { return s == AVX ? Processor::hasAVX2() : true; }
		};

		template<> struct canSub<double> { static inline bool test(Size s) { return true; } };
		template<> struct canSub<float> { static inline bool test(Size s) { return true; } };
		template<>
		struct canSub<int>
		{
			static inline bool test(Size s) { return s == AVX ? Processor::hasAVX2() : true; }
		};

		template<> struct canMul<double> { static inline bool test(Size s) { return true; } };
		template<> struct canMul<float> { static inline bool test(Size s) { return true; } };
		template<>
		struct canMul<int>
		{
			static inline bool test(Size s)
			{
				return s == AVX ? Processor::hasAVX2() : Processor::hasSSE41();
			}
		};

		template<> struct canDiv<double> { static inline bool test(Size s) { return true; } };
		template<> struct canDiv<float> { static inline bool test(Size s) { return true; } };
		template<> struct canDiv<int>
		{
			static inline bool test(Size s)
			{
				return false;//s == AVX ? Processor::hasAVX2() : Processor::hasSSE41();
			}
		};

		template<class T, Size s>
		struct Packet;

		template<>
		struct Packet<float,AVX>
		{
			union {
				__m256 simd;
				float data[8];
			};

			static constexpr size_t size() { return 8; }

			void load(float const* a) { simd = _mm256_loadu_ps(a); }
			void store(float* a) const { _mm256_storeu_ps(a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm256_add_ps(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm256_sub_ps(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const { return Packet{_mm256_mul_ps(simd,rhs.simd)}; }

			Packet& operator+=(Packet rhs) { simd = _mm256_add_ps(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm256_sub_ps(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs) { simd = _mm256_mul_ps(simd,rhs.simd); return *this; }
		};

		template<>
		struct Packet<double,AVX>
		{
			union {
				__m256d simd;
				double data[4];
			};

			static constexpr size_t size() { return 4; }

			void load(double const* a) { simd = _mm256_loadu_pd(a); }
			void store(double* a) const { _mm256_storeu_pd(a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm256_add_pd(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm256_sub_pd(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const { return Packet{_mm256_mul_pd(simd,rhs.simd)}; }

			Packet& operator+=(Packet rhs) { simd = _mm256_add_pd(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm256_sub_pd(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs) { simd = _mm256_mul_pd(simd,rhs.simd); return *this; }
		};

		//AVX2
		template<>
		struct Packet<int,AVX>
		{
			union {
				__m256i simd;
				int data[8];
			};

			static constexpr size_t size() { return 8; }

			void load(int const* a) { simd = _mm256_loadu_si256((__m256i*)a); }
			void store(int* a) const { _mm256_storeu_si256((__m256i*)a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm256_add_epi32(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm256_sub_epi32(simd,rhs.simd)}; }
			//Packet operator/(Packet rhs) const { return Packet{_mm256_div_epi32(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const
			{
				__m256i low,hi;
				low = _mm256_mul_epi32(
						_mm256_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0))
						,_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
				hi  = _mm256_mul_epi32(
						_mm256_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2))
						,_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

				return Packet{_mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(low),
					_mm256_castsi256_ps(hi), _MM_SHUFFLE(2,0,2,0)))};
			}

			Packet& operator+=(Packet rhs) { simd = _mm256_add_epi32(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm256_sub_epi32(simd,rhs.simd); return *this; }
			//Packet& operator/=(Packet rhs) { simd = _mm256_div_epi32(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs)
			{
				__m256i low,hi;
				low = _mm256_mul_epi32(
						_mm256_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0))
						,_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
				hi  = _mm256_mul_epi32(
						_mm256_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2))
						,_mm256_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

				simd = _mm256_castps_si256(_mm256_shuffle_ps(_mm256_castsi256_ps(low),
					_mm256_castsi256_ps(hi), _MM_SHUFFLE(2,0,2,0)));
				return *this;
			}
		};

		template<>
		struct Packet<float,SSE>
		{
			union {
				__m128 simd;
				float data[4];
			};

			static constexpr size_t size() { return 4; }

			void load(float const* a) { simd = _mm_loadu_ps(a); }
			void store(float* a) const { _mm_storeu_ps(a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm_add_ps(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm_sub_ps(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const { return Packet{_mm_mul_ps(simd,rhs.simd)}; }
			Packet operator/(Packet rhs) const { return Packet{_mm_div_ps(simd,rhs.simd)}; }

			Packet& operator+=(Packet rhs) { simd = _mm_add_ps(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm_sub_ps(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs) { simd = _mm_mul_ps(simd,rhs.simd); return *this; }
			Packet& operator/=(Packet rhs) { simd = _mm_div_ps(simd,rhs.simd); return *this; }
		};

		//SSE2
		template<>
		struct Packet<double,SSE>
		{
			union {
				__m128d simd;
				double data[2];
			};

			static constexpr size_t size() { return 2; }

			void load(double const* a) { simd = _mm_loadu_pd(a); }
			void store(double* a) const { _mm_storeu_pd(a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm_add_pd(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm_sub_pd(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const { return Packet{_mm_mul_pd(simd,rhs.simd)}; }
			Packet operator/(Packet rhs) const { return Packet{_mm_div_pd(simd,rhs.simd)}; }
			
			Packet& operator+=(Packet rhs) { simd = _mm_add_pd(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm_sub_pd(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs) { simd = _mm_mul_pd(simd,rhs.simd); return *this; }
			Packet& operator/=(Packet rhs) { simd = _mm_div_pd(simd,rhs.simd); return *this; }
		};

		//SSE4.1
		template<>
		struct Packet<int,SSE>
		{
			union {
				__m128i simd;
				int data[4];
			};

			static constexpr size_t size() { return 4; }

			void load(int const* a) { simd = _mm_loadu_si128((__m128i*)a); }
			void store(int* a) const { _mm_storeu_si128((__m128i*)a,simd); }

			Packet operator+(Packet rhs) const { return Packet{_mm_add_epi32(simd,rhs.simd)}; }
			Packet operator-(Packet rhs) const { return Packet{_mm_sub_epi32(simd,rhs.simd)}; }
			//Packet operator/(Packet rhs) const { return Packet{_mm_div_epi32(simd,rhs.simd)}; }
			Packet operator*(Packet rhs) const
			{
				__m128i low,hi;
				low = _mm_mul_epi32(
						_mm_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0))
						,_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
				hi  = _mm_mul_epi32(
						_mm_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2))
						,_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

				return Packet{_mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(low),
					_mm_castsi128_ps(hi), _MM_SHUFFLE(2,0,2,0)))};
			}

			Packet& operator+=(Packet rhs) { simd = _mm_add_epi32(simd,rhs.simd); return *this; }
			Packet& operator-=(Packet rhs) { simd = _mm_sub_epi32(simd,rhs.simd); return *this; }
			//Packet& operator/=(Packet rhs) { simd = _mm_div_epi32(simd,rhs.simd); return *this; }
			Packet& operator*=(Packet rhs)
			{
				__m128i low,hi;
				low = _mm_mul_epi32(
						_mm_shuffle_epi32(simd,_MM_SHUFFLE(3,1,2,0))
						,_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(3,1,2,0)));
				hi  = _mm_mul_epi32(
						_mm_shuffle_epi32(simd,_MM_SHUFFLE(1,3,0,2))
						,_mm_shuffle_epi32(rhs.simd,_MM_SHUFFLE(1,3,0,2)));

				simd = _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(low), _mm_castsi128_ps(hi),
					_MM_SHUFFLE(2,0,2,0)));
				return *this;
			 }
		};

		template<class T, template<class X> class Op, template<class Y> class Test>
		void operation(T const* a, T const* b, T* dst, size_t size)
		{
			size_t packet_size = (Test<T>::test(AVX) ? 32 : 16)/sizeof(T);
			size_t num_packets = size/packet_size;
			size_t rest = size - num_packets*packet_size;
			int init = 0;

			if (Test<T>::test(AVX))
			{
				for (int i = 0; i < size-rest; i+=packet_size)
				{
					Packet<T,AVX> simd_a, simd_b;

					simd_a.load(&a[i]);
					simd_b.load(&b[i]);

					Op<Packet<T,AVX>>()(simd_a,simd_b).store(&dst[i]);
				}

				init = size-rest;
				packet_size = 4;
				num_packets = rest/packet_size;
				rest -= num_packets*packet_size;
			}

			if (Test<T>::test(SSE))
			{
				for (int i = init; i < size-rest; i+=packet_size)
				{
					Packet<T,SSE> simd_a, simd_b;

					simd_a.load(&a[i]);
					simd_b.load(&b[i]);

					Op<Packet<T,SSE>>()(simd_a,simd_b).store(&dst[i]);
				}
			}
			else
				rest = size;

			for (int i = size-rest; i < size; i++)
				dst[i] = Op<T>()(a[i],b[i]);
		}

		template<class T>
		void add(T const* a, T const* b, T* dst, size_t size)
		{
			operation<T,std::plus,canAdd>(a,b,dst,size);
		}

		template<class T>
		void sub(T const* a, T const* b, T* dst, size_t size)
		{
			operation<T,std::minus,canSub>(a,b,dst,size);
		}

		template<class T>
		void mul(T const* a, T const* b, T* dst, size_t size)
		{
			operation<T,std::multiplies,canMul>(a,b,dst,size);
		}

		template<class T>
		void div(T const* a, T const* b, T* dst, size_t size)
		{
			operation<T,std::multiplies,canDiv>(a,b,dst,size);
		}

		int strncmp(char*, char*, size_t);
	}
}

#endif
