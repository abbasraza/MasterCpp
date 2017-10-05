//
//  main.cpp
//  Array3
//
//  Created by abbas raza on 5/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of 2D array.
 - When array is passed as argument, and function modifies elements, it will reflect in original array
   because array reference is passed instead of copy.
 */

#include <iostream>

#define	STUDENTS	4
#define DATA		2

void print_student_records(int rec[][DATA])
{
	std::cout << "Address of array passed in argument " << rec << std::endl;
	for(int i = 0; i < STUDENTS; ++i)
	{
		std::cout << "Roll Number " << " = " << rec[i][0];
		std::cout << ", Marks " << " = " << rec[i][1] << std::endl;
	}
}

void amend_student_records(int rec[][DATA])
{
	for(int i = 0; i < STUDENTS; ++i)
	{
		rec[i][1] += 5; // this will modify original array
	}
}

int main(int argc, const char * argv[])
{

	int student_records[][DATA] = {	{2, 50},
									{10, 80},
									{19, 85},
									{17, 90}
								};

	print_student_records(student_records);

	amend_student_records(student_records);

	print_student_records(student_records);

	return 0;
}
