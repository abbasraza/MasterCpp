//
//  main.cpp
//  String4
//
//  Created by abbas raza on 11/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of c_str()
 - Usage of sizeof(pointer)
 - Usage of defining lenght of array at run-time.
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1 = "Abbas";

	char str1[] = "Abbas"; // has null at end
	const char * str2 = "Abbas"; // has null at end
	const char * str3 = s1.c_str(); // has null at end

	std::cout << static_cast<int>(str1[strlen(str1)]) << std::endl;
	std::cout << static_cast<int>(str2[strlen(str2)]) << std::endl;
	std::cout << static_cast<int>(str3[strlen(str3)]) << std::endl;
	std::cout << static_cast<int>(s1[s1.length()]) << std::endl; // no null ??

	// std::cout << static_cast<int>(s1.at(s1.length())) << std::endl; // error. bound check exception.

	/* sizeof(pointer variable) = sizeof pointer on platform i.e 32/64 bit etc */
	char  * temp;
	std::cout << "size of temp " << sizeof(temp) << std::endl;


	/****** copy c_str to dynamic memory  ******/

	/* Always allocate src.lenght() + 1. because c_str() gives string + null character at end. Totalling lenght to 
	   src.lenght() + 1
	   i.e 
	   string s1 = "Abbas";
	   here s1.lenght() = 5;
	   s1.c_str() will return a pointer to string {'A', 'b', 'b', 'a', 's', '\0'}
	   whose lenght will be equal to 6.
	   so if you want to copy s1 into a dynamically allocated char *, allocate 6 bytes and then copy.
	*/
	
	// THIS WAS USED DURING PRACTICE
	//	char * str4 = (char *)malloc(s1.length());
	//	memset((void *)str4, 3, s1.length() + 1);
	//	std::cout << static_cast<int>(str4[s1.length()]) << std::endl;
	//
	//	std::cout << "after copy" << std::endl;
	//
	//	strcpy(str4, s1.c_str());
	//	std::cout << static_cast<int>(str4[s1.length()]) << std::endl;
	
	
	/**** Way 1 ******/
	char * str4 = (char *)malloc(s1.length() + 1);
	strcpy(str4, s1.c_str()); // make str4 = {'A', 'b', 'b', 'a', 's', '\0'};
	/*************/

	/***** Way 2 *****/
	size_t len = s1.length(); // this is not known at compile time.
	// char str[len] = {}; // we can't initialize array whose len is not known at compile time.
	char str5[len + 1]; // however we can do this. dis
	
	strcpy(str5, s1.c_str()); // make str5 = {'A', 'b', 'b', 'a', 's', '\0'};
	/*************/
	
	/****** Way 3 ******/
	char * str6 = new char[s1.length() + 1];
	strcpy(str6, s1.c_str()); // make str6 = {'A', 'b', 'b', 'a', 's', '\0'};
	/***************/

	return 0;
}
