#include <game-engine/settings.h>

namespace {
	boost::program_options::options_description generic("Generic options");
	boost::program_options::options_description config("Configuration options");

	Engine::Settings m_settings =
		{ 1024, 768, Engine::WINDOW, false, 1.0, false, 100.0, 800.0, 1.0, 16, 1 };
}

Engine::Settings const& Engine::settings() { return m_settings; }

void
Engine::IO::changeResolution(int w, int h)
{
	m_settings.video.width  = w;
	m_settings.video.height = h;
}

void
Engine::IO::initSettings(const char* file)
{
	static bool initialized = false;
	static bool fullscreen = false;
	static bool window = true;
	static bool borderless = false;

	if (!initialized)
	{
		generic.add_options()
		("help,h", "print usage message")
		("version,v", "print version string");

		config.add_options()
		//video options
		("video.width,vw", boost::program_options::value<int>(&m_settings.video.width)->default_value(1024), "Video width")
		("video.height,vh", boost::program_options::value<int>(&m_settings.video.height)->default_value(768), "Video height")
		("video.fullscreen,f", boost::program_options::value<bool>(&fullscreen)->default_value(false), "Set fullscreen view")
		("video.borderless,b", boost::program_options::value<bool>(&borderless)->default_value(false), "Set borderless windowed view")
		("video.window,w", boost::program_options::value<bool>(&window)->default_value(true), "Set windowed view")
		("video.vsync", boost::program_options::value<bool>(&m_settings.video.vsync), "Set V-Sync on")
		("video.gamma", boost::program_options::value<float>(&m_settings.video.gamma), "Set gamma value")

		//control options
		("controls.lock-mouse", boost::program_options::value<bool>(&m_settings.controls.lock_mouse), "Lock mouse inside window")
		("controls.cam-speed", boost::program_options::value<float>(&m_settings.controls.cam_speed), "Set camera speed for arrow keys")
		("controls.cam-scroll", boost::program_options::value<float>(&m_settings.controls.cam_scroll), "Set camera speed for mouse scroll")
		("controls.cam-drag", boost::program_options::value<float>(&m_settings.controls.cam_drag), "Set camera speed for mouse drag");
	}

	boost::program_options::variables_map variables;
	
	std::ifstream fstream;
	fstream.open(file);

	boost::program_options::store(boost::program_options::parse_config_file(fstream, config, true), variables);
	boost::program_options::notify(variables);

	fstream.close();

	if (fullscreen)
		m_settings.video.mode = FULLSCREEN;
	else if (borderless)
		m_settings.video.mode = BORDERLESS;
	else if (window)
		m_settings.video.mode = WINDOW;
}
