//
//  main.cpp
//  StringClass
//
//  Created by abbas raza on 9/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of c++ standard string class.
	-- Ctor
	-- = operator
	-- + operator
	-- += operator
	-- swap
	-- -= (no such operator)
	-- size, length (Both synonyms and return same value)
	-- getline
	-- find
	-- find_first_of
	-- find_first_not_of
	-- erase
	-- replace
	-- insert
	-- append
	-- compare
	-- substr
- Details about string class --->  http://www.cplusplus.com/reference/string/string/
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	std::string s1;
	std::string s2 = "Hello";
	s1 = s2 + " Abbas";
	
	std::cout << "s1 --> " << s1 << std::endl;
	std::cout << "s2 --> " << s2 << std::endl;
	
	s1 += " Raza";
	
	std::cout << "s1 --> " << s1 << std::endl;
	
	// s1 -= "Abbas"; // Nah. No such operator overloaded.

	s1.swap(s2);

	std::cout << "s1 --> " << s1 << std::endl;
	std::cout << "s2 --> " << s2 << std::endl;

	std::cout << "s1 size --> " << s1.size() << std::endl;
	std::cout << "s2 size --> " << s2.size() << std::endl;

	std::string s3;

	std::cout << "Enter Line: ";
	std::getline(std::cin, s3);
	s3 = s2 + " " + s3; // don't we have pre-append ??
	// 	s3 = s2 + ' ' + s3; // ' ' works instead of " "

	std::cout << "s3 --> " << s3 << std::endl;

	
	std::string s4 = "Miss Moly had a dolly who was sick sick sick";
	
	/********* Usage of find *********/
	std::cout << "dolly found at index " << s4.find("dolly") << std::endl;
	std::cout << "sick found at index " << s4.find("sick") << std::endl; // first match.
	std::cout << "sick sick found at index " << s4.find("sick sick") << std::endl;
	std::cout << "ck found at index " << s4.find("ck ") << std::endl;
	std::cout << "'y' found at index " << s4.find('y') << std::endl; // finding a character.
	
	// if not found in string, then index returned = -1. cout shows it as unsigned. need explicit conversion.
	std::cout << "Abbas found at index " << static_cast<signed>(s4.find("Abbas")) << std::endl;
	/********************************/

	/********* Letter seach from a group of letters *********/
	std::cout << "first vowel letter found at index " << s4.find_first_of("aeiouAEIOU") << std::endl;
	std::cout << "last vowel letter found at index " << s4.find_last_of("aeiouAEIOU") << std::endl;
	std::cout << "first non-vowel letter found at index " << s4.find_first_not_of("aeiouAEIOU") << std::endl;
	/*******************************************************/

	/****** find *****/
	std::cout << "s4 before erase: " << s4 << std::endl;
	s4.erase(s4.find("sick"), 18); // erase(index, length);
	std::cout << "s4 after erase: " << s4 << std::endl;

	std::string s5 = "Kainaat";
	s4.replace((s4.find("Moly")), 4, s5); // replace string starting at index 1 and ending at index 2 with some string.
	std::cout << "s4 after replace: " << s4 << std::endl;
	
	s4.replace(s4.find(s5), 7, "Kainaat Zehra");
	std::cout << "s4 after replace: " << s4 << std::endl;
	/*****************/

	/* Whats the difference between lenght() and size() ??? lenght() uses size() ??  yes they are same!*/
	std::cout << "lenght of s4 " << s4.length() << std::endl;
	std::cout << "size of s4 " << s4.size() << std::endl;
	
	/* What are these ?? see link given above. */
	std::cout << "max size of s4 " << s4.max_size() << std::endl;
	std::cout << "capacity of s4 " << s4.capacity() << std::endl;

	/******* insert ********/
	s4.insert(s4.size(), " sick sick sick"); // insert in the end.
	std::cout << "s4 after insert: " << s4 << std::endl;
	/**********************/

	/******* erase ********/
	s4.erase(s4.find("Miss "), 4); // erase.
	std::cout << "s4 after erase: " << s4 << std::endl;
	/**********************/


	/******* append ********/
	std::cout << "s4 after append: " << s4.append(s5) << std::endl; // append returns reference to s4. i.e its not void.

	s4.append(3, '!'); // append 3 times ! (at the end).
	std::cout << "s4 after append: " << s4 << std::endl;
	/**********************/


	/******* compare ******/
	std::cout << "Is s4 same as s5? " << s4.compare(s5) << std::endl;
	
	std::string s6 = "HELLO";
	std::string s7 = "hello";
	std::cout << "Is s6 same as s7? " << s6.compare(s7) << std::endl; // compare return 0 if both strings are same.
	/**********************/


	/******* substr *******/
	std::cout << "Substring of s4 " << s4.substr(0, 10) << std::endl; // substr gives us seperate copy of sub string.
	/**********************/

	return 0;
}