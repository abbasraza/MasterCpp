//
//  main.cpp
//  CStringClass
//
//  Created by abbas raza on 9/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Creating class for c-style strings.
 - We cannot do:
	char str1[10] = "Hello";
	char str2[10];
	str2 = str1;
 
   But we can do:
   CString str1 = "Hello";
   CString str2 = str1;
 
 - Draw backs of class like this:
	--We have to manage the lenght/memory of arrays.
    --We can't do str1 + str2; (overloaded operators)
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
	void print_string();
	void concat(CString);
};

CString::CString() : str{'\0'}
{
	
}

CString::CString(const char s[])
{
	strcpy(str, s);
}

void CString::print_string()
{
	std::cout << str << std::endl;
}

void CString::concat(CString c)
{
	/* you should place bounds check here */

	//std::cout << strlen(str) << std::endl;
	
	/* strcat vs strcpy */
	//strcpy(str + strlen(str), c.str);
	strcat(str, c.str);
}

int main(int argc, const char * argv[])
{
	CString s1;
	
	/* Both of these are alternate methods to call argument wala constructor */
	CString s2("Hello");
	CString s3 = "How are you";
	/*************************************/
	
	CString s4 = s3;

	std::cout << "s1 = "; s1.print_string();
	std::cout << "s2 = "; s2.print_string();
	std::cout << "s3 = "; s3.print_string();
	std::cout << "s4 = "; s4.print_string();

	s1.concat(s2);
	std::cout << "s1 = "; s1.print_string();

	return 0;
}
