#include "String.h"
#include <cstring>

//Default constructor
String::String()
	:data(new char[10]), size(0)
{
}

//Constructor that takes single char and allocates 10 chars in data
String::String(char c)
	:data(new char[10]), size(1)
{
	*data = c;
}

//Constructor copies contents of C-string to new String's data array
String::String(const char* cstr)
	:data(new char[strlen(cstr)]), size(strlen(cstr))
{
	strcpy(data, cstr);
}

//Copy Constructor
String::String(const String& other)
	:data(new char[other.size]), size(other.size)
{
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}

}

//Destructor
String::~String()
{
	if (data != nullptr)
	{
		delete [] data;
		data = nullptr;
	}
	size = 0;
}

String& String::operator=(const String& right)
{

	if (size < right.size)
	{
		delete[] data;
		data = new char[right.size];
	}

	size = right.size;

	for (int i = 0; i < size; i++)
	{
		data[i] = right.data[i];
	}

	return *this;
}

	int String::length() const
	{
		return size;
	}

	char String::charAt(int i) const
	{
		return *(data + i);
	}

	int String::indexOf(char c) const
	{
		
		for (int i = 0; i < size; ++i)
		{
			if ( *(data + i) == c )
			{
				return i;
			}

		}

		return -1 ;
	}

	char& String::operator[](int i)
	{
		return data[i];
	}

	String String::operator+(const String& right) const
	{
		int concSize = this->size + right.size;
		char* tempResult = new char[concSize + 1];
		
		for (int i = 0; i < this->size; ++i) {
			tempResult[i] = this->data[i];
		}

		for (int i = 0; i < right.size; ++i) {
			tempResult[this->size + i] = right.data[i];
		}

		tempResult[concSize] = '\0';
		String result(tempResult);
		delete[] tempResult;
	
		return result;
	}

	String String::operator+(char c) const
	{
		int concSize = this->size + 1;
		char* tempResult = new char[concSize + 1];
		for (int i = 0; i < this->size; ++i)
		{
			tempResult[i] = this->data[i];
		}
		
		tempResult[concSize - 1] = c;
		tempResult[concSize] = '\0';
		String result(tempResult);
		delete[] tempResult;

		return result;
	}

	bool String::operator==(const String& right) const 
	{
		if (this->size != right.size) {
			return false;
		}

		for (int i = 0; i < this->size; ++i) {
			if (this->data[i] != right.data[i]) {
				return false;
			}
		}

		return true;
	}

	bool String::operator!=(const String& right) const
	{

		return !(*this == right);
	}

	bool String::operator<(const String& right) const
	{
		if (*this == right) {
			return false;
		}

		if (this->size > right.size) {
			return false;
		}

		for (int i = 0; i < this->size; ++i) {
			if (this->data > right.data) {
				return false;
			}
		}
		return true;
	}


	bool String::operator>(const String& right) const
	{
		return !(*this < right) && !(*this == right);
	}


	bool String::operator>=(const String& right) const
	{
		return *this > right || *this == right;
	}


	bool String::operator<=(const String& right) const
	{
		return *this < right || *this == right;
	}

	String String::substring(int start, int end) const 
	{
		if (start > end || start < 0 || start >= size || start == end)
		{
			return String();
		}

		if (end > size)
		{
			end = size;
		}

		int substringLength = end - start;
		char* substring = new char[substringLength + 1];

			for (int i = 0; i < substringLength; ++i)
			{
					substring[i] = data[start + i];   
			}
			substring[substringLength] = '\0';
			String s(substring);
			delete [] substring;
		return s;
	}

	std::ostream& operator<<(std::ostream& os, const String& s)
	{
		os << s.str();
		return os;
	}
	

	std::istream& operator>>(std::istream& is, String& s) 
	{
		std::string in;
		is >> in;
		char* c = new char[in.length()];


		for (int i = 0; i < in.length(); ++i) {
			c[i] = in.at(i);
		}

		c[in.length()] = '\0';
		s = c;
		delete [] c;

		return is;
	}

	std::string String::str() const
	{
		std::ostringstream sout;
		for (int i = 0; i < size; i++)
		{
			sout << data[i];
		}

		return sout.str();
	}