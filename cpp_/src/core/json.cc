#include <game-engine/core/json.h>

namespace
{
	char peekWhitespace(std::istream&);
	char getWhitespace(std::istream&);
	std::nullptr_t setNull(std::istream&, bool&);
	bool setTrue(std::istream&, bool&);
	bool setFalse(std::istream&, bool&);
	char setChar(std::istream&, bool&);
	Engine::String setString(std::istream&, bool&);
	double setNumber(std::istream&, bool&);
	Engine::JSON::Value setValue(std::istream&, bool&);
	Engine::JSON::Object setObject(std::istream&, bool&);
	Engine::JSON::Array setArray(std::istream&, bool&);


	char
	peekWhitespace(std::istream& file)
	{
		char c = file.peek();
		while (c == ' ' || c == '\t' || c == '\r' || c == '\n')
		{
			file.get(c);
			c = file.peek();
		}
		return c;
	}

	char
	getWhitespace(std::istream& file)
	{
		char c;
		file.get(c);
		while (c == ' ' || c == '\t' || c == '\r' || c == '\n')
			file.get(c);
		return c;
	}

	std::nullptr_t
	setNull(std::istream& file, bool& error)
	{
		static const char str[5] = "null";
		char c;
		for (int i = 0; i < 5; i++)
		{
			file.get(c);
			if (c == str[i])
				continue;
			else
			{
				error = true;
				break;
			}
		}
		return nullptr;
	}

	bool
	setTrue(std::istream& file, bool& error)
	{
		static const char str[5] = "true";
		char c;
		for (int i = 0; i < 5; i++)
		{
			file.get(c);
			if (c == str[i])
				continue;
			else
			{
				error = true;
				break;
			}
		}
		return true;
	}

	bool
	setFalse(std::istream& file, bool& error)
	{
		static const char str[6] = "false";
		char c;
		for (int i = 0; i < 6; i++)
		{
			file.get(c);
			if (c == str[i])
				continue;
			else
			{
				error = true;
				break;
			}
		}
		return false;
	}

	char
	setChar(std::istream& file, bool& error)
	{
		char c;
		file.get(c);
		switch (c)
		{
			case '"':
			case '\\':
			case '/': return c;
			case 'b': return '\b';
			case 'f': return '\f';
			case 'n': return '\n';
			case 'r': return '\r';
			case 't': return '\t';
			default:
				error = true;
				return 0;
		}
	}

	Engine::String
	setString(std::istream& file, bool& error)
	{
		Engine::String ret;

		char c;
		file.get(c);

		if (c != '"')
			error = true;

		while (!error)
		{
			file.get(c);
			if (c == '"')
				break;
			else if (c == '\\')
			{
				ret += setChar(file,error);
				if (error)
					break;
			}
			else
				ret += c;
		}

		return ret;
	}

	double
	setNumber(std::istream& file, bool& error)
	{
		double ret;
		file >> ret;
		return ret;
	}

	Engine::JSON::Value
	setValue(std::istream& file, bool& error)
	{
		Engine::JSON::Value ret;

		char c = file.peek();

		switch (c)
		{
			case 'f': ret = setFalse(file, error); break;
			case 't': ret = setTrue(file, error); break;
			case 'n': ret = setNull(file, error); break;
			case '"': ret = setString(file, error); break;
			case '[': ret = setArray(file, error); break;
			case '{': ret = setObject(file, error); break;
			case '-':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0': ret = setNumber(file, error); break;
			default: error = true; break;
		}

		return ret;
	}

	Engine::JSON::Object
	setObject(std::istream& file, bool& error)
	{
		Engine::JSON::Object ret;

		char c;
		file.get(c); //{

		c = peekWhitespace(file);

		if (c == '"')
		{
			Engine::String a = setString(file, error);
			
			if (error)
				return ret;

			c = getWhitespace(file);

			if (c == ':')
			{
				peekWhitespace(file);
				ret[a] = setValue(file, error);
			}
			else
				error = true;

			if (error)
				return ret;
		}
		else
		{
			if (c != '}')
				error = true;
			return ret;
		}

		while(true)
		{
			c = peekWhitespace(file);

			if (c == ',')
			{
				file.get(c);
				c = peekWhitespace(file);

				if (c == '"')
				{
					Engine::String a = setString(file, error);
					
					if (error)
						return ret;

					getWhitespace(file);

					if (c == ':')
					{
						peekWhitespace(file);
						ret[a] = setValue(file, error);
					}
					else
						error = true;
				}
				else
					error = true;

				if (error)
					return ret;
			}
			else
			{
				if (c != '}')
					error = true;
				return ret;
			}
		}

		return ret;
	}

