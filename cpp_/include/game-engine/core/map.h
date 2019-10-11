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
	public: //types
		struct Pair
		{
			Key key;
			T value;

			bool operator<(Pair const& r) const { return this->key < r.key; }
			bool operator<(Key const& r) const { return this->key < r; }
		};

		typedef typename std::vector<Pair>::iterator iter;
		typedef typename std::vector<Pair>::const_iterator citer;

	public: //iterators
		iter  begin() { return _data.begin(); }
		iter  end()   { return _data.end(); }
		citer begin() const { return _data.begin(); }
		citer end()   const { return _data.end(); }

	public: //const methods
		bool empty() const { return _data.empty(); }
		size_t size() const { return _data.size(); }

	public: //non-const methods
		iter insert(Pair const& v)
		{
			iter pos = std::lower_bound(_data.begin(),_data.end(),v);
			if (pos != end())
				if (pos->key == v.key)
				{
					pos->value = v.value;
					return pos;
				}

			return _data.insert(pos, v);
		}

		void erase(iter i) { _data.erase(i); }
		void erase(Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(),_data.end(),k);
			if (pos != end())
				if (pos->key == k)
					_data.erase(pos);
		}

		void clear() { _data.clear(); }
		void swap(Map& r) { _data.swap(r._data); }

	public: //access methods
		T& operator[](Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos != end())
				if (pos->key == k)
					return pos->value;
			return _data.insert(pos,Pair{k,T()})->value;
		}

		iter find(Key const& k)
		{
			iter pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos != end())
				if (pos->key == k)
					return pos;
			return end();
		}

		citer find(Key const& k) const
		{
			citer pos = std::lower_bound(_data.begin(), _data.end(), k);
			if (pos != end())
				if (pos->key == k)
					return pos;
			return end();
		}
	private:
		std::vector<Pair> _data;
	};
}

#endif
