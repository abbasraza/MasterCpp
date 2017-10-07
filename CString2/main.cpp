//
//  main.cpp
//  CString2
//
//  Created by abbas raza on 7/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of std::cin.get function.
 - How to get line with spaces.
 - How to get paragraph.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	char str[100];
	std::cout << "Enter a line: ";
	std::cin.get(str, 100);
	std::cout << "You entered: " << str << std::endl;

	std::cout << "Enter a Para: ";
	std::cin.get(str, 100, '$');
	std::cout << "You entered: " << str << std::endl;

	return 0;
}