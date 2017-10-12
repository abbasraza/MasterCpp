//
//  main.cpp
//  OperatorOverloading3
//
//  Created by abbas raza on 12/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - How to do concat using + overloaded operator.
   CString str1 = "Hello";
   CString str2 = "Abbas";
   CString str3 = str1 + str2;
*/

#include <iostream>

class CString
{
private:
	static const int max_len = 50;
	char str[max_len];
public:
	CString();
	CString(const char []);
	void print_string() const;
	CString operator + (const CString&) const;
};

CString::CString() : str{'\0'}
{
	
}

CString::CString(const char s[])
{
	strcpy(str, s);
}

void CString::print_string() const
{
	std::cout << str << std::endl;
}

CString CString::operator + (const CString& s) const
{
	CString r;
	
	if ((strlen(str) + strlen(s.str)) < max_len)
	{
		strcpy(r.str, str);
		strcat(r.str, s.str);
	}
	return r;
}

/*
void CString::concat(CString c)
{
	// you should place bounds check here
	
	//std::cout << strlen(str) << std::endl;
	
	// strcat vs strcpy
	//strcpy(str + strlen(str), c.str);
	strcat(str, c.str);
}
*/

int main(int argc, const char * argv[])
{
	CString s1 = "Hello";
	CString s2 = "Abbas";
	
	/* Const reference to an object is same as constant object */
	const CString& s3 = s1;
	s3.print_string();

	CString s4 = s1 + s2;
	std::cout << "s4 = "; s4.print_string();
	
	return 0;
}
