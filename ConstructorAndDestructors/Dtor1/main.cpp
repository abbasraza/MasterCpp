//
//  main.cpp
//  Dtor1
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//
#include <iostream>

/* Purpose of this program:
 - Just to show a basic destructor.
 - Destructor is called for a local object on exit of function in which its defined.
 */

class smallobj
{
private:
	int data;
public:
	smallobj():data(0)
	{
		std::cout << "ctor called" << std::endl;
	}

	void set_data(int v) // will this be an inline function when object is instantiated??
	{
		data = v;
	}

	void show_data()
	{
		std::cout << "data = " << data << std::endl;
	}
	
	~smallobj() // destructor. No return, no argument
	{
		std::cout << "Destructor called" << std::endl;
		//release memory/resourses allocated for this object
	}
};

void test_function()
{
	std::cout << "Entered in test_function" << std::endl;
	smallobj obj2;
	std::cout << "Exiting test_function" << std::endl;
}

int main(int argc, const char * argv[])
{
	smallobj obj1;   // memory set aside for this object at this Object instantiation. functions memory??
	// is obj1 a memory space or pointer to memory space???
	// obj1 is like structure. i.e memory space in which data lies.

	
	//smallobj * obj2 = &obj1;
	//smallobj  obj2 = obj1;

	obj1.show_data();
	obj1.set_data(10);
	obj1.show_data();

	test_function();

	std::cout << "Program exiting" << std::endl;
	return 0;
}
