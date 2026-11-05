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

char String::At(size_t index, char symbol)
{
	if (index >= length)
		throw StringException("Out of string's length");
	cStr[index] = symbol;
}

const char& String::At(size_t index) const
{
	return cStr[index];
}

size_t String::Length() const
{
	return length;
}



String::~String()
{
	delete[] cStr;
}

