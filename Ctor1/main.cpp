//
//  main.cpp
//  Ctor1
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

/* Purpose of this program:
 - Why initializing data inside body of constructor is not preffered. i.e const can't be initialized like this
 - Note: this program will generate build errors which is expected.
 - This is similar to:
	const int t; --> error
	t = 0;
 - In this case, when constructor is called, data is declared first and then initialized later.
 */

class Distance
{
private:
	int feet;
	float inch;
	const int temp;
public:
	// constructor has no return type
	Distance() // no arguments, no initializer list.
	{
		/* this initialization technique is not recommended. see other examples */
		std::cout << "Constructor called" << std::endl;
		feet = 0;
		inch = 0;
		temp = 0;
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
	std::cout << "Before instantiating" << std::endl;
	Distance d1; // Constructor is called when object defined.
	std::cout << "After instantiating" << std::endl;
	Distance d2;
	
	d1.show_distace(); // output can contain garbage values because class data no initialized.
	
	d1.set_distance(4, 2.6);
	d1.show_distace();
	
	d1.get_distance();
	d1.show_distace();
	
	return 0;
}