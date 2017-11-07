//
//  main.cpp
//  CStringtoString
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - CString to C-Style string conversion and vice versa.
 - a const function treats all member data as const.
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
	operator char * ();
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

CString::operator char * ()
{
	return str;
}


int main(int argc, const char * argv[])
{
	CString s1;
	
	/* C-Style string to CString */
	s1 = "Hello Kainaat";
	std::cout << "s1 = "; s1.print_string();
	
	std::cout << "C-Style string = " << s1 << std::endl; // without conversion operator, this will cause linking error.

	/* CString to C-Style string*/
	char * str = s1;
	std::cout << "C-Style string = " << str << std::endl;
	std::cout << "C-Style string = " << static_cast<char *>(s1) << std::endl;

	//char str2[] = static_cast<char *>(s1); // this can't be done.
	//char str2[] = str; // this can't be done.


	return 0;
}
