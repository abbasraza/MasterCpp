//
//  main.cpp
//  ConstMemberFunc
//
//  Created by abbas raza on 29/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//
#include <iostream>

/* Purpose of this program:
 - Usage of constant member function.
 - a.someconstfunc(); here someconstfunc() cannot modify data of a.
   someconstfunc() can modify any temp object of the same class created inside function.
   someconstfunc() can modify any non-constant argument passed to it of same class.
 - we should make those functions constant which are not supposed to modify/change any of 
   the object data. i.e display functions, etc
 - constructor/destructor can't be const functions.
 - from inside a const function, we can call only const functions of that class.
*/

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

	Distance(int f, float i) : feet(f), inch(i)
	{
		//std::cout << "initalizer list wala Ctor called on " << this << std::endl;
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
	Distance add_distance(Distance) const;
};

Distance Distance::add_distance(Distance d) const
{
	//feet = 0; // this will generate compile time error. can't be modified.
	// d.feet = 0; // argument can be modified.

	//this->get_distance(); // from a const func, we cannot call non-const func of that class.
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
	Distance d1(4,8);
	d1.show_distace(); // output can contain garbage values because class data no initialized.

	//d1.set_distance(4, 2.6);
	//d1.show_distace();

	//d1.get_distance();
	//d1.show_distace();

	Distance d2(3,3);
	d2.show_distace();

	Distance d3 = d1.add_distance(d2);
	d3.show_distace();

	return 0;
}