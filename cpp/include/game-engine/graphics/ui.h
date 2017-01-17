#pragma once
#ifndef UI_H
#define UI_H

#include <vector>

#include <game-engine/core/string.h>
#include <game-engine/math/fixed.h>

namespace Engine { namespace UI {
	typedef Math::fixed<Math::UINT16,10> Percent;

	enum Format
	{
		RIGHT,
		CENTERED,
		LEFT
	};

	enum State
	{
		NORMAL,
		ONFOCUS,
		CLICKED,
	};

	struct Font
	{
		String name;
		Percent size;
	};

	struct Label
	{
		Percent x;
		Percent y;
		
		Font font;
	};

	struct Button
	{
		Percent x;
		Percent y;
		Percent width;
		Percent height;

		Label font;
		String text;
		struct {
			unsigned char top;
			unsigned char bottom;
			unsigned char left;
			unsigned char right;
		} padding;

		String texture[3];

		unsigned char state;
	};

	struct Slider
	{
		Percent x;
		Percent y;
		Percent width;
		Percent height;
		
		Percent length;
		
		unsigned minimum;
		unsigned maximum;
		unsigned step;
		unsigned value;

		String texture[3];

		unsigned char state;
	};

	struct BaseWidget
	{
		unsigned char type;
		union {
			Label label;
			Button button;
			Slider slider;
		};
	};

	struct BasePanel
	{
		Percent x;
		Percent y;
		Percent width;
		Percent height;
		
		std::vector<BaseWidget> container;
	};

}}

#endif