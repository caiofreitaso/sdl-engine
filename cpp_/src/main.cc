#include <game-engine/engine.h>

int main(int argc, char const *argv[])
{
	Engine::IO::initSettings("graphics.ini");
	
	if (!Engine::IO::initSDL("TEST"))
	{
		Engine::Graphics::initGL();

		{
			Engine::Graphics::Scene s;

			Engine::setScene(&s);
			Engine::loopOMP();
		}

		std::cout << "TEST" << std::endl;

		Engine::quit();
	}
	return 0;
}