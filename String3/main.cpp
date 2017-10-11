//
//  main.cpp
//  String3
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of string.at vs '[' operator.
 - Always use string.at instead of '['.
 - Always use string.length() for end of string.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1 = "Hello Abbas Raza";
	std::cout << "len of s1 " << s1.length() << std::endl;
	std::cout << "capacity of s1 " << s1.capacity() << std::endl;

	std::cout << s1.at(10) << std::endl;
	std::cout << s1[10] << std::endl;

	std::cout << s1.at(150) << std::endl; // This will throw exception (out of bounds)
	std::cout << s1[150] << std::endl; // This will not give any error/exception. So avoid this.

    return 0;
}
