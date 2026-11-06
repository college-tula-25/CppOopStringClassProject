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

	String& operator=(const String& other);
	String& operator=(char symbol);

	char At(size_t index, char symbol);
	const char& At(size_t index) const;

	char& operator[](size_t index);

	size_t Length() const;

	String& Append(const String& str);
	String& Insert(size_t index, const String& str);
	String& Erase(size_t index, size_t length);
	String& Erase();

	int Find(String str, size_t index = 0);
	int Find(char symbol, size_t index = 0);


	String& SubString(size_t index, size_t length);
	String& Reverse();
	size_t Count(String str);
	size_t Count(char symbol);

	String& operator+= (const String& str);
	String& operator*(size_t count);

	friend String& operator+(const String& left, const String& right);
	
	friend bool operator<(const String& left, const String& right);
	friend bool operator>=(const String& left, const String& right);
	friend bool operator>(const String& left, const String& right);
	friend bool operator<=(const String& left, const String& right);
	friend bool operator==(const String& left, const String& right);
	friend bool operator!=(const String& left, const String& right);


	friend std::ostream& operator<<(std::ostream& out, const String& str);

	~String();
};

