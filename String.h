#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <string>
#include <sstream>


class StringTester;

class String
{
    friend class StringTester;
private:
    // declare private members here
	char* data = nullptr;
	int size = 0;




public:
    // declare public members here
	String();
	String(char c);
	String(const char* c);
	String(const String& other);
	~String();
	String& operator=(const String& right);

	int length() const;
	char charAt(int i) const;
	int indexOf(char c) const;
	char& operator[](int i);

	String operator+(const String& right) const;
	String operator+(char c) const;

	bool operator==(const String& right) const;
	bool operator<(const String& right) const;
	bool operator!=(const String& right) const;
	bool operator>=(const String& right) const;
	bool operator>(const String& right) const;
	bool operator<=(const String& right) const;


	String substring(int start, int end) const;

	std::string String::str() const;

	friend std::ostream& operator<<(std::ostream& os, const String& s);
	friend std::istream& operator>>(std::istream& is, String& s);

};

std::ostream& operator<<(std::ostream& os, const String& s);
std::istream& operator>>(std::istream& is, String& s);

#endif