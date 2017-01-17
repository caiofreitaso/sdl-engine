#pragma once
#ifndef CONTAINER_H
#define CONTAINER_H

namespace Engine {

	template<class T>
	constexpr size_t type_size(T c) { return sizeof(typename T::value_type); }

	template<class T>
	constexpr size_t byte_length(T c) { return type_size(c) * c.size(); }


}

#endif