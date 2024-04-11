//
//  main.cpp
//  OperatorOverloading5
//
//  Created by abbas raza on 31/10/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of += overloaded operator.
*/

#include <iostream>

class Distance
{
private:
	int feet;
	float inch;
public:
	// constructor has no return type
	Distance():feet(0), inch(0.0f) // initializer list. initialize to 0 or any other hard-coded value
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
	Distance operator += (const Distance&);
};

Distance Distance::operator += (const Distance& d)
{
	feet += d.feet;

	if (inch + d.inch >=12)
	{
		feet += 1;
		inch += d.inch - 12;
	}
	else
	{
		inch += d.inch;
	}

	//return Distance(feet, inch);
	return *this;
}

int main()
{
	Distance d1(9, 9.3f);
	Distance d2(4, 1.0f);
	Distance d3;

	d1 += d2;
	d1.show_distace();
	
	d3 = d1 += d2;
	d3.show_distace();

	return 0;
}