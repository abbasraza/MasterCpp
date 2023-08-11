//
//  main.cpp
//  Reference2
//
//  Created by abbas raza on 4/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of reference (Alias). Just a different name for a variable.
 - Reference in assignment.
 - Pass by reference.
 - Return by reference.
	- Reference to local variable.
	- Reference to global variable.
	- Reference on left side of = . Means original variable will be changed.
	- Reference on right side of =. Means original variable will remain unchanged.
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
	Distance add_distance(Distance&);
	Distance& add_distance2(Distance);

};

Distance global_d;
Distance Distance::add_distance(Distance& d)
{
	std::cout << "Argument to add distance is " << &d << std::endl;
	//d.feet = 4; // this will throw error if d is const.
	// if d modified, it will reflect in original passed as argument.
	Distance sum;
	std::cout << "local variable sum address: " << &sum << std::endl;

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

Distance& Distance::add_distance2(Distance d)
{
	std::cout << "Argument to add distance is " << &d << std::endl;
	//d.feet = 4; // this will throw error if d is const.
	global_d.feet = feet + d.feet; // since d is Distance object, that's why functions of Distance class can access d's data.

	if (inch + d.inch >=12)
	{
		global_d.feet += 1;
		global_d.inch = (inch + d.inch - 12);
	}
	else
	{
		global_d.inch = inch + d.inch;
	}

	return global_d;
}

int main()
{
	Distance d1(9, 1);
	std::cout << "d1 address: " << &d1 << " d1= "; d1.show_distace();

	Distance& d2 = d1;
	std::cout << "d2 address: " << &d2 << " d2= "; d2.show_distace();

	d2.set_distance(11, 3);
	std::cout << "d1 address: " << &d1 << " d1= "; d1.show_distace();
	std::cout << "d2 address: " << &d2 << " d2= "; d2.show_distace();

	Distance d3 = d2.add_distance(d1);
	std::cout << "d3 address: " << &d3 << " d3= "; d3.show_distace();

	Distance& d4 = d3.add_distance2(d2); // d4 is same as reference returned by add_distance2
	Distance d5 = d3.add_distance2(d2); // d5 is seperate copy of reference returned by add_distance2

	std::cout << "global_d address: " << &global_d << " global_d= "; global_d.show_distace();
	std::cout << "d4 address: " << &d4 << " d4= "; d4.show_distace();
	std::cout << "d5 address: " << &d5 << " d5= "; d5.show_distace();

	return 0;
}