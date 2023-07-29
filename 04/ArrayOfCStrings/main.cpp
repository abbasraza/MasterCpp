//
//  main.cpp
//  ArrayOfCStrings
//
//  Created by abbas raza on 7/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array of strings.
 - What does array of strings mean? String is an array of characters. So 'array of strings' = array of 'array of characters'.
   i.e array of arrays. which is 2D array.
 - Difference between array of strings vs array of character pointers.
 - Constant strings
	---> const char * str[] = ..
	---> const char str[] = ..
    are stored in different section of program memory (Read-only/Text??).
*/

#include <iostream>

int main(int argc, const char * argv[])
{
	/* Array of strings */
	char days_of_week[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	
	//char days_of_week2[] = {"Sunday", "Monday"};
	//char days_of_week2[] = days_of_week[0]; // we can't do this.

	/* Address where strings are stored. All same. 
	   {string1, string2, string3,... }
	*/
	std::cout << "Non const array address 1 " << static_cast<void *>(days_of_week) << std::endl;
	std::cout << "Non const array address 2 " << static_cast<void *>(&days_of_week) << std::endl;
	std::cout << "Non const array address 3 " << static_cast<void *>(days_of_week[0]) << std::endl;
	std::cout << "Non const array address 4 " << static_cast<void *>(&days_of_week[0]) << std::endl;


	/* Array of const strings */
	const char days_of_week3[][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	/* Address where strings are stored. All same.
	 {string1, string2, string3,... }
	 */
	std::cout << "const char array address 1 " << static_cast<const void *>(days_of_week3) << std::endl;
	std::cout << "const char array address 2 " << static_cast<const void *>(&days_of_week3) << std::endl;
	std::cout << "const char array address 3 " << static_cast<const void *>(days_of_week3[0]) << std::endl;
	std::cout << "const char array address 4 " << static_cast<const void *>(&days_of_week3[0]) << std::endl;

	

	/* Array of pointers to const strings. */
	const char * days_of_week4[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	/* Address where pointers are stored. All same. 
	   {pointer1, pointer2, pointer3,...}
	*/
	std::cout << "Array of const char * address 1 " << static_cast<const void *>(days_of_week4) << std::endl;
	std::cout << "Array of const char * address 2 " << static_cast<const void *>(&days_of_week4) << std::endl;
	std::cout << "Array of const char * address 3 " << static_cast<const void *>(&days_of_week4[0]) << std::endl;
	
	/* Address where strings are stored. i.e where pointers are pointing. 
	   Its in different (read-only) section. Is it in text section??
	*/
	std::cout << "Array of const char * address 4 " << static_cast<const void *>(days_of_week4[0]) << std::endl;


	for (int i = 0; i < 7; ++i)
	{
		std::cout << days_of_week[i] << std::endl;
	}
    return 0;
}
