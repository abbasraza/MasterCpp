//
//  main.cpp
//  Distance1
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

/* Purpose of this program:
 - Object as data type example
 - Not using constructor i.e object data can contain garbage
   because not initialised.
*/

class Distance
{
private:
	int feet;
	float inch;
public:
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
	Distance d1;
	d1.show_distace(); // output can contain garbage values because class data no initialized.
	
	d1.set_distance(4, 2.6);
	d1.show_distace();
	
	d1.get_distance();
	d1.show_distace();

	return 0;
}