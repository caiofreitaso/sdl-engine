#include <game-engine/math/point.h>
#include <iostream>
#include <chrono>

#define GET_TIME std::chrono::duration_cast<std::chrono::duration<double> >

int main(int argc, char const *argv[])
{
	Engine::Point2 a = {1,2};
	Engine::Point2 b = {3,4};
	Engine::Point2 c = {5,6};

	Engine::Point2 ab, ac, bc;

	std::cout << a[0] << "," << a[1] << std::endl;
	std::cout << b[0] << "," << b[1] << std::endl;
	std::cout << c[0] << "," << c[1] << std::endl << std::endl;


	std::cout << "SUM" << std::endl;

	ab = a + b;
	ac = a + c;
	bc = b + c;

	std::cout << ab[0] << "," << ab[1] << std::endl;
	std::cout << ac[0] << "," << ac[1] << std::endl;
	std::cout << bc[0] << "," << bc[1] << std::endl << std::endl;


	std::cout << "SUBTRACTION" << std::endl;

	ab = a - b;
	ac = a - c;
	bc = b - c;


	std::cout << ab[0] << "," << ab[1] << std::endl;
	std::cout << ac[0] << "," << ac[1] << std::endl;
	std::cout << bc[0] << "," << bc[1] << std::endl << std::endl;


	std::cout << "SCALAR MULTIPLICATION" << std::endl;

	ab = a * 3;
	ac = b * 3;
	bc = c * 3;

	std::cout << ab[0] << "," << ab[1] << std::endl;
	std::cout << ac[0] << "," << ac[1] << std::endl;
	std::cout << bc[0] << "," << bc[1] << std::endl << std::endl;


	std::cout << "SCALAR DIVISION" << std::endl;

	ab = a / 3000;
	ac = b / 3000;
	bc = c / 3000;

	std::cout << ab[0] << "," << ab[1] << std::endl;
	std::cout << ac[0] << "," << ac[1] << std::endl;
	std::cout << bc[0] << "," << bc[1] << std::endl << std::endl;


	std::cout << "DOT PRODUCT" << std::endl;

	std::cout << Engine::Math::dot(a,b) << std::endl;
	std::cout << Engine::Math::dot(a,c) << std::endl;
	std::cout << Engine::Math::dot(b,c) << std::endl << std::endl;


	std::cout << "LENGTH" << std::endl;
	std::cout << a.length() << std::endl;
	std::cout << b.length() << std::endl;
	std::cout << c.length() << std::endl << std::endl;
  

	auto t1 = std::chrono::high_resolution_clock::now();
	for (unsigned i = 0; i < -1; i++)
	{
		Engine::Point2 p1{i,i};
		Engine::Point2 p2{i/2,i/2};
		p1 = p1 + p2;
	}
	auto t2 = std::chrono::high_resolution_clock::now();

	std::cout << GET_TIME(t2-t1).count() << std::endl;

	return 0;
}