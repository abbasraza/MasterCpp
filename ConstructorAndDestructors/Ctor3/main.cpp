//
//  main.cpp
//  Ctor3
//
//  Created by abbas raza on 3/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of default ctor.
 - If there is atleast 1 ctor in class, implicit default ctor is not added by compiler.
   i.e
   if you have this ctor in class:
   Distance(int f, float i) : feet(f), inch(i)
   {
   }
   you can't use below statement
   Distance d1;
 
 - Keep number of ctors in class to minumum.
 - New way to define ctor with default values:
	Distance() : feet(0), inch(0)
	{
	}
	
	OR
	
	Distance()
	{
	}
 
	is same as:
 
	Distance(int f = 0, float i = 0.0f) : feet(f), inch(i)
	{
	}
	
	So both of them can't co-exist.
	---------------------------------------------------------------
	
	Valid usage:
	===========
	Distance(int f, float i) : feet(f), inch(i)
	{
	}
 
	OR
	
	Distance(int f = 0, float i = 0.0f) : feet(f), inch(i)
	{
	}
 
	OR
	
	Distance(int f, float i = 0.0f) : feet(f), inch(i)
	{
	}
*/

#include <iostream>

class Distance
{
private:
	int feet;
	float inch;
public:
	/* This ctor can be 0-argument, 1-argument or 2-argument. both the parameters are optional.
	 ==>> if no parameter is provided: both parameters will take default vaules.
	 ==>> if first parameter is provided only: 2nd parameter will take default value.
	 ==>> if both parameters are provided: provided parameters will be used.
	*/
	Distance(int f = 0, float i = 0.0f) : feet(f), inch(i)
	{
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
	Distance d1; // calls ctor which we defined in class.
	Distance d2(14, 2.3f);
	Distance d3 = d2;
	Distance d4(6);

	std::cout << "d1 = "; d1.show_distace(); std::cout << std::endl;
	std::cout << "d2 = "; d2.show_distace(); std::cout << std::endl;
	std::cout << "d3 = "; d3.show_distace(); std::cout << std::endl;
	std::cout << "d4 = "; d4.show_distace(); std::cout << std::endl;

	return 0;
}