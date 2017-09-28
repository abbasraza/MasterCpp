//
//  main.cpp
//  ReturnObj
//
//  Created by abbas raza on 27/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Return object from functions.
 - usage of copy ctor.
*/

#include <iostream>

class Distance
{

private:
	int feet;
	float inch;
public:
	Distance():feet(0), inch(0.0) // initializer list. initialize to 0 or any other hard-coded value
	{
		std::cout << "no-arg Ctor called on " << this << std::endl;
	}
	
	Distance(int f, float i) : feet(f), inch(i)
	{
		std::cout << "initalizer list wala Ctor called on " << this << std::endl;
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

	~Distance()
	{
		std::cout << "dtor called on " << this << std::endl;
	}

	Distance add_distance(Distance);
};


Distance Distance::add_distance(Distance d)
{
	std::cout << "Argument to add distance is " << &d << std::endl;

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
	Distance d1(8, 11.0); // initializer list ctor will be called and object will be created.
	Distance d2(4,9); // initializer list ctor will be called and object will be created.
	
	std::cout << "before add distance" << std::endl;
	
	
	/* 2 Cases:
	 Case 1:
	 Distance d3; // no argument ctor will be called and object will be created.
	 d3 = d1.add_distance(d2);  // Add d1 into d2 and return sum
	 in above statement, the default copy ctor will be called and the return of add_distance
	 will be copied to d3. return object will be destroyed then.
	 i.e sum in this case.

	 Case 2:
	 Distance d3 = d1.add_distance(d2);  // Add d1 into d2 and return sum
	 in above statement, no default copy ctor will be called. d3 will be same as the return of add_distance.
	 i.e sum in this case. address of d3 will be = to address of return of add_distance.
	 */

	Distance d3 = d1.add_distance(d2);
	std::cout << "after add distance" << std::endl;
	std::cout << "d3 is " << &d3 << std::endl;

	
	/* there is only one show_distance function of class Distance.
	 which is shared among all its objects.
	 Can be checked easily by viewing he address of show_distance. in debugger
	 */
	d1.show_distace();
	d2.show_distace();
	
	std::cout << "d3="; d3.show_distace();
	
	/* Ways to declare/initialize objects
	 
		Distance dA; // no argument ctor
		Distance dB(1,2); // initializer list ctor
	 
		Distance dC = dA.add_sum(); // no default copy ctor called?? return of add_sum will be same as dC.
									// will be destroyed when dC destroys
		Distance dD = dA; // default copy ctor
		Distance dE(dA); // default copy ctor
	 
		Distance dF; // no argument ctor will be called
		dF = dA; // default copy ctor will only copy members of dA to dF. address of dF will remain same as in above step.
		later
		dF = dB; // default copy ctor will only copy members of dA to dF. address of dF will remain same as in above step.
	 */
	
	d3 = d1; // d3 address remains same. only members copies.
	std::cout << "d3 is " << &d3 << std::endl;
	
	std::cout << "d3="; d3.show_distace();
	Distance d4;
	
	d4 = d1; // d4 address remains same
	d4 = d2; // d4 address remains same
	d4 = d3; // d4 address remains same
	std::cout << "d4 is " << &d4 << std::endl;
	
	return 0;
}