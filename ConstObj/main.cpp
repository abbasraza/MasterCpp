//
//  main.cpp
//  ConstObj
//
//  Created by abbas raza on 1/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of constant objects.
 - We can only call constant functions with constant object. i.e only functions which do not modify any data.
 - We can call any (const/non-const) function on a non-const object.
 - We can copy const object to non-const object.
 - Passing const object in arguments.
 - Const object will contain values given at creation time.
 - When const obj is passed as argument, the func of the same class can read (only) its data. 
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
	void show_distace() const
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
	Distance add_distance(Distance);

};

Distance Distance::add_distance(const Distance d)
{
	std::cout << "Argument to add distance is " << &d << std::endl;
	//d.feet = 4; // this will throw error if d is const.
	Distance sum;

	sum.feet = feet + d.feet; // since d is Distance object, that's why functions of Distance class can access d's data.

	if (inch + d.inch >=12)
	{
		sum.feet += 1;
		sum.inch = (inch + d.inch - 12);
	}
	else
	{
		sum.inch = inch + d.inch;
	}

	return sum;
}

int main()
{
	const Distance d1(9, 1);
	std::cout << "d1="; d1.show_distace();
	// d1.get_distance(); // this will throw error.

	Distance d2(2, 12);
	std::cout << "d2="; d2.show_distace();

	//Distance d3 = d1.add_distance(d2); // this will throw error.
	Distance d3 = d2.add_distance(d1);
	std::cout << "d3="; d3.show_distace();
	d3.set_distance(1, 1);
	
	Distance d4(d1); // we can copy a const object to non const object
	d4.set_distance(4, 5);
	std::cout << "d4="; d4.show_distace();
	std::cout << "d1="; d1.show_distace();

	return 0;
}