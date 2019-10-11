#pragma once
#ifndef VARIADIC_H
#define VARIADIC_H

#include <type_traits>
//#include <iostream>

////////////////////
//      SAME
////////////////////

template<class T, class... Rest>
struct same {
	static constexpr bool value =
		same<Rest...>::value & std::is_same<T,typename same<Rest...>::first>::value;
	typedef T first;
};

template<class T>
struct same<T> {
	static constexpr bool value = true;
	typedef T first;
};

template<class T, class U>
struct same<T,U> {
	static constexpr bool value = std::is_same<T,U>::value;
	typedef T first;
};


////////////////////
//   CONVERTIBLE
////////////////////

template<class To, class From, class... Rest>
struct convertible {
	static constexpr bool value =
		convertible<To, Rest...>::value & std::is_convertible<From, To>::value;
};

template<class To, class From>
struct convertible<To, From> {
	static constexpr bool value = std::is_convertible<From, To>::value;
};

template<class T>
struct convertible<T,T> {
	static constexpr bool value = true;
};


////////////////////
//    PURE_TYPE
////////////////////

template<class T>
struct pure_type {
	typedef typename std::remove_const<typename std::remove_reference<T>::type>::type type;
};


////////////////////
//     LARGEST
////////////////////
template<class T, class... Rest>
struct largest {
	typedef std::conditional_t<(sizeof(T) > sizeof(typename largest<Rest...>::type)), T,
		typename largest<Rest...>::type> type;
};

template<class T, class U>
struct largest<T,U> {
	typedef std::conditional_t<(sizeof(T) > sizeof(U)), T, U> type;
};

template<class T>
struct largest<T> {
	typedef T type;
};


//PRINT
/*
template<class T, class... Rest>
void print_same(T a, Rest... r)
{
	std::cout << same<T,Rest...>::value << std::endl;
}

template<class T, class... Rest>
void print_convertible(T a, Rest... r)
{
	std::cout << convertible<T,Rest...>::value << std::endl;
}*/

#endif
