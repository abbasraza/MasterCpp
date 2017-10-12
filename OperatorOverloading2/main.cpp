//
//  main.cpp
//  OperatorOverloading2
//
//  Created by abbas raza on 12/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
  - Usage of Binary operator overloading. +
  - The object on left of the operator is always the object whose overloaded function is called.
	i.e 
		d3 = d1 + d3;
	here d1's overloaded function will be called.
  - Number of arguments required in overloaded function are NUMBER_OF_OPERANDS_OPERATION_REQUIRES - 1; (not true for friends??)
    i.e Unary operation requires only 1 operand. so No arguments in the overloaded unary operator function.
		Binary operation requires 2 operands. so 1 argument is needed in the overloaded binary operator function.
  -
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
	Distance operator + (const Distance&) const;
};

Distance Distance::operator + (const Distance& d) const
{
	std::cout << "operator overloaded function called of object " << this << std::endl;
	std::cout << "operator overloaded function has argument object " << &d << std::endl;

	Distance sum;
	
	sum.feet = feet + d.feet;
	
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

/*
Distance Distance::add_distance(Distance& d)
{
	std::cout << "Argument to add distance is " << &d << std::endl;
	//d.feet = 4; // this will throw error if d is const.
	// if d modified, it will reflect in original passed as argument.
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
*/

int main()
{
	Distance d1(9, 9);
	Distance d2(4, 11);

	std::cout << "d1 address: " << &d1 << " d1= "; d1.show_distace();
	std::cout << "d2 address: " << &d2 << " d2= "; d2.show_distace();

	Distance d3 = d1 + d2; // Here operator overloaded function of d1 will be called. d2 will be passed as argument.
	std::cout << "d3 address: " << &d3 << " d3= "; d3.show_distace();

	/* overloaded + of d1 will be called with d2 as argument.
	   overloaded + of result of above operation will be called with d3 as argument.
	   so below statement is similar to
	   d4 = ((d1 + d2) + d3);
	*/
	Distance d4 = d1 + d2 + d3;
	std::cout << "d4 address: " << &d4 << " d4= "; d4.show_distace();

	return 0;
}