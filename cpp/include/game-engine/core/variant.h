#pragma once
#ifndef VARIANT_H
#define VARIANT_H

#include <game-engine/core/variadic.h>

namespace Engine {

template<class... Args>
class variant
{
	unsigned char m_state;
	unsigned char m_data[sizeof(typename largest<Args...>::type)];

private:
	template<size_t I, class T>
	struct alternative;

	template<size_t I, class... Rest>
	struct alternative<I, variant<Rest...>>;

}



}

#endif