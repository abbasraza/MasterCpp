//
//  main.cpp
//  Inheritance1
//
//  Created by abbas raza on 2/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Introduction to inheritance.
 
 - Here:
	D = derived
	B = base

 - Private and public inheritance.

 - Use of protected data member. can be accessed by D class but not by public.

 - Data & functions of B which can be accessed directly (using dot operator)
	- Inside class:
		B --> all
		D --> all except private
	- By Objects of:
		B and Publicly D class --> only public
		Privately D class --> none
 
 - When we derive a class from B, the B class says to D:
 - You can't access my private data directly.
 - You can use my no argument ctor. ??? TODO wrong see Inheritance2
 - (public inheritance): Your objects can only access my public stuff directly.
 - (private inheritance): Your objects cannot access any of my stuff directly.

 - If D (no matter public or private) class doesn't have a no argument ctor, the ctor of B is called when object of
   D class is created. ?? TODO wrong. see Inheritance2
 
 - class CountDown : Counter
   {
   }
   This means private inheritance.
 
 - When to use private inheritance? : when hiding B completely from D's objects.
*/

#include <iostream>

class Counter
{
protected:
	int count;
public:
	Counter() : count(10)
	{
		std::cout << "No argument ctor of Counter called" << std::endl;
	}
	Counter(int c) : count(c)
	{
		std::cout << "1 argument ctor of Counter called" << std::endl;
	}
	int get_count() const
	{
		return count;
	}
	Counter operator ++ ()
	{
		return Counter(++count);
	}
};

class CountDown : public Counter // public inheritance
{
public:
	Counter operator -- ()
	{
		return Counter(--count);  // here we can access count variable directly because of protected.
								  // here we can access Counter 1 argument ctor because of public.
	}
};

int main()
{
	Counter c1;
	++c1;
	std::cout << "c1 = " << c1.get_count() << std::endl;
	//--c1; // fail. B can't use D class's functions.

	CountDown c2; // No argument ctor of B class called.
	++c2;
	++c2;
	++c2;
	++c2;
	--c2;
	std::cout << "c2 = " << c2.get_count() << std::endl;

//	CountDown c3(10); // fail. D class doesn't have 1 argument ctor.
	return 0;
}