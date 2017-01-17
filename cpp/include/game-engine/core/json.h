#pragma once
#ifndef JSON_H
#define JSON_H

#include <vector>
#include <type_traits>
#include <ostream>
#include <fstream>
#include <game-engine/core/string.h>
#include <game-engine/core/map.h>

namespace Engine { namespace JSON {
	class Value;
	
	typedef Map<String, Value> Object;
	typedef std::vector<Value> Array;
	
	class Value
	{
	public: //types
		enum Type {
			BOOLEAN,
			NUMBER,
			STRING,
			OBJECT,
			ARRAY
		};

	public: //ctors & dtor
		Value();
 		Value(Value const&);
		Value(Value&&);

		template<class T, typename std::enable_if<std::is_nothrow_assignable<double&, T>::value, int>::type D = 0>
		Value(T s)
		: _type(NUMBER), number(s)
		{ }

		Value(String);
		Value(bool);
		Value(Array);
		Value(Object);

		~Value();

	public: //operators
		template<class T, typename std::enable_if<std::is_nothrow_assignable<double&, T>::value, int>::type D = 0>
		Value& operator=(T s)
		{
			reset();
			_type = NUMBER;
			number = s;
		}

		Value& operator=(bool);
		Value& operator=(String);
		Value& operator=(char);
		Value& operator=(const char*);
		Value& operator=(std::nullptr_t);
		Value& operator=(Array);
		Value& operator=(Object);
		Value& operator=(Value const&);
		
	public: //methods
		Type type() const;

		bool& getBool();
		Object* getObject();
		Array& getArray();
		double& getNumber();
		String& getString();

		bool const& getBool() const;
		Array const& getArray() const;
		String const& getString() const;
		double const& getNumber() const;
		const Object* getObject() const;

		String serialize() const;

	private: //data
		Type _type;
		union
		{
			String  string;
			double  number;
			void*   object;
			bool   boolean;
		};

	private: //methods
		void reset();
	};

	Value parse(std::istream&);
}}

namespace std {
	template<class Char, class Traits>
	basic_ostream<Char,Traits>&
	operator<<(basic_ostream<Char,Traits>& o, Engine::JSON::Value const& s)
	{
		switch(s.type())
		{
			case Engine::JSON::Value::BOOLEAN: return o << s.getBool();
			case Engine::JSON::Value::NUMBER: return o << s.getNumber();
			case Engine::JSON::Value::STRING: return o << s.getString();
			case Engine::JSON::Value::OBJECT: return o << s.getObject();
			case Engine::JSON::Value::ARRAY: return o << s.getArray();
		}
	}

	template<class Char, class Traits>
	basic_ostream<Char,Traits>&
	operator<<(basic_ostream<Char,Traits>& o, Engine::JSON::Object const& s)
	{
		o << "{";
		for (auto i = s.begin(); i != s.end(); i++)
		{
			o << i->key << ": ";
			switch(i->value.type())
			{
				case Engine::JSON::Value::BOOLEAN: i->value.getBool() ? o << "true" : o << "false"; break;
				case Engine::JSON::Value::NUMBER: o << i->value.getNumber(); break;
				case Engine::JSON::Value::STRING: o << "\"" << i->value.getString() << "\""; break;
				case Engine::JSON::Value::OBJECT: o << *i->value.getObject(); break;
				case Engine::JSON::Value::ARRAY: o << i->value.getArray(); break;
			}
			if (i == s.end()-1)
				o << "}";
			else
				o << ", ";
		}
		return o;
	}

	template<class Char, class Traits>
	basic_ostream<Char,Traits>&
	operator<<(basic_ostream<Char,Traits>& o, Engine::JSON::Array const& s)
	{
		if (s.size() == 0)
			return o << "[]";

		o << "[";
		for (auto i = s.begin(); i != s.end(); i++)
		{
			switch(i->type())
			{
				case Engine::JSON::Value::BOOLEAN: i->getBool() ? o << "true" : o << "false"; break;
				case Engine::JSON::Value::NUMBER: o << i->getNumber(); break;
				case Engine::JSON::Value::STRING: o << "\"" << i->getString() << "\""; break;
				case Engine::JSON::Value::OBJECT: o << *i->getObject(); break;
				case Engine::JSON::Value::ARRAY: o << i->getArray(); break;
			}
			if (i == s.end()-1)
				o << "]";
			else
				o << ", ";
		}
		return o;
	}
}

#endif