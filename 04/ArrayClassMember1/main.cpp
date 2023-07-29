//
//  main.cpp
//  ArrayClassMember1
//
//  Created by abbas raza on 8/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Usage of array of integers inside class.
 - Array initialization in no-argument constructor.
 - Array initialization in argument wala constructor.
 - Usage of compile time constants in class (for defining lenght of array). 
   They don't have addresses. compiler will place constant values where ever its used.
 - Usage of defining constructors outside class.
 - Calling constructor manually. ?? TODO
 - Providing object data in rvalue. ?? TODO . This calls argument wala constructor.
 - Static const/variable inside a function are stored in bss. Just like globals variables.
 - Non static variables/constants define inside function are stored on stack.
*/

#include <iostream>

class foo
{
	static const int max = 10; // this is compile time constant. It doesn't have any address unless its defined outside class.
	int ar[max];
public:
	foo();
	foo(int []);
	void show_foo();
};

/* If we don't need to access address of 'max' then we don't need to define max */
const int foo::max; // this will assign max address.

/* Initializing array to default values */
foo::foo(): ar{1,2,3}
{
	
}

/* Initializing array equal to given values/array */
foo::foo(int v[])
{
	std::cout << "argument wala ctor called" << std::endl;
	// ar = v; // we can't simply do this.

	for (int i = 0; i < max; ++i)
	{
		ar[i] = v[i];
	}
}

void foo::show_foo()
{
	std::cout << "address of array " << ar << std::endl;
	
	/* If we don't need to access address of 'max' then we don't need to define max */
	std::cout << "address of max " << &max << std::endl; // we can only do this if max is defined outside class.

	for(int i = 0; i < max; ++i)
	{
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;
}

int global_variable = 0;

int main(int argc, const char * argv[])
{
	static const int v1 = 100;
	std::cout << "Address of v1 (local static const int) = " << &v1 << std::endl;
	
	const int v2 = 100;
	std::cout << "Address of v2 (local const int) = " << &v2 << std::endl;

	static int v3 = 100;
	std::cout << "Address of v3 (local static  int) = " << &v3 << std::endl;

	std::cout << "Address of global_variable = " << &global_variable << std::endl;

	/* Can we call constructor manually like this. ?
	   instead of 
	   foo f0;
	 TODO
	*/
	foo f0 = foo::foo();
	f0.show_foo();

	std::cout << "Address of f0 " << &f0 << std::endl;

	foo f1;
	f1.show_foo();

	/* We know this way of using ctor */
	foo f2((int [10]){1,3,4,5,6});
	f2.show_foo();

	/* Is this valid way to define object
	   i.e not giving data in arguments of ctor but as rvalue ?? 
	 TODO
	*/
	std::cout << "!!!!!!! f3 !!!!!!!" << std::endl;
	foo f3 = (int [10]){11,13,14,15,16}; // This calls argument wala constructor.
	f3.show_foo();

	return 0;
}