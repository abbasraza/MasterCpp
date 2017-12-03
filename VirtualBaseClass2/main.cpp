//
//  main.cpp
//  VirtualBaseClass2
//
//  Created by abbas raza on 4/12/17.
//  Copyright © 2017 Self. All rights reserved.
//


/* Purpose of this program:
 - Explore virtual base class in single inheritance scenario.
 - If a class inherits one or more classes that have virtual parents,
   the most derived class is responsible for constructing the virtual base class.

 ---
| A |
 ---
  ^
  |
  |
 ---
| B |
 ---
  ^
  |
  |
 ---
| C |
 ---
 
 So here C is responsible for constructing A.

*/

#include <iostream>

class A
{
private:
	int var_a;
public:
	A(int v) : var_a(v)
	{
		std::cout << "Ctor of A" << std::endl;
	}
	void fA()
	{
		std::cout << "fA() var_a = " << var_a  << std::endl;
	}
};

class B : virtual public A
{
private:
	int var_b;
public:
	B(int v1, int v2) : A(v1), var_b(v2)
	{
		std::cout << "Ctor of B" << std::endl;
	}
	void fB()
	{
		std::cout << "fB() var_b = " << var_b << std::endl;
	}
};

class C : public B
{
private:
	int var_c;
public:
	C(int v1, int v2, int v3) : var_c(v1), A(v2), B(v2, v3)
	{
		std::cout << "Ctor of C" << std::endl;
	}
	void fC()
	{
		std::cout << "fC() var_c = " << var_c << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	C c(1,2,3);
	c.fC();
	return 0;
}
