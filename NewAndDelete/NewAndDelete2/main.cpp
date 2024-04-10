//
//  main.cpp
//  NewAndDelete2
//
//  Created by abbas raza on 19/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of dynamic memory allocation with new and delete.
 - Allocating array of integers dynamically.
 - Causing new to fail and generate exception.
 - Causing new to fail and avoiding exception using nothrow.
 - 2d array of ints using new. TODO
*/

//#define MCPP_NEW_GENERATE_EXCEPTION

#include <iostream>

void print_array(int * ptr)
{
	for(int i = 0; i < 10; ++i)
	{
		std::cout << "ptr[" << i << "] = " << ptr[i] << std::endl;
	}
}

int main(int argc, const char * argv[])
{
	/* Array of integers on heap */

	/* initialize array 1 */
	int * ptr1 = new int[10];
	ptr1[0] = 1;
	ptr1[1] = 2;
	print_array(ptr1);
	delete[] ptr1;
	ptr1 = NULL;

	/* initialize array 2 */
	int * ptr2 = new int[10]{0,1,2,3,4,5,6,7,8,9};
	print_array(ptr2);
	delete[] ptr2;
	ptr2 = 0;

	/* initialize array 3 */
	int * ptr3 = new int[10]{[0 ... 9] = 0};
	print_array(ptr3);
	delete[] ptr3;
	ptr3 = 0;

	/* initialize array 4 */
	std::cout << "Enter lenght of array wanted: " << std::endl;
	long len;
	std::cin >> len;
	int * ptr4 = new int[len];
	delete [] ptr4;

	/* causing memory allocation failure */
#ifdef MCPP_NEW_GENERATE_EXCEPTION
	int * ptr5 = new int[999999999999999];
#else
	int * ptr5 = new (std::nothrow) int[999999999999999];
#endif
	if (!ptr5)
	{
		std::cout << "failed to allocate memory" << std::endl;
	}

	delete[] ptr5;
	std::cout << "Program end" << std::endl;

	/*
	 #############################################################################
	 dynamically allocating 2d array of ints (dimensions compile time constant)
	 #############################################################################
    */
	//int ** array1 = new int[2][4]; // won't work
	int (*array1)[4] = new int[2][4];
	// OR
	auto array2 = new int[2][4];

	int rows;
	int cols;
	std::cin >> rows;
	std::cin >> cols;

	/*
	 ################################################################################
	 dynamically allocating 2d array of ints (dimensions not compile time constant)
	 ################################################################################
    */
	//auto array3 = new int[rows][cols]; // won't work
	//int (*array3)[cols] = new int[rows][cols]; // won't work
	// int ** array3 = new int[rows][cols]; //won't work
	//TODO
	return 0;
}
