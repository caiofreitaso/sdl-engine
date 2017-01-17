#pragma once
#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <ostream>
#include <algorithm>

namespace Engine {
	class String
	{
	public: //types
		typedef char value_type;
		typedef char* iterator;
		typedef char const* const_iterator;
		typedef char const* const_ptr;

	public: //ctors and dtor
		String() noexcept;
		String(String const&);
		String(String&&) noexcept;
		String(const_ptr);
		String(const_ptr, size_t);

		~String();

	public: //operators
		value_type& operator[](size_t);
		value_type const& operator[](size_t) const;

		String& operator=(value_type);
		String& operator=(const_ptr);
		String& operator=(String&&);
		String& operator=(String const&);

		String& operator+=(String const&);
		String& operator+=(const_ptr);
		String& operator+=(value_type);

		String operator+(String const&) const;
		String operator+(const_ptr) const;
		String operator+(value_type) const;

		bool operator==(String const&) const;
		bool operator==(const_ptr) const;

		bool operator!=(String const&) const;
		bool operator!=(const_ptr) const;

		bool operator<(String const&) const;
		bool operator<(const_ptr) const;

		bool operator>(String const&) const;
		bool operator>(const_ptr) const;

		bool operator<=(String const&) const;
		bool operator<=(const_ptr) const;

		bool operator>=(String const&) const;
		bool operator>=(const_ptr) const;

	public: //methods
		iterator begin();
		iterator end();

		const_iterator cbegin() const;
		const_iterator cend() const;

		size_t size() const;
		size_t length() const;
		size_t capacity() const;

		const_ptr data() const;
		const_ptr c_str() const;

		String& append(String const&);
		String& append(value_type);
		String& append(const_ptr);
		String& append(const_ptr, size_t);

		size_t find(String const&, size_t pos1 = 0, size_t pos2 = 0) const;
		size_t find(const_ptr, size_t pos = 0, size_t pos2 = 0) const;
		size_t find(value_type, size_t pos = 0) const;

		void push_back(value_type);

	public: //static methods
		static int compare(String const&, String const&, size_t pos1 = 0, size_t pos2 = 0);
		static int compare(String const&, const_ptr, size_t pos1 = 0, size_t pos2 = 0);
		static int compare(const_ptr, String const&, size_t pos1 = 0, size_t pos2 = 0);
		static int compare(const_ptr, const_ptr, size_t, size_t, size_t, size_t);

	private: //data
		union {
			value_type stack[24];

			struct {
				value_type *heap; //long-size = 8 bytes
				size_t capacity; //8 bytes
				size_t size; //8 bytes
			};
		} m_data;
	
	private: //constant
		constexpr static value_type heapMask = 0x20;
		constexpr static size_t sizeMask = ~((size_t)32 << (sizeof(size_t)-1)*8);
	
	private: //methods
		bool isHeap() const;
		void copyHeap(const_ptr, size_t);
		void increaseCap();
		void deleteHeap();
		void setStack(size_t);
		void setSize(size_t,bool);
		size_t nextCap() const;
	};
}

namespace std {
	template<class Char, class Traits>
	basic_ostream<Char,Traits>&
	operator<<(basic_ostream<Char,Traits>& o, Engine::String const& s)
	{ return o << s.data(); }
}
#endif
