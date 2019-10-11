#pragma once
#ifndef MEMORY_H
#define MEMORY_H

#include <game-engine/core/map.h>

namespace Engine { namespace Memory {
	//Wrapper based on file extension
	void load(char const* file);

	//TTF files
	void loadFont(char const* file);
	//PNG files
	void loadTexture(char const* file);
	//WAV files
	void loadSound(char const* file);
	//MP3 files
	void loadMusic(char const* file);

	//
}}

#endif