#pragma once
#ifndef SPARSE_H
#define SPARSE_H

#include <cstddef>
#include <algorithm>
#include <iterator>
#include <vector>
#include <game-engine/math/util.h>

//Sparse SYMMETRIC Matrix
//Stores only the upper triangular matrix
//Useful for non-directed graphs

namespace Engine {

//rotate & pop_back
//O(n) & O(1)
template<class U>
void rotate_pop(std::vector<U>& v, size_t pos)
{
	std::rotate(v.begin() + pos, v.begin() + pos + 1, v.end());
	v.pop_back();
}

}

namespace Engine { namespace Math {

/* Symmetric sparse matrix
 *
 * Represents the matrix as three lists:
 * (a) an ordered array of values
 * (b) an ordered array of row indices for each value
 * (c) an ordered array of columns' start positions
 *
 * Example
 * =======
 *
 * For the matrix
 * 
 *     0 1 2
 * M = 1 3 0
 *     2 0 5
 *
 * Sparse would store
 *
 * (a) m_values  = 1 3 2 5
 * (b) m_indices = 0 1 0 2
 * (c) m_columns = 0 0 2
 *
 */
template<class T>
class Sparse {
public:
	static const int OK = 0;
	static const int OUT_OF_BOUNDS = -1;
	static const int UNKNOWN = -2;

	Sparse(Sparse&& s) noexcept :
	m_values(std::move(s.m_values)),
	m_indices(std::move(s.m_indices)),
	m_columns(std::move(s.m_columns))
	{
	}


	Sparse(Sparse const& s) :
	m_values(s.m_values),
	m_indices(s.m_indices),
	m_columns(s.m_columns)
	{
	}

	Sparse(size_t side) :
	m_values(Engine::Math::lcm(64,sizeof(T))),
	m_indices(Engine::Math::lcm(64,sizeof(T))),
	m_columns(side)
	{
	}

	Sparse() :
	m_values(Engine::Math::lcm(64,sizeof(T))),
	m_indices(Engine::Math::lcm(64,sizeof(T))),
	m_columns(0)
	{
	}

	size_t size() const { return m_values.size(); }
	size_t side() const { return m_columns.size(); }

	//It adds another row and column to the matrix,
	//and places it as the last row/column
	//O(1)
	void increase() { m_columns.push_back(m_values.size()); }

	//puts a non-zero value in the correct position
	//or deletes the value if the value is non-zero
	//O(n)
	int
	set(size_t i, size_t j, T value)
	{
		if (i > side() || j > side())
			return OUT_OF_BOUNDS;

		if (i > j)
			std::swap(i,j);

		u_iter begin = m_indices.begin() + m_columns[j];
		u_iter end   = index_end(j);

		//O(log2(n))
		begin = std::lower_bound(begin, end, i);

		//if there is already a non-zero value for this element
		if (begin != end)
		{
			auto index = std::distance(m_indices.begin(), begin);
			
			//remove value and index if new value is zero
			if (value == T())
			{
				rotate_pop(m_indices, index);
				rotate_pop(m_values, index);
			}
			else
				m_values[index] = value;
		}

		//do nothing if new value is zero, else
		if (value != T())
		{
			begin = m_indices.begin() + m_columns[j];

			//go to the value's biggest neighbor
			for (; begin != end && *begin < i; begin++)
				;

			auto index = std::distance(m_indices.begin(),begin);

			//add value & index
			m_values.push_back(value);
			m_indices.push_back(i);

			//then rotate all arrays
			//O(n)
			std::rotate(m_values.begin() + index,
						m_values.end() - 1,
						m_values.end());

			//O(n)
			std::rotate(m_indices.begin() + index,
						m_indices.end() - 1,
						m_indices.end());

			//update column start indices
			size_t next_start = j < side()-1 ? m_columns[j+1] : size();
			
			if (m_columns[j] == next_start)
				m_columns[j] = index;

			//O(n)
			for (size_t k = j+1; k < side(); k++)
				m_columns[k]++;;
		}
		return OK;
	}

	//deletes an entire column/row
	//O(n log2(n))
	int
	del(size_t j)
	{
		if (j > side())
			return OUT_OF_BOUNDS;

		size_t i, k;
		u_iter begin, end;

		//shift values from columns of index greater than j
		//O(n log2(n))
		for (i = side()-1; i > j; i--)
		{
			begin = m_indices.begin() + m_columns[i];
			end   = index_end(i);

			//O(log2(n))
			begin = std::lower_bound(begin, end, j);
		
			//if there is a 'j' referenced
			if (begin != end)
			{
				auto index = std::distance(m_indices.begin(), begin);

				//O(n)
				rotate_pop(m_indices, index);
				rotate_pop(m_values, index);

				if (index == m_columns[i])
					k = i;
				else
					k = i+1;

				for(; k < side(); k++)
					m_columns[k]--;
			}
		}

		//then delete and shift the values of the column j
		begin = m_indices.begin() + m_columns[j];
		end = index_end(j);

		//if there are elements aij, where i <= j
		if (begin != end)
		{
			m_indices.erase(begin, end);

			auto vbegin = m_values.begin() + std::distance(m_indices.begin(), begin);
			auto vend = m_values.begin() + std::distance(m_indices.begin(), end);
			
			m_values.erase(vbegin, vend);
			
			for(k = i+1; k < side(); k++)
				m_columns[k] -= std::distance(vbegin, vend);
		}

		//O(n)
		rotate_pop(m_columns, j);

		//O(n)
		for (auto& index : m_indices)
			if (index > j)
				index--;

		return OK;
	}

	//returns the value for Aij
	//O(log2(n))
	T
	operator()(size_t i, size_t j) const
	{
		if (i > j)
			std::swap(i,j);

		u_citer begin = m_indices.begin() + m_columns[j];
		u_citer end = index_end(j);

		//O(log2(n))
		begin = std::lower_bound(begin, end, i);

		if (begin != end)
			return m_values[begin - m_indices.begin()];
		return T();
	}

private:
	typedef typename std::vector<T>::iterator v_iter;
	typedef typename std::vector<size_t>::iterator u_iter;
	typedef typename std::vector<size_t>::const_iterator u_citer;

	u_iter
	index_end(size_t j)
	{
		if (j < side()-1)
			return m_indices.begin() + m_columns[j+1];
		else
			return m_indices.end();
	}

	u_citer
	index_end(size_t j) const
	{
		if (j < side()-1)
			return m_indices.begin() + m_columns[j+1];
		else
			return m_indices.end();
	}

private:
	std::vector<T> m_values;
	std::vector<size_t> m_indices;
	std::vector<size_t> m_columns;
};

}}

#endif
