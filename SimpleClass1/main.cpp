//
//  main.cpp
//  SimpleClass1
//
//  Created by abbas raza on 26/09/2017.
//  Copyright © 2017 Self. All rights reserved.
//

#include <iostream>

/* Purpose of this program:
 - Just to show a basic class, data and member functions.
*/

class smallobj
{
private:
	int data;
public:
	void set_data(int v) // will this be an inline function when object is instantiated??
	{
		data = v;
	}
	void show_data()
	{
		std::cout << "data = " << data << std::endl;
	}
	/*
	void set_data(int v); // functions declared inside and defined outside
	void show_data(); // functions declared inside and defined outside
	 */
};

/*
void smallobj::set_data(int v) // Will this be non inline function?
{
	data = v;
}

void smallobj::show_data()
{
	std::cout << "data = " << data << std::endl;
}
*/
int main(int argc, const char * argv[])
{
	smallobj obj1;   // memory set aside for this object at this Object instantiation. functions memory??
	// is obj1 a memory space or pointer to memory space???
	obj1.show_data();
	obj1.set_data(10);
	obj1.show_data();
    return 0;
}
