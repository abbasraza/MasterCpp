//
//  main.cpp
//  ExplicitKeyword
//
//  Created by abbas raza on 2/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of explicit 1 argument ctor. to prevent implicit conversion.
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
	explicit Distance(float in)
	{
		feet = in / 12;
		inch = in - (feet * 12);
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
};

int main()
{
	Distance d1(24.8f);
	Distance d2 = 37.3f; // this will result in error. We can't convert float to Distance implicitly here.
						// because the 1 argument ctor is explicit.
	Distance d3 = static_cast<Distance>(108.99f); // explicitly it works fine.

	std::cout << "d1 = "; d1.show_distace(); std::cout << std::endl;
	std::cout << "d3 = "; d3.show_distace(); std::cout << std::endl;

	return 0;
}