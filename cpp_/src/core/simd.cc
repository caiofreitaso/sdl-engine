#include <game-engine/core/simd.h>

namespace {
	struct CPU_ID {
		std::bitset<32> ecx1;
		std::bitset<32> edx1;
		std::bitset<32> ebx7;
		std::bitset<32> ecx7;

		CPU_ID()
		: ecx1{0}, edx1{0}, ebx7{0}, ecx7{0}
		{
			#ifdef _MSC_VER
			std::vector<std::vector<int>> data;
			
			std::vector<int> cpu_info(4,-1);

			__cpuid(cpu_info.data(), 0);

			int n_ids = cpu_info[0];
			for (int i = 0; i <= n_ids; i++)
			{
				__cpuidex(cpu_info.data(), i, 0);
				data.push_back(cpu_info);
			}

			if (n_ids >= 1)
			{
				ecx1 = data[1][2];
				edx1 = data[1][3];
			}

			if (n_ids >= 7)
			{
				ebx7 = data[7][1];
				ecx7 = data[7][2];
			}
			#else
			unsigned n_ids = __get_cpuid_max(0,0);
			unsigned eax,ebx,ecx,edx;
			if (n_ids >= 1)
			{
				__get_cpuid(1, &eax,&ebx,&ecx,&edx);
				ecx1 = ecx;
				edx1 = edx;
			}
			if (n_ids >= 7)
			{
				__get_cpuid(7, &eax,&ebx,&ecx,&edx);
				ebx7 = ebx;
				ecx7 = ecx;
			}
			#endif
		}

	} cpuid;
}

bool Engine::Processor::hasSSE() { return cpuid.edx1[25]; }
bool Engine::Processor::hasSSE2() { return cpuid.edx1[26]; }
bool Engine::Processor::hasSSE3() { return cpuid.ecx1[0]; }
bool Engine::Processor::hasSSE41() { return cpuid.ecx1[19]; }
bool Engine::Processor::hasSSE42() { return cpuid.ecx1[20]; }
bool Engine::Processor::hasSSSE3() { return cpuid.ecx1[9]; }
bool Engine::Processor::hasAVX() { return cpuid.ecx1[28]; }
bool Engine::Processor::hasAVX2() { return false; }//cpuid.ebx7[5]; }

int Engine::SIMD::strncmp(char* c, char* d, size_t len)
{
	if (c == d) return 0;

	size_t num_packets = len/16;
	size_t rest = len - num_packets*16;

	Packet<int,SSE> xmm0, xmm1;
	for (size_t i = 0; i < len-rest; i += 16)
	{
		xmm0.load((int*)&c[i]);
		xmm1.load((int*)&d[i]);
		int cmp = _mm_cmpistri(xmm0.simd,xmm1.simd,24);
		if (cmp < 16)
			return c[i+cmp] < d[i+cmp] ? -1 : 1;
	}
	if (rest)
	{
		xmm0.load((int*)&c[num_packets]);
		xmm1.load((int*)&d[num_packets]);
		int cmp = _mm_cmpestri(xmm0.simd,rest,xmm1.simd,rest,24);
		if (cmp < 16)
			return c[(len-rest)+cmp] < d[(len-rest)+cmp] ? -1 : 1;
	}

	return 0;
}