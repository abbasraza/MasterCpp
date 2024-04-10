//
//  main.cpp
//  ctor2
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Use of constructor initializer list for const data.
 - In this case, when constructor is called, data is declared and initialized at same time
   with values given in initializer list.
 */

#include <iostream>

class Distance
{
private:
	int feet;
	float inch;
	const int temp;
public:
	// constructor has no return type
	Distance():feet(1), inch(0.1), temp(7)// initializer list. initialize to 0 or any other hard-coded value
	{
		std::cout << "Constructor called" << std::endl;
	}
	void set_distance(int f, float i)
	{
		feet = f;
		inch = i;
	}
	void show_distace()
	{
		std::cout << "Distance = " << feet << " feet and " << inch << " inches" << std::endl;
		std::cout << "const temp contains " << temp << std::endl;
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
	
	std::cout << "Default distance" << std::endl;
	d1.show_distace(); // output can contain garbage values because class data no initialized.
	
	d1.set_distance(4, 2.6);
	d1.show_distace();
	
	d1.get_distance();
	d1.show_distace();
	
	return 0;
}