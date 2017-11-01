//
//  main.cpp
//  UserDefinedTypeConversion
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - User defined type to basic type conversion --> Done using conversion operator.
 - Basic type to user defined type conversion --> Done using 1 argument ctor (called conversion ctor).
 - Conversion operator doesn't have any return type and parameters.
	operator float()
	{
		return a float;
	}
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
	Distance(float in)
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
	operator float () const; // no return type, no parameter.
};

Distance::operator float () const
{
	return feet * 12 + inch;
}

int main()
{
	/* 2 argument ctor ways to use */
	Distance d1(9, 9.3f);
	Distance d2 = {9, 9.3f};
	Distance d3;
	d3 = {9, 9.3f};

	/* 1 argument ctor ways to use. argument is in inches */
	Distance d4(24.6f);
	Distance d5 = 37.3f;
	Distance d6;
	d6 = 108.99f;

	std::cout << "d1 = "; d1.show_distace(); std::cout << std::endl;
	std::cout << "d2 = "; d2.show_distace(); std::cout << std::endl;
	std::cout << "d3 = "; d3.show_distace(); std::cout << std::endl;
	std::cout << "d4 = "; d4.show_distace(); std::cout << std::endl;
	std::cout << "d5 = "; d5.show_distace(); std::cout << std::endl;
	std::cout << "d6 = "; d6.show_distace(); std::cout << std::endl;

	/******** User defined type to basic type conversion ********/

	//float inches = d1; // implicit type casting works.
	float inches = static_cast<float>(d1); // explicit type casting also works.
	std::cout << "inches in d1 = " << inches << std::endl;

	
	/******** Basic type to user defined type conversion ********
	 This is done basically using 1 argument ctor
	*/
	
	//d1 = static_cast<Distance>(100.4f); // 1 argument ctor called.
	d1 = 100.4f; // 1 argument ctor called.

	std::cout << "d1 from float = "; d1.show_distace(); std::cout << std::endl;

	return 0;
}