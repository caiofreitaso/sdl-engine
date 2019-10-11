#include <game-engine/core/string.h>
#include <iostream>

int main(int argc, char const *argv[])
{
	Engine::String a = 3.0, b = "asd";

	std::cout << a.c_str() << std::endl;

	a = "asd";

	std::cout << a.c_str() << std::endl;

	std::cout << (a == b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;

	a += "ddqqqqd";

	std::cout << a.c_str() << std::endl;

	std::cout << (a == b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;

	std::cout << a.find("d") << std::endl;

	std::cout << a[3] << std::endl;

	a += "dddaaasssdddfffggghhhjjjkkklll";

	std::cout << a.data() << std::endl;

	std::cout << (a == b) << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;

	std::cout << "size: " << a.size() << ", length: " << a.length() << ", capacity: " << a.capacity() << std::endl;

	
	return 0;
}