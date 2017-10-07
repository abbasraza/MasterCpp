//
//  main.cpp
//  CString1
//
//  Created by abbas raza on 6/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of C style string.
 - Modifiable string:
	char string[10];
	char string[] = "Helllo";
	These can be modified like string[0] = 'a';
 - String constant/literal: (This can't be modified)
	const char * str = "hello";
 - Usage of setw
 - Usage of cin for getting a string.
 - char string[10]. here we can store 9 characters. at the end there is always null character. '\0'
*/

#include <iostream>
#include <iomanip> // for setw. if not included, will get error 'no setw' in namespace std.

int main(int argc, const char * argv[]) {
	
	char str[10]; // this is not constant string. just array of characters. so can be modified.
	
	std::cout << "Enter 9 or less characters : ";
	std::cin >> str; // '>>' operator considers space character as termination/null character?
	
	std::cout << str << std::endl; // keep sending characters to output until found null character or end of string.
	
	std::cout << "Enter more than 9 characters : ";

	/* works fine */
	std::cin >> std::setw(10) >> str;
	std::cout << str << std::endl;
	
	/* crash */ //setw is given out of bound lenght
	//std::cin >> std::setw(11) >> str;
	//std::cout << str << std::endl;

	char str2[] = "Practice practice and practice"; // the last character is null always
	str2[0] = 'a'; // this is not constant.
	std::cout << str2 << std::endl;

	char * str3 = "Am i wasting my time?"; // Rvalue = string literal and lvalue = char *
	// what is string literal??
	//str3[0] = 'L'; // this will cause a crash
	std::cout << str3 << std::endl;
	
	/* lvalue = constant    rvalue = constant. */
	const char * str4 = "Am i wasting my time.......?";
	std::cout << str4 << std::endl;


    return 0;
}
