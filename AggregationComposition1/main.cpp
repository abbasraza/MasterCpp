//
//  main.cpp
//  AggregationComposition1
//
//  Created by abbas raza on 7/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/*
 - Purpose of this program:
 - Composition/aggregation usage.
 
 - C has a A
   C has a B
 
     OR
 
   C consists of a A
   C consists of a B
 
		---
   ---⬥| C |⬥----
  |	    ---      |
  |              |
 ---            ---
| A |          | B |
 ---            ---

*/

#include <iostream>

class A
{
private:
	int dA;
public:
	A(int d = 0) : dA(d)
	{
		std::cout << "default ctor A() called" << std::endl;
	}
	void fA()
	{
		std::cout << "fA()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of A called" << std::endl;
	}
};

class B
{
private:
	int dB;
public:
	B(int d = 0) : dB(d)
	{
		std::cout << "default ctor B() called" << std::endl;
	}
	void fB()
	{
		std::cout << "fB()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of B called" << std::endl;
	}
};

class C
{
private:
	A objA;
	B objB;
	int dC;
public:
	C(int d1 = 0, int d2 = 0, int d3 = 0): dC(d1), objA(d2), objB(d3)
	{
		std::cout << "default ctor C() called" << std::endl;
	}
	void fC()
	{
		objA.fA();
		objB.fB();

		objA.fG();
		objB.fG();

		std::cout << "fC()" << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	C c1(1,2,3);
	// c1.objA.fA(); // no access to private data.
	c1.fC();
}