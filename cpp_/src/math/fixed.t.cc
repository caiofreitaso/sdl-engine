#include <game-engine/math/fixed.h>
#include <iostream>
#include <bitset>


int main(int argc, char const *argv[])
{
	Engine::Math::Fixed a(0.5);
	Engine::Math::Fixed b(2);
	std::bitset<32> mask(Engine::Math::Fixed::MASK);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << (a/b) << std::endl;
	std::cout << (b/a) << std::endl;
	std::cout << (a*b) << std::endl;
	std::cout << (b*a) << std::endl;
	std::cout << (a+b) << std::endl;
	std::cout << (b+a) << std::endl;
	std::cout << (a-b) << std::endl;
	std::cout << (b-a) << std::endl;
	std::cout << sqrt(b) << std::endl << std::endl;

	std::cout << "FIXED-POINT TEST" << std::endl;
	std::cout << (Engine::Math::Fixed::SIGNED ? "signed " : "unsigned ");
	std::cout << Engine::Math::Fixed::BITS << "bit w/ ";
	std::cout << Engine::Math::Fixed::PRECISION << "bit precision" << std::endl;
	std::cout << "Precision mask = " << mask << std::endl;

	std::cout << "STD::IS_CONVERTIBLE" << std::endl;
	std::cout << "double: " << std::is_convertible<double, Engine::Math::Fixed>::value << std::endl;
	std::cout << "float: " << std::is_convertible<float, Engine::Math::Fixed>::value << std::endl;
	std::cout << "unsigned: " << std::is_convertible<unsigned, Engine::Math::Fixed>::value << std::endl;

	return 0;
}