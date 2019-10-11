#include <game-engine/core/simd.h>
#include <game-engine/core/string.h>
#include <iostream>
#include <chrono>

int main(int argc, char const *argv[])
{
	if(Engine::Processor::hasSSE())   std::cout << "hasSSE" << std::endl;
	if(Engine::Processor::hasSSE2())  std::cout << "hasSSE2" << std::endl;
	if(Engine::Processor::hasSSE3())  std::cout << "hasSSE3" << std::endl;
	if(Engine::Processor::hasSSE41()) std::cout << "hasSSE41" << std::endl;
	if(Engine::Processor::hasSSE42()) std::cout << "hasSSE42" << std::endl;
	if(Engine::Processor::hasSSSE3()) std::cout << "hasSSSE3" << std::endl;
	if(Engine::Processor::hasAVX())   std::cout << "hasAVX" << std::endl;
	if(Engine::Processor::hasAVX2())  std::cout << "hasAVX2" << std::endl;
	std::cout << std::endl;

	// for (int i = 0 ; i < length; i++)
	// 	std::cout << ref[i] << " ";
	// std::cout << std::endl;

	



	auto start = std::chrono::system_clock::now();
//	for (int i = 0; i < 1000000; i++)
	{
		int *a, *b;
		a = new int[36];
		b = new int[36];
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

	int size = 1024*1024*1024;
	{
		char *a,*b;
		a = new char[size];
		b = new char[size];
		for (int i = 0; i < size; i++)
			a[i] = b[i] = 'a';
		b[575] = 'b';
	start = std::chrono::system_clock::now();
		std::cout << ::strncmp(a,b,size) << std::endl;
	end = std::chrono::system_clock::now();
	}
	t = end-start;
	std::cout << t.count() << std::endl;

	{
		char *a,*b;
		a = new char[size];
		b = new char[size];
		for (int i = 0; i < size; i++)
			a[i] = b[i] = 'a';
		b[575] = 'b';
	start = std::chrono::system_clock::now();
		std::cout << Engine::SIMD::strncmp(a,b,size) << std::endl;
	end = std::chrono::system_clock::now();
	}
	t = end-start;
	std::cout << t.count() << std::endl;

	return 0;
}