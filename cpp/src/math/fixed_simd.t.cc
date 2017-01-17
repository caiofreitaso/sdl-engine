#include <game-engine/math/fixed_simd.h>
#include <iostream>
#include <chrono>

int main(int argc, char const *argv[])
{
	auto start = std::chrono::system_clock::now();
	{
		Engine::Math::fixed<Engine::Math::INT32,12> *a, *b;
		a = new Engine::Math::fixed<Engine::Math::INT32,12>[36];
		b = new Engine::Math::fixed<Engine::Math::INT32,12>[36];
		for (int i = 0; i < 36; i++)
			a[i] = b[i] = i;

		Engine::SIMD::mul(a,b,a,36);
		for (int i = 0; i < 36; i++)
			std::cout << a[i] << " ";
		std::cout << std::endl;
	}
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> t = end-start;
	std::cout << t.count() << std::endl;

	return 0;
}