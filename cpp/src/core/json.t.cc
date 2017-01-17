#include <iostream>
#include <game-engine/core/json.h>

int main(int argc, char const *argv[])
{
	Engine::JSON::Object obj;
	obj["asd"] = 3;
	obj["obj"] = Engine::JSON::Object();
	(*obj["obj"].getObject())["dd"] = true;
	(*obj["obj"].getObject())["ww"] = "123";
	(*obj["obj"].getObject())["qq"] = Engine::JSON::Array();

	std::cout << obj << std::endl;

	Engine::JSON::Value s = Engine::JSON::parse(std::cin);
	std::cout << s << " " << std::cin.fail() << std::endl;
	return 0;
}