//
//  main.cpp
//  ConstCast
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Only changes cv-qualification; all other casts cannot cast away constness. Can't change type.
 - Usage of const_cast
 - How const_cast can cast const char * pointer returned by c_str() to non constant pointer.
 - We then use this pointer to modify original string.
 
 - Compile time or runtime? TODO machine code / assembly difference?
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
	
	std::cout << "s1 = " << s1 << std::endl;
	
	const std::string s2 = "Hello Abbas Raza";
	const char * str2 = s1.c_str();
	std::strcpy(const_cast<char *>(str2), "Ihavemodifiedthestring");
	std::cout << "s2 = " << s2 << std::endl;

	/* Undefined behaviour:
	   Casting constness of a 'const int'
	*/
	const int v1 = 10;
	int * ptr1 = const_cast<int*>(&v1);
	*ptr1 = 20;
	std::cout << "v1 = " << v1 << " *ptr1 = " << *ptr1 << std::endl;

	/* Correct behaviour:
	   Casting constness of a 'const int *' to 'int'
	*/
	int v2 = 10;
	const int * ptr2 = &v2;
	int * ptr3 = const_cast<int*>(ptr2);
	*ptr3 = 20;
	std::cout << "v2 = " << v2 << " *ptr3 = " << *ptr3 << std::endl;

    return 0;
}
