#include "String.h"

StringException::StringException(const char* message)
{
	this->message = new char[strlen(message) + 1];
	strcpy_s(this->message, strlen(message) + 1, message);
}

char* StringException::Message()
{
	return message;
}




String::String()
	: length{}
{
	cStr = new char{ '\0' };
}

String::String(const char* cStr)
	: length{ std::strlen(cStr) }
{
	this->cStr = new char[length + 1];
	strcpy_s(this->cStr, length + 1, cStr);

	std::cout << "String construct\n";
}

String::String(char symbol, size_t count)
	: length{ count }
{
	cStr = new char[length + 1];
	for (int i{}; i < length; i++)
		cStr[i] = symbol;
	cStr[length] = '\0';
}

String::String(const String& other)
	: length{ other.length }
{
	cStr = new char[length + 1];
	strcpy_s(cStr, length + 1, other.cStr);
}

String& String::operator=(const String& other)
{
	if (&other == this)
		return *this;
	
	if (cStr)
		delete[] cStr;

	length = other.length;
	cStr = new char[length + 1];

	strcpy_s(cStr, length + 1, other.cStr);

	return *this;
}

String& String::operator=(char symbol)
{
	*this = String(symbol, 1);
	return *this;
}

char String::At(size_t index, char symbol)
{
	if (index >= length)
		throw StringException("Out of string's length");
	cStr[index] = symbol;
}

const char& String::At(size_t index) const
{
	if (index >= length)
		throw StringException("Out of string's length");
	return cStr[index];
}

char& String::operator[](size_t index)
{
	return cStr[index];
}

size_t String::Length() const
{
	return length;
}

String& String::Append(const String& str)
{
	char* newStr = new char[length + str.length + 1];

	size_t index{};
	for (int i{}; i < length; i++)
		newStr[index++] = cStr[i];

	for (int i{}; i < str.length; i++)
		newStr[index++] = str.cStr[i];

	newStr[index] = '\0';

	delete[] cStr;
	cStr = newStr;
	length += str.length;

	return *this;
}

String& String::Erase(size_t index, size_t length)
{
	if (index >= length)
		throw StringException("Out of string's length");

	char* newStr = new char[this->length - length + 1];
	int newIndex{};

	for (size_t i{}; i < index; i++)
		newStr[newIndex++] = cStr[i];
	for(size_t i{ index + length}; i < length; i++)
		newStr[newIndex++] = cStr[i];

	newStr[newIndex] = '\0';

	delete[] cStr;
	cStr = newStr;
	this->length -= length;

	return *this;
}

String& String::Reverse()
{
	String result(*this);
	for (size_t i{}, j{ result.length - 1 }; i < result.length; i++, j--)
	{
		char t = result.cStr[i];
		result.cStr[i] = result.cStr[j];
		result.cStr[j] = t;
	}
	return result;
}

String& String::operator+=(const String& str)
{
	return Append(str);
}



String::~String()
{
	delete[] cStr;
}

std::ostream& operator<<(std::ostream& out, const String& str)
{
	out << str.cStr;
	return out;
}

String& operator+(const String& left, const String& right)
{
	String result(left);
	return result.Append(right);
}

bool operator<(const String& left, const String& right)
{
	size_t minLength{ (left.length < right.length) ? left.length : right.length };

	for (size_t i{}; i < minLength; i++)
	{
		if (left.cStr[i] == right.cStr[i]) 
			continue;
		
		return left.cStr[i] < right.cStr[i];
	}
	return left.length < right.length;
}

bool operator>=(const String& left, const String& right)
{
	return !(left < right);
}
