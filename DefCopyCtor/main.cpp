//
//  main.cpp
//  DefCopyCtor
//
//  Created by abbas raza on 27/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Use of default copy constructor which is a 1 argument constructor built into every class. 
   The argument is the object of same type.
 - Member by member copy of one object into the other happens.
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
};

int main()
{
	Distance d1(9, 1);
	
	Distance d2(d1); // default copy constructor will be called. d1 will be passed as argument to that.
	// member-by-member copy of d1 into d2. All members of d1 are copied into d2.
	//pointers??
	
	Distance d3 = d1; //default copy ctor will be called. d1 will be passed as argument.
    //member-by-member copy of d1 into d3.

	d1.show_distace();
	d2.show_distace();
	d3.show_distace();

	d3.set_distance(3, 2); // only d3 changed here. d1 and d2 remain unchanged.

	std::cout << "d1="; d1.show_distace();
	std::cout << "d2="; d2.show_distace();
	std::cout << "d3="; d3.show_distace();


	return 0;
}