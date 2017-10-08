//
//  main.cpp
//  Array1
//
//  Created by abbas raza on 5/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of 1D array.
 - Address of array.
 - Passing 1D array as function argument.
 - How elements of 1D array of integers are stored in memory.
 - When array is passed as argument, and function modifies elements, it will reflect in original array.
*/

#include <iostream>

//void print_marks(int marks[4], int len) // Correct way to define function taking array as argument.
void print_marks(int marks[], int len) // we can skip number of elements in array here. i.e [4]
{
	std::cout << "Address of array passed in argument " << marks << std::endl;
	for(int i = 0; i < len; ++i)
	{
		std::cout << "Roll Number " << i + 1 << " = " << marks[i] << std::endl;
		std::cout << "Address of array member " << i << " = " << &marks[i] << std::endl;
	}
}

int main(int argc, const char * argv[])
{
	// int student_marks[]; //error
	// int student_marks[4]; // no error
	
	/* // This is wrong
	int student_marks[4];
	student_marks = {50, 80, 85, 90};
	*/
	
	/* 	// This is correct
	int student_marks[4];
	student_marks[0] = ;
	student_marks[1] = ;
	..
	..
	*/

	/* These both are correct
	int student_marks[4] = {50, 80, 85, 90};
	int student_marks[] = {50, 80, 85, 90};
	 */

	int student_marks[] = {50, 80, 85, 90};

	/* 
	 Address of Array is name of array
	 cout << student_marks;
	 will print the address of array.
	 Similarly the address of first element of array is same as address of array.
	 cout << &student_marks[0];
	 
	 cout << &student_marks; // this is also address of array. But we can't pass this in argument.
	*/

	std::cout << "Address of array student_marks method 1 " << student_marks << std::endl;
	std::cout << "Address of array student_marks method 2 " << &student_marks[0] << std::endl;
	std::cout << "Address of array student_marks method 3 " << &student_marks << std::endl;

	// print_marks(&student_marks[0], sizeof(student_marks) / sizeof(int)); // This is correct way to pass array in argument.
	print_marks(student_marks, sizeof(student_marks) / sizeof(int)); //this is also correct.

	// print_marks(&student_marks, sizeof(student_marks) / sizeof(int)); //this is not correct.
	

	return 0;
}
