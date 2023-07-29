//
//  main.cpp
//  CStringClassMember
//
//  Created by abbas raza on 8/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array of characters (C-Style strings) inside class.
 - How to initialize array ?
		- No argument constructor.
		- Constructor with arguments.
 - Copy constructor will copy array.
*/

#include <iostream>

class Student
{
private:
	char name[30];
	int roll_number;
public:
	Student() : name("Default"), roll_number(0) // how to initialize array
	{
	}

	Student(const char n[], int rn) : roll_number(rn)
	{
		//std::cout << "Calling argument wala constructor" << std::endl;
		strcpy(name, n);
	}

	void store_student_data(const char n[], int rn)
	{
		strcpy(name, n);
		roll_number = rn;
	}

	void print_student_data()
	{
		std::cout << "Name: " << name << " <----> Roll Number: " << roll_number << std::endl;
	}
};

int main(int argc, const char * argv[]) {

	Student s1;
	s1.print_student_data();
	s1.store_student_data("Abbas", 17);
	s1.print_student_data();
	
	Student s2("Fraz", 49);
	s2.print_student_data();
	
	Student s3 = {"Usman", 19}; // This will call argument wala ctor.
	s3.print_student_data();
	
	Student s4 = s3; // copy ctor will be called. Array copied.
	std::cout << "s4 = "; s4.print_student_data();

	s4.store_student_data("Omer", 1);

	std::cout << "s3 = "; s3.print_student_data();
	std::cout << "s4 = "; s4.print_student_data();

	return 0;
}
