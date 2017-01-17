#include <iostream>
#include <type_traits>

template<class T>//, int Power, typename std::enable_if<(Power == 0), int>::type D = 0>
constexpr T pow2(int power)
{
	return (power >= 8
				? T(256) * pow2<T>(power-8)
				: power > 0
					? T(2) * pow2<T>(power-1)
					: power == 0
						? T(1)
						: power > -8
							? T(0.5) * pow2<T>(power+1)
							: T(0.00390625) * pow2<T>(power+8)
							);
}

int main(int argc, char const *argv[])
{
	std::cout << pow2<double>(12) << std::endl;
	return 0;
}