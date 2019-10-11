#include <game-engine/core/string.h>

Engine::String::String() noexcept
{
	m_data.heap = 0;
	m_data.capacity = 0;
	m_data.size = 0;
	setStack(0);
}

Engine::String::String(String const& s)
{
	if (s.isHeap())
		copyHeap(s.m_data.heap, s.m_data.capacity);
	else
		m_data = s.m_data;
}

Engine::String::String(Engine::String&& s) noexcept
{
	m_data = s.m_data;
	s.setStack(0);
}

Engine::String::String(const_ptr s)
: String(s, strlen(s))
{ }

Engine::String::String(const_ptr s, size_t len)
{
	m_data.heap = 0;
	m_data.capacity = 0;
	m_data.size = 0;
	if (len <= 24)
	{
		memcpy(m_data.stack, s, len);
		m_data.stack[23] = 24-len;
	}
	else
		copyHeap(s,len);
}

Engine::String::~String()
{
	if (isHeap())
		deleteHeap();
}

Engine::String::value_type&
Engine::String::operator[](size_t i)
{
	return *(begin() + i);
}


Engine::String::value_type const&
Engine::String::operator[](size_t i) const
{
	return *(cbegin() + i);
}

Engine::String&
Engine::String::operator=(value_type c)
{
	//delete itself
	if (isHeap())
		deleteHeap();

	//copy data
	m_data.stack[0] = c;
	m_data.stack[23] = 23;

	return *this;
}

Engine::String&
Engine::String::operator=(const_ptr s)
{
	size_t len = strlen(s);
	if (len <= 24)
	{
		memcpy(m_data.stack, s, len);
		m_data.stack[23] = 24-len;
	}
	else
		copyHeap(s,len);
	return *this;
}

Engine::String&
Engine::String::operator=(Engine::String&& s)
{
	//String tmp(s);
	m_data = s.m_data;
	return *this;
}

Engine::String&
Engine::String::operator=(String const& s)
{
	if (s.isHeap())
		copyHeap(s.m_data.heap, s.m_data.capacity);
	else
		m_data = s.m_data;
	return *this;
}

Engine::String&
Engine::String::operator+=(String const& s)
{
	return append(s);
}

Engine::String&
Engine::String::operator+=(const_ptr s)
{
	return append(s);
}

Engine::String&
Engine::String::operator+=(value_type c)
{
	push_back(c);
	return *this;
}

Engine::String
Engine::String::operator+(String const& s) const
{
	return String(*this).append(s);
}

Engine::String
Engine::String::operator+(const_ptr s) const
{
	return String(*this).append(s);
}

Engine::String
Engine::String::operator+(value_type s) const
{
	return String(*this).append(s);
}


bool
Engine::String::operator==(String const& s) const
{
	return compare(*this,s) == 0;
}

bool
Engine::String::operator==(const_ptr s) const
{
	return compare(*this,s) == 0;
}

bool
Engine::String::operator!=(String const& s) const
{
	return compare(*this,s) != 0;
}

bool
Engine::String::operator!=(const_ptr s) const
{
	return compare(*this,s) != 0;
}

bool
Engine::String::operator<(String const& s) const
{
	return compare(*this,s) < 0;
}

bool
Engine::String::operator<(const_ptr s) const
{
	return compare(*this,s) < 0;
}

bool
Engine::String::operator>(String const& s) const
{
	return compare(*this,s) > 0;
}

bool
Engine::String::operator>(const_ptr s) const
{
	return compare(*this,s) > 0;
}

bool
Engine::String::operator<=(String const& s) const
{
	return compare(*this,s) <= 0;
}

bool
Engine::String::operator<=(const_ptr s) const
{
	return compare(*this,s) <= 0;
}

bool
Engine::String::operator>=(String const& s) const
{
	return compare(*this,s) >= 0;
}

bool
Engine::String::operator>=(const_ptr s) const
{
	return compare(*this,s) >= 0;
}

Engine::String::iterator
Engine::String::begin()
{
	return isHeap() ? m_data.heap : &m_data.stack[0];
}

Engine::String::iterator
Engine::String::end()
{
	return begin()+size();
}

Engine::String::const_iterator
Engine::String::cbegin() const
{
	return isHeap() ? m_data.heap : &m_data.stack[0];
}

Engine::String::const_iterator
Engine::String::cend() const
{
	return cbegin()+size();
}

