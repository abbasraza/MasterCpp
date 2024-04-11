//
//  main.cpp
//  OperatorOverloading6
//
//  Created by abbas raza on 1/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Operator [] overloading.
 - Return by reference.
*/

#include <iostream>

class safearray
{
	static const int max = 10; // this is compile time constant. It doesn't have any address unless its defined outside class.
	int ar[max];
public:
	safearray();
	safearray(int []);
	void show_safearray();
	int& operator [](int index);
};


/* Initializing array to default values */
safearray::safearray(): ar{1,2,3}
{
	
}

/* Initializing array equal to given values/array */
safearray::safearray(int v[])
{
	std::cout << "argument wala ctor called" << std::endl;
	// ar = v; // we can't simply do this.
	
	for (int i = 0; i < max; ++i)
	{
		ar[i] = v[i];
	}
}

void safearray::show_safearray()
{
	for(int i = 0; i < max; ++i)
	{
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;
}

int& safearray::operator [](int index)
{
	if (index < max)
	{
		return ar[index];
	}
	std::cout << "index out of bounds error" << std::endl;
	exit(1);
}

int main(int argc, const char * argv[])
{
	safearray a1;
	
	a1.show_safearray();
	
	std::cout << "a1[1] = " << a1[1] << std::endl;
	a1[1] = 10;
	std::cout << "a1[1] = " << a1[1] << std::endl;
	
	int& t1 = a1[1];
	t1 = 17;
	std::cout << "a1[1] = " << a1[1] << std::endl;

	a1[200] = 20;
	a1.show_safearray();
	std::cout << "a1[200] = " << a1[200] << std::endl;

	return 0;
}