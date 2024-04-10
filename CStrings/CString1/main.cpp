//
//  main.cpp
//  CString1
//
//  Created by abbas raza on 6/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of C style string. 
   const vs non-const string.
 
 - Modifiable string:
	char string[10];
	char string[] = "Helllo";
	These can be modified like string[0] = 'a';
 
 - String constant/literal: (This can't be modified)
	const char * str = "hello";
    const char str[] = "Hello";
 
 - Usage of setw
 
 - Usage of cin for getting a string.
 
 - char string[10]. here we can store 9 characters. at the end there is always null character. '\0'
 
 - char str[] = "Hello";
   const char str2[] = "Hello";
   char * str3 = "Hello";
   const char * str4 = "Hello";
   Here str is stored in a section which can is writeable. 
   str2, str3, str4 are stored in read-only sections. (Text section??)
   Can be verified by printing the addresses.
 
 - How to print the address in this situation (i.e how to print address of location where string is stored)
		const char * str = "HELLLO";
		std::cout << str << std::endl; // this will print complete string pointed to by str.
	but we want to print the address where HELLLO is stored.
	str is a pointer which contains address of HELLLO.
	so we just need to print whats inside str.
	in case of integer it simple.
	int a = 10;
	int * ptr = &a;
	std::cout << ptr << std::endl;
	this will print address of a.
	but this is not the case as we seen above in case of string.
	so what we need to do is to give cout a pointer of different type instead of char pointer.
	so lets give it void ptr. we need to convert char pointer to void and then give it to cout.
	std::cout << static_cast<void *>(str) << std::endl;
	this will print address where "HELLLO" is stored. so when void pointer is given to cout like int, it will print address inside.
*/

#include <iostream>
#include <iomanip> // for setw. if not included, will get error 'no setw' in namespace std.

int main(int argc, const char * argv[]) {
	
	char str[10]; // this is not constant string. just array of characters. so can be modified.
	
	std::cout << "Enter 9 or less characters : ";
	std::cin >> str; // '>>' operator considers space character as termination/null character?
	
	std::cout << str << std::endl; // keep sending characters to output until found null character or end of string.
	/* In  ^^^ statement, we are passing address of array str to cout. When address of a char array is passed to cout, cout will
	   not print address. it will print characters/string at that address.
	   so
	 std::cout << &str[0] << std::endl;
	 will print string as well instead of printing the address of the array. or address where this string is stored.
	 */

	/* How to find if any two addresses are same ??? */
	void * addr1 = static_cast<void *>(str);
	void * addr2 = static_cast<void *>(&str[0]);
	void * addr3 = static_cast<void *>(&str);
	//void * addr4 = static_cast<void *>(str[0]); //can't do this.

	// void * addr3 = &str; // same as above but in C-Style.

	if ((addr1 == addr2) && (addr1 == addr3))
	{
		std::cout << "All addresses are same" << std::endl;
		std::cout << "str ------> addr1 = " << addr1 << std::endl;
		std::cout << "&str[0] --> addr2 = " << addr2 << std::endl;
		std::cout << "&str -----> addr3 = " << addr3 << std::endl;
	}


	std::cout << "Enter more than 9 characters : ";

	/* works fine */
	std::cin >> std::setw(10) >> str;
	std::cout << str << std::endl;
	
	/* crash */ //setw is given out of bound lenght
	//std::cin >> std::setw(11) >> str;
	//std::cout << str << std::endl;

	char str2[] = "Practice practice and practice"; // the last character is null always
	str2[0] = 'a'; // this is not constant.
	std::cout << str2[0] << std::endl;


	const char str3[] = "Am i wasting my time?";
	// str3[0] = 'a'; // can't do this.
	

	char * str4 = "Am i wasting my time?"; // Rvalue = string literal and lvalue = char *
	// what is string literal??
	//str3[0] = 'L'; // this will cause a crash
	std::cout << str4 << std::endl;
	
	/* lvalue = constant    rvalue = constant. */
	const char * str5 = "Am i wasting my time.......?"; // where is this string stored??
	std::cout << str5 << std::endl;

	std::cout  << "Address of str2 = " << static_cast<void *>(str2) << std::endl;
	std::cout  << "Address of str3 = " << static_cast<const void *>(str3) << std::endl;
	std::cout  << "Address of str4 = " << static_cast<void *>(str4) << std::endl;
	std::cout  << "Address of str5 = " << static_cast<const void *>(str5) << std::endl;

	return 0;
}
