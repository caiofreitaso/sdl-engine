#include <game-engine/math/sparse.h>
#include <iostream>

template<class T>
void print_sparse(Engine::Math::Sparse<T> const& m)
{
	for (unsigned i = 0; i < m.side(); i++)
	{
		for (unsigned j = 0; j < m.side(); j++)
			std::cout << m(i,j) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
	Engine::Math::Sparse<unsigned> matrix(5);

	for (unsigned i = 0, k = 0; i < matrix.side(); i++)
		for (unsigned j = 0; j <= i; j++, k++)
			matrix.set(i,j,i);

	print_sparse(matrix);

	matrix.del(2);
	print_sparse(matrix);
	
	matrix.increase();
	print_sparse(matrix);

	matrix.increase();
	print_sparse(matrix);

	matrix.del(2);
	print_sparse(matrix);

	return 0;
}