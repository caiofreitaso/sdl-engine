#include <game-engine/io/state.h>

namespace {
	bool m_quit = false;
	bool m_endScene = false;

	SDL_Window *m_window = nullptr;
	SDL_Surface *m_screen = nullptr;
	SDL_GLContext m_context = 0;

	Engine::IO::State m_state;
}

Engine::IO::State const& Engine::IO::state() { return m_state; }

void Engine::IO::swapWindow() { SDL_GL_SwapWindow(m_window); }

bool Engine::isSceneFinished() { return m_endScene; }
bool Engine::isGameFinished()  { return m_quit; }

void Engine::startScene() { m_endScene = false; }
void Engine::endScene()   { m_endScene = true; }

Engine::IO::Resolution
Engine::IO::windowSize()
{
	Engine::IO::Resolution ret;
	SDL_GetWindowSize(m_window, &ret.width, &ret.height);
	return ret;
}

float
Engine::IO::windowRatio()
{
	int w, h;
	SDL_GetWindowSize(m_window, &w, &h);
	return ((float) w)/h;
}

void
Engine::IO::handleEvent(SDL_Event e)
{
	switch(e.type)
	{
		case SDL_WINDOWEVENT:
			switch(e.window.event)
			{
				case SDL_WINDOWEVENT_RESIZED:
				case SDL_WINDOWEVENT_SIZE_CHANGED:
					changeResolution(e.window.data1, e.window.data2);
					break;
			}
			break;
		
		case SDL_QUIT:
			m_quit = true;
			m_endScene = true;
			break;
		
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			m_state.mod = e.key.keysym.mod;
			m_state.keys[e.key.keysym.scancode] = e.key.state;
			break;
		
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
			switch(e.button.button)
			{
				case SDL_BUTTON_LEFT:   m_state.mouse[0] = e.button.state; break;
				case SDL_BUTTON_MIDDLE: m_state.mouse[1] = e.button.state; break;
				case SDL_BUTTON_RIGHT:  m_state.mouse[2] = e.button.state; break;
			}
			m_state.clicks  = e.button.clicks;
			m_state.mouse_x = e.button.x;
			m_state.mouse_y = e.button.y;
			break;

		case SDL_MOUSEWHEEL:
			// if (e.wheel.direction == SDL_MOUSEWHEEL_FLIPPED)
			// 	m_state.scroll = -e.wheel.y;
			// else
				m_state.scroll = e.wheel.y;
			
			m_state.scroll_time = e.wheel.timestamp;
			break;
	}
}

int
Engine::IO::initSDL(const char* name)
{
	if (SDL_Init( SDL_INIT_VIDEO ) < 0)
	{
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return -1;
	}
	else
	{
		switch(settings().video.mode)
		{
			case FULLSCREEN:
				m_window = SDL_CreateWindow(name,
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				settings().video.width, settings().video.height,
				SDL_WINDOW_FULLSCREEN_DESKTOP);
				break;
			case WINDOW:
				m_window = SDL_CreateWindow(name,
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				settings().video.width, settings().video.height,
				SDL_WINDOW_OPENGL);
				break;
			case BORDERLESS:
				m_window = SDL_CreateWindow(name,
				SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
				settings().video.width, settings().video.height,
				SDL_WINDOW_BORDERLESS);
				break;
		}

		if (m_window == NULL)
		{
			std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			return -2;
		}
		else
		{
			SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
			
			m_screen  = SDL_GetWindowSurface(m_window);
			m_context = SDL_GL_CreateContext(m_window);

			return 0;
		}
	}
}

void
Engine::quit()
{
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
