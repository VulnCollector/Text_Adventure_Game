#include "String.h"
#include <iostream>
#include <string>
using namespace std;

String::String()
{
	str = nullptr;
	str = new char[1];
	str[0] = '\0';
}

String::String(const char* _str)
{
	// copy string into char* array
	int size = (int)strlen(_str);
	str = new char[size + 1];
	memcpy(str, _str, size + 1);


	
}

String::String(const String& _other)
{
	// copy string into char* array
	int size = (int)strlen(_other.str);
	str = new char[size + 1];
	memcpy(str, _other.str, size + 1);
}

String::~String()
{
	delete str;
	str = nullptr;
}

size_t String::Length() const
{
	return size_t(strlen(str)); //get length of string
}

char& String::CharacterAt(size_t _index)
{
	//get the character at a certain index in the string
	if (_index < 0 || _index > strlen(str))
	{
		
		return str[strlen(str)];
	}
	else
	{
		
		return str[_index];
	}
	
}

const char& String::CharacterAt(size_t _index) const
{

	if (_index < 0 || _index > strlen(str))
	{

		return str[strlen(str)];
	}
	else
	{

		return str[_index];
	}
}

bool String::EqualTo(const String& _other) const
{
	//compare strings to see if they are the same
	if (strcmp(str, _other.str) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

String& String::Append(const String& _str)
{
	// add the second string onto the end of the first
	int length = (int)strlen(str) + (int)strlen(_str.str);
	strcat_s(str, length + 1, _str.str);
	return *this;
	
}

String& String::Prepend(const String& _str)
{
	//add the first string onto the end of the second
	int length = (int)strlen(str) + (int)strlen(_str.str);
	strcat_s(_str.str, length + 1, str);
	str = _str.str;
	return *this;
}

const char* String::CStr() const
{
	//return the string sent to the class
	return str;
}

String& String::ToLower()
{
	//make all the letters in the string lowercase
	for (size_t i = 0; i < Length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return *this;
}

String& String::ToUpper()
{
	//make all the letters in the string uppercase
	for (size_t i = 0; i < Length(); i++)
	{
		str[i] = toupper(str[i]);
	}
	return *this;
}

size_t String::Find(const String& _str)
{
	//same as below but starting from the first index always
	return Find(0, _str);
}

size_t String::Find(size_t _startIndex, const String& _str)
{
	//find a certain string inside a string starting from the start index input
	if (_startIndex >= Length())
	{
		return -1;
	}
	const char* pos = strstr(str + _startIndex, _str.str);
	if (pos != nullptr)
	{
		return pos - str;
	}
	else
	{
		return -1;
	}
}

String& String::Replace(const String& _find, const String& _replace)
{
	//replace all instances of _find with _replace ||| Code used from STACKOVERFLOW
	size_t startPos = 0;
	while ((startPos = Find(startPos, _find)) != -1)
	{
		string Replace = string(str, str + startPos) + _replace.CStr() + string(str + startPos + _find.Length());

		char* newStr = new char[Replace.length() + 1];

		strcpy_s(newStr,strlen(newStr + 1), Replace.c_str());

		str = newStr;

		startPos += _replace.Length();
	}

	return *this;
}

String& String::ReadFromConsole()
{
	//get the user input and input it into the char array
	string input;
	getline(cin, input);
	char* newStr = new char[input.length() + 1];
	strcpy_s(newStr, strlen(newStr + 1), input.c_str());
	str = newStr;
	return *this;
}

String& String::WriteToConsole()
{
	//write the character array to the console
	cout << str;
	return *this;
}

bool String::operator==(const String& _other)
{
	//overload == operator, see EqualTo Function
	return this->EqualTo(_other);
}

bool String::operator!=(const String& _other)
{
	//opposite of ==
	return !(*this == _other);
}

String& String::operator=(const String& _str)
{
	//copy _str char array into this char array
	str = new char[_str.Length() + 1];
	strcpy_s(str, this->Length() + 1, _str.str);
	
	return *this;
		
}

char& String::operator[](size_t _index)
{
	//return the character at _index in the char array
	return str[_index];
}

const char& String::operator[](size_t _index) const
{
	return str[_index];
}

bool String::operator<(const String& _other)
{
	//check if this string is before or after _others string alphabetically
	return strcmp(str, _other.str) < 0;
}

String& String::operator+(const String& _str)
{
	//add the 2 strings together, see append
	return this->Append(_str);
}

String& String::operator+=(const String& _str)
{
	//same as above
	return this->Append(_str);
}
