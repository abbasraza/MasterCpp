//
//  main.cpp
//  Inheritance1
//
//  Created by abbas raza on 2/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Introduction to inheritance.

 - Private and public inheritance.

 - Use of protected data member. can be accessed by derived class but not by public.

 - Data & functions of Base which can be accessed directly (using dot operator)
	- Inside:
		Base --> all
		Derived --> all except private
	- By Objects of:
		Base and Publicly derived class --> only public
		Privately derived class --> none
 
 - When we derive a class from Base, the Base class says to derived:
 - You can't access my private data directly.
 - You can use my no argument ctor. ??? TODO wrong see Inheritance2
 - (public inheritance): Your objects can only access my public stuff directly.
 - (private inheritance): Your objects cannot access any of my stuff directly.

 - If derived (no matter public or private) class doesn't have a no argument ctor, the ctor of Base is called when object of
   derived class is created. ?? TODO wrong. see Inheritance2

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
	//--c1; // fail. Base can't use Derived class's functions.

	CountDown c2; // No argument ctor of Base class called.
	++c2;
	++c2;
	++c2;
	++c2;
	--c2;
	std::cout << "c2 = " << c2.get_count() << std::endl;

//	CountDown c3(10); // fail. Derived class doesn't have 1 argument ctor.
	return 0;
}