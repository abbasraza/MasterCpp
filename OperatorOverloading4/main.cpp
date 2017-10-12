//
//  main.cpp
//  OperatorOverloading4
//
//  Created by abbas raza on 12/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of == overloaded operator.
 - float + int arithmetic conversion = float.
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
	bool operator == (const Distance&) const;

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

bool Distance::operator == (const Distance& d) const
{
	return (feet * 12 + inch) == (d.feet * 12 + d.inch); // int + float = float ? YES. See ArithmeticConversions.
}

int main()
{
	Distance d1(9, 9.33);
	Distance d2(4, 1);
	Distance d3(9, 9.33);

	std::cout << "d1 and d2 are" << (d1 == d2 ? "" : " not") << " equal" << std::endl;
	std::cout << "d1 and d3 are" << (d1 == d3 ? "" : " not") << " equal" << std::endl;

	return 0;
}