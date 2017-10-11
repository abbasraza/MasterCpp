//
//  main.cpp
//  ConstCast
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of const_cast
 - How const_cast can cast const char * pointer returned by c_str() to non constant pointer.
 - We then use this pointer to modify original string.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1 = "Hello Abbas Raza";
	std::cout << "len of s1 " << s1.length() << std::endl;
	std::cout << "capacity of s1 " << s1.capacity() << std::endl;

	const char * str = s1.c_str();
	std::strcpy(const_cast<char *>(str), "Ihavemodifiedthestring");
	std::cout << "len of s1 " << s1.length() << std::endl;
	std::cout << "capacity of s1 " << s1.capacity() << std::endl;
	
	std::cout << s1 << std::endl;
    return 0;
}
