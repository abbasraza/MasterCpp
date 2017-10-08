//
//  main.cpp
//  Array2
//
//  Created by abbas raza on 5/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of 2D array (why called 2D?). Declare, define.
 - Practical use. Store marks of students in memory (1D) vs store marks of students along with their roll number
   in memory (2D). Consider it as an excel sheet. 1 coloumn for roll numbers and 1 column for marks. or 1 row for
   roll numbers and 1 row for marks.
   2dArray[NUMBER_OF_STUDENTS][FIELDS_PER_STUDENT]
 - Address of array.
 - Passing 2D array as function argument.
 - How elements of 2D array of integers are stored in memory. 1 row, then 2nd, then 3rd after that.
 - When array is passed as argument, and function modifies elements, it will reflect in original array.

 */

#include <iostream>

// void print_student_records(int rec[4][2]) // correct way
void print_student_records(int rec[][2])
{
	std::cout << "Address of array passed in argument " << rec << std::endl;
	for(int i = 0; i < 4; ++i)
	{
		std::cout << "Roll Number " << " = " << rec[i][0];
		std::cout << ", Marks " << " = " << rec[i][1] << std::endl;
	}
}

void print_2d_array_addresses(int rec[][2])
{
	for(int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << "Address of element [" << i << "]" << "[" << j << "]" << &rec[i][j] << std::endl;
		}
	}
}

int main(int argc, const char * argv[])
{
	//int student_records[][]; //error
	//int student_records[][2]; // error
	//int student_records[4][2]; // no error

	
	 /* This is wrong
	 //int student_records[4][2];
	 //student_records = {{2, 50}, {10, 80}, {19, 85}, {17, 90}};
	 */
	
	/* 	// This is correct
	 int student_records[4][2];
	 student_records[0][0] = ;
	 student_records[0][1] = ;
	 ..
	 ..
	 */
	
	/* These both are correct
	 int student_records1[4][2] = {	{2, 50},
									{10, 80}, 
									{19, 85}, 
									{17, 90}
								};

	 int student_records2[][2] = {	{2, 50},
									{10, 80},
									{19, 85},
									{17, 90}
								};
	 */
	
	/* These both are wrong. Can't leave 2nd dimension empty
	 int student_records3[4][] = {	{2, 50},
									{10, 80},
									{19, 85},
									{17, 90}
								};
	 
	 int student_records4[][] = {	{2, 50},
									{10, 80},
									{19, 85},
									{17, 90}
								};
	 */
	 

	int student_records[][2] = {	{2, 50},
									{10, 80},
									{19, 85},
									{17, 90}
								};
	
	/*
	 Address of Array is name of array
	 cout << student_records;
	 will print the address of array.
	 Similarly the address of first element of array is same as address of array.
	 cout << &student_records[0];
	 
	 cout << &student_records; // this is also address of array. But we can't pass this in argument.
	 */
	
	std::cout << "Address of array student_records " << &student_records[0] << std::endl;
	std::cout << "Address of array student_records method 2 " << student_records << std::endl;
	std::cout << "Address of array student_records method wrong " << &student_records << std::endl;

	
	print_student_records(&student_records[0]); // This is correct way to pass array in argument.
	
	print_2d_array_addresses(student_records);
	// print_2d_array_addresses(&student_records); // This is wrong

	
	return 0;
}
