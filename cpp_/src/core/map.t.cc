#include <iostream>
#include <game-engine/core/map.h>
#include <game-engine/core/string.h>

int main(int argc, char const *argv[])
{
	Engine::Map<Engine::String, int> map;

	map["teste"] = 1;
	map["asd"] = 0;
	map["eee"] = 123;
	map.insert({"asdd",3});

	for (auto& i : map)
		std::cout << i.key << ": " << i.value << "; ";
	std::cout << std::endl;
	return 0;
}