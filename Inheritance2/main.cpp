//
//  main.cpp
//  Inheritance2
//
//  Created by abbas raza on 3/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - ctor and inheritance.
 - To create a child, first a parent will be created then child.
 - Here:
	D = derived
	B = base

 - When a D object is created:
   1) The ctor of D is called.
   2) 
       i)  If there is a ctor of B specified in initializer list of ctor of D, then that ctor of B will be called.
       OR
       ii) Otherwise default no-arg ctor of B will be called. If there is no default no-arg ctor in B (implicit or
		   user defined), then it will create problem.
   3) ctor of B (whichever from step 2) is executed.
   4) ctor of D is executed.

 - D shouldn't modify data of B directly. Should be done via calling appropriate ctor of B in D.
   D ctor can't initialize B members in initializer list. Instead should call appropriate B ctor 
   in initializer list of D's ctor.

 - D doesn't inherit ctor from B.

*/

#include <iostream>

class Counter
{
protected:
	int count;
public:
	Counter() : count(10)
	{
		std::cout << "Counter(): count=" << count << std::endl;
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
	CountDown(int v = 0) : Counter(v) // specifying which ctor of Counter to execute.
	{
		
	}
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
	
	CountDown c2; // ctor calling order as mentioned above.
	++c2;
	++c2;
	++c2;
	++c2;
	--c2;
	std::cout << "c2 = " << c2.get_count() << std::endl;
	
	CountDown c3(10);
	std::cout << "c3 = " << c3.get_count() << std::endl;

	return 0;
}