size_t
Engine::String::size() const
{
	size_t ret = m_data.size & sizeMask;
	return isHeap() ? ret : 24 - m_data.stack[23];
}

size_t
Engine::String::length() const
{
	return size();
}

size_t
Engine::String::capacity() const
{
	size_t ret = m_data.capacity;
	return isHeap() ? ret : 24;
}

Engine::String::const_ptr
Engine::String::data() const
{
	value_type *ptr = m_data.heap;
	return (isHeap()) ? ptr : &(m_data.stack[0]);
}

Engine::String::const_ptr
Engine::String::c_str() const
{
	return data();
}

Engine::String&
Engine::String::append(String const& s)
{
	return append(s.c_str(), s.size());
}

Engine::String&
Engine::String::append(value_type s)
{
	return append(&s, 1);
}

Engine::String&
Engine::String::append(const_ptr s)
{
	return append(s, strlen(s));
}

Engine::String&
Engine::String::append(const_ptr s, size_t n)
{
	if (capacity() < size() + n)
		increaseCap();

	strcat(begin()+size()-2,s);

	setSize(size()+n,isHeap());
	return *this;
}

size_t
Engine::String::find(String const& s, size_t pos1, size_t pos2) const
{
	return find(s.c_str(),pos1,pos2);
}

size_t
Engine::String::find(const_ptr s, size_t pos1, size_t pos2) const
{
	const_ptr ret = strpbrk(data() + pos1, s + pos2);

	return ret ? ret - data() : size();
}

size_t
Engine::String::find(value_type c, size_t pos) const
{
	value_type s[2] = {c,0};
	const_ptr ret = strpbrk(data() + pos, s);
	return ret ? ret - data() : size();
}

void
Engine::String::push_back(value_type c)
{
	if (capacity() < size() + 1)
		increaseCap();

	*(begin()+size()) = c;

	setSize(size()+1, isHeap());
}

int
Engine::String::compare(String const& s1, String const& s2,
                        size_t pos1, size_t pos2)
{
	return Engine::String::compare(s1.data(), s2.data(),
                                   pos1, s1.size(), pos2, s2.size());
}

int
Engine::String::compare(String const& s1, const_ptr s2,
                        size_t pos1, size_t pos2)
{
	return Engine::String::compare(s1.data(), s2, pos1, s1.size(),
                                   pos2, strlen(s2));
}

int
Engine::String::compare(const_ptr s1, String const& s2,
                        size_t pos1, size_t pos2)
{
	return Engine::String::compare(s1, s2.data(), pos1, strlen(s1),
                                   pos2, s2.size());
}

int
Engine::String::compare(const_ptr s1, const_ptr s2,
                        size_t pos1, size_t len1,
                        size_t pos2, size_t len2)
{
	size_t len = len1 > len2 ? len2 : len1;

	int ret = strncmp(s1 + pos1, s2 + pos2, len);

	return ret != 0 ? ret : (len1 > len2 ? 1 : (len1 < len2 ? -1 : 0));
}

bool
Engine::String::isHeap() const
{
	return ((m_data.stack[23] & heapMask) == heapMask);
}

void
Engine::String::deleteHeap()
{
	delete[] m_data.heap;
}

void
Engine::String::setStack(size_t s)
{
	if (isHeap()) deleteHeap();

	m_data.stack[23] = 24-s;
}

void
Engine::String::copyHeap(const_ptr s, size_t len)
{
	if (isHeap()) deleteHeap();

	m_data.heap = new value_type[len];
	m_data.capacity = len;

	setSize(len,true);

	memcpy(m_data.heap, s, len);
}

void
Engine::String::increaseCap()
{
	size_t nxt_cap = isHeap() ? nextCap() : 64;
	size_t nxt_sz = size();

	value_type *tmp = new value_type[nxt_cap];

	memcpy(tmp,begin(),size());

	if (isHeap()) deleteHeap();

	m_data.heap = tmp;
	m_data.capacity = nxt_cap;

	setSize(nxt_sz,true);
}

void
Engine::String::setSize(size_t s, bool heapSize)
{
	if (heapSize)
	{
		m_data.size = s;
		m_data.stack[23] = heapMask;
	}
	else
		m_data.stack[23] = 24-s;
}

size_t
Engine::String::nextCap() const
{
	return capacity() < 256 ? capacity()+64 : 3*capacity()/2;
}