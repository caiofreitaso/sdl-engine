#include <game-engine/engine.h>

namespace { Engine::Graphics::Scene* m_scene = nullptr; }

void
Engine::setScene(Graphics::Scene* s)
{
	m_scene = s;
	startScene();
}

void
Engine::quitScene()
{
	m_scene = nullptr;
	endScene();
}

void
Engine::loop()
{
	while(!isGameFinished())
	{
		if (m_scene != nullptr)
		{
			update(m_scene->handler);
			m_scene->update(IO::state());
			render(m_scene->camera,m_scene->VAO,m_scene->objects);
		}
		else
			update(Graphics::Scene::nop_handler);
	}
}

void
Engine::loopOMP()
{
	#pragma omp parallel
	{
		#pragma omp master
		Engine::Graphics::renderLoop();

		#pragma omp single
		Engine::IO::inputLoop();
	}
}

void
Engine::IO::update(std::function<void(State const&, SDL_Event)> f)
{
	for (SDL_Event e; SDL_PollEvent(&e); )
		switch(e.type)
		{
			case SDL_WINDOWEVENT:
			case SDL_QUIT:
			case SDL_KEYDOWN:
			case SDL_KEYUP:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
			case SDL_MOUSEWHEEL:
				handleEvent(e);
				break;
			default:
				f(state(), e);
				break;
		}
}

void
Engine::IO::inputLoop()
{
	for (unsigned t = SDL_GetTicks(); !isGameFinished(); t = SDL_GetTicks())
	{

		if (m_scene != nullptr)
		{
			update(m_scene->handler);
			m_scene->update(state());
		}
		else
			update(Graphics::Scene::nop_handler);

		unsigned diff = SDL_GetTicks() - t;
		if (diff < settings().event_delay) 
			SDL_Delay(settings().event_delay - diff);
	}
}

void
Engine::Graphics::renderLoop()
{
	while(!isGameFinished())
	{
		if (m_scene != nullptr)
		{
			render(m_scene->camera,m_scene->VAO,m_scene->objects);

			if (Graphics::diff() < settings().render_delay)
				SDL_Delay(settings().render_delay - Graphics::diff());
		}
	}
}