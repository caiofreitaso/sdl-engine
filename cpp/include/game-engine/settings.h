#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H

#include <fstream>
#include <boost/program_options.hpp>

namespace Engine {
	enum WindowMode {
		FULLSCREEN,
		WINDOW,
		BORDERLESS
	};

	struct VideoSettings {
		int height;
		int width;
		WindowMode mode;
		bool vsync;
		float gamma;
	};

	struct ControlSettings {
		bool  lock_mouse;
		float cam_speed;
		float cam_scroll;
		float cam_drag;
	};

	struct Settings {
		VideoSettings video;
		ControlSettings controls;
		unsigned event_delay;
		unsigned render_delay;
	};

	Settings const& settings();
	
	namespace IO {
		void changeResolution(int, int);
		void initSettings(const char*);
	}
}

#endif