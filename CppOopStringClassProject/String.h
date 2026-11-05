#pragma once
#include <cstring>
#include <iostream>

class StringException
{
	char* message;
public:
	StringException(const char* message);
	char* Message();
};

class String
{
	char* cStr;
	size_t length;
public:
	String();
	String(const char* cStr);
	String(char symbol, size_t count);

	String(const String& other);

	char At(size_t index, char symbol);
	const char& At(size_t index) const;

	size_t Length() const;

	~String();
};

