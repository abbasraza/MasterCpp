//
//  main.cpp
//  String2
//
//  Created by abbas raza on 10/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of string relational operators
	--- ==
	---	<
	--- >
 - The operators use std::compare
 - Return
	 0	They compare equal
	<0	Either the value of the first character that does not match is lower in the compared
		string, or all compared characters match but the compared string is shorter.
	>0	Either the value of the first character that does not match is greater in the compared
		string, or all compared characters match but the compared string is longer.

 - http://www.cplusplus.com/reference/string/string/operators/

 Enter s1: a
 Enter s2: aa
 a came before aa
 
 Enter s1: aa
 Enter s2: a
 aa came after a

*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1;
	std::string s2;
	std::string s3;

	while (1)
	{
		std::cout << "Enter s1: ";
		std::cin >> s1;
		std::cout << "Enter s2: ";
		std::cin >> s2;

		if (s1 == s2)
		{
			std::cout << s1 << " = " << s2 << std::endl;
		}

		if (s1 < s2)
		{
			std::cout << s1 << " came before " << s2 << std::endl;
		}

		if (s1 > s2)
		{
			std::cout << s1 << " came after " << s2 << std::endl;
		}
	}

	return 0;
}