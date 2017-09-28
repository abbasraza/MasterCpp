//
//  main.cpp
//  ObjAsFuncArg1
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Use of constructor overloading. No arguments constructor is default constructor.
 - Use of passing objects in function arguments. (copy is passed)
 - Function definition outside class body. not inline??
*/

#include <iostream>

class Distance
{
private:
	int feet;
	float inch;
public:
	// constructor has no return type
	Distance():feet(0), inch(0.0) // initializer list. initialize to 0 or any other hard-coded value
	{
		//std::cout << "Constructor called" << std::endl;
	}
	Distance(int f, float i)
	{
		feet = f;
		inch = i;
	}
	void set_distance(int f, float i)
	{
		feet = f;
		inch = i;
	}
	void show_distace()
	{
		std::cout << "Distance = " << feet << " feet and " << inch << " inches" << std::endl;
	}
	void get_distance()
	{
		std::cout << "Enter feet" << std::endl;
		std::cin >> feet;
		std::cout << "Enter inches" << std::endl;
		std::cin >> inch;
	}
	void add_distance(Distance);
};

void Distance::add_distance(Distance d)
{
	feet += d.feet; // since d is Distance object, that's why functions of Distance class can access d's data.

	if (inch + d.inch >=12)
	{
		feet += 1;
		inch = (inch + d.inch - 12);
	}
	else
	{
		inch += d.inch;
	}
	//d.set_distance(0, 0); // we are changing d (local copy) here
}

int main()
{
	Distance d1;	// Constructor without arguments is called when object defined.
	Distance d2(9, 1);	// Constructor with arguments called.
	Distance d3(1, 2);

	d1.add_distance(d2);	// copy of d2 passed to function
	d1.add_distance(d3);	// copy of d3 passed to function
	
	d1.show_distace();
	
	d2.show_distace();
	d3.show_distace();

	return 0;
}