	Engine::JSON::Array
	setArray(std::istream& file, bool& error)
	{
		Engine::JSON::Array ret;

		char c;
		file.get(c); //[

		c = peekWhitespace(file);

		if (c != ']')
		{
			ret.push_back(setValue(file, error));

			if (error)
				return ret;
		}
		else
			return ret;

		while(true)
		{
			c = peekWhitespace(file);

			if (c == ',')
			{
				file.get(c);
				ret.push_back(setValue(file, error));
				
				if (error)
					return ret;
			}
			else
			{
				if (c != ']')
					error = true;
				return ret;
			}
		}

		return ret;
	}
}

Engine::JSON::Value::Value()
: _type(Value::OBJECT), object(nullptr)
{ }

Engine::JSON::Value::Value(Value const& a)
: _type(a._type)
{
	if (_type == OBJECT)
		object = new Object(*static_cast<Object*>(a.object));
	else if (_type == ARRAY)
		object = new Array(*static_cast<Array*>(a.object));
	else
		string = a.string;
}

Engine::JSON::Value::Value(Value&& a)
: _type(a._type), string(a.string)
{
	a.object = nullptr;
}

Engine::JSON::Value::Value(String s)
: _type(Value::STRING), string(s)
{ }

Engine::JSON::Value::Value(bool s)
: _type(Value::BOOLEAN), boolean(s)
{ }

Engine::JSON::Value::Value(Array s)
: _type(Value::ARRAY), object(new JSON::Array(s))
{ }

Engine::JSON::Value::Value(Object s)
: _type(Value::OBJECT), object(new JSON::Object(s))
{ }


Engine::JSON::Value::~Value() { reset(); }


void
Engine::JSON::Value::reset()
{
	if (object)
	{
		switch(_type)
		{
			case OBJECT: delete static_cast<Object*>(object); break;
			case ARRAY: delete static_cast<Array*>(object); break;
		}
		object = nullptr;
	}
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(Value const& a)
{
	reset();
	_type = a._type;
	if (_type == OBJECT)
		object = new Object(*static_cast<Object*>(a.object));
	else if (_type == ARRAY)
		object = new Array(*static_cast<Array*>(a.object));
	else
		string = a.string;
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(bool a)
{
	reset();
	_type = BOOLEAN;
	boolean = a;
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(String a)
{
	reset();
	_type = STRING;
	string = a;
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(char a)
{
	reset();
	_type = STRING;
	string = a;
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(const char* a)
{
	reset();
	_type = STRING;
	string = a;
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(Array a)
{
	reset();
	_type = ARRAY;
	object = new Array(a);
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(Object a)
{
	reset();
	_type = OBJECT;
	object = new Object(a);
}

Engine::JSON::Value&
Engine::JSON::Value::operator=(std::nullptr_t a)
{
	reset();
	_type = OBJECT;
	object = a;
}

Engine::JSON::Value::Type
Engine::JSON::Value::type() const
{
	return _type;
}


bool&
Engine::JSON::Value::getBool()
{
	return boolean;
}

Engine::JSON::Object*
Engine::JSON::Value::getObject()
{
	return static_cast<Object*>(object);
}

Engine::JSON::Array&
Engine::JSON::Value::getArray()
{
	return *static_cast<Array*>(object);
}

double&
Engine::JSON::Value::getNumber()
{
	return number;
}

Engine::String&
Engine::JSON::Value::getString()
{
	return string;
}


bool const&
Engine::JSON::Value::getBool() const
{
	return boolean;
}

Engine::JSON::Array const&
Engine::JSON::Value::getArray() const
{
	return *static_cast<Array*>(object);
}

Engine::String const&
Engine::JSON::Value::getString() const
{
	return string;
}

double const&
Engine::JSON::Value::getNumber() const
{
	return number;
}

const Engine::JSON::Object*
Engine::JSON::Value::getObject() const
{
	return static_cast<Object*>(object);
}

Engine::JSON::Value
Engine::JSON::parse(std::istream& input)
{
	Value ret;

	bool error = false;

	ret = setValue(input,error);

	if (error)
		ret = nullptr;

	return ret;
}