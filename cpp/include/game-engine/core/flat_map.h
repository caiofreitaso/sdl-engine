#pragma once
#ifndef FLATMAP_H
#define FLATMAP_H

#include <vector>
#include <algorithm>
#include <cstdlib>

namespace Engine {
	template<class Key, class T>
	class Map
	{
		std::vector<Pair> _data;

	public:
		struct Pair
		{
			Key key;
			T value;

			bool operator<(Pair const& r) const { return this->key < r.key; }
			bool operator<(Key const& r) const { return this->key < r; }
		};

		typedef iter std::vector<Pair>::iterator;
		typedef citer std::vector<Pair>::const_iterator;

		iter  begin() { return _data.begin(); }
		iter  end()   { return _data.end(); }
		citer begin() const { return _data.begin(); }
		citer end()   const { return _data.end(); }

		bool empty() const { return _data.empty(); }
		size_t size() const { return _data.size(); }

		iter insert(Pair const& v)
		{
			iter pos = std::lower_bound(_data.begin(),_data.end(),v);
			if (pos->key == v.key)
			{
				pos->value = v.value;
				return pos;
			}
			else
				return _data.insert(pos, v);
		}

		void erase(iter i) { _data.erase(i); }
		void erase(Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(),_data.end(),k);
			if (pos->key == k)
				_data.erase(pos);
		}

		void clear() { _data.clear(); }
		void swap(Map& r) { _data.swap(r._data); }

		T& operator[](Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos->key == k)
				return pos->value;
			else
				return _data.insert(pos,Pair{k,T()})->value;
		}

		iter find(Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos->key == k)
				return pos;
			return end();
		}

		citer find(Key const& k) const
		{
			citer pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos->key == k)
				return pos;
			return end();
		}
	};
}

#endif
