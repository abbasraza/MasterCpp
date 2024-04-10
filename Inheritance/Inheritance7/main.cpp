//
//  main.cpp
//  Inheritance7
//
//  Created by abbas raza on 6/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Multiple inheritance and scope resolution.
 - The Diamond problem. Deadly diamond of death.
 
	    ---
   --> | A | <--
  |     ---     |
  |             |
  |             |
 ---           ---
| B |         | C |
 ---           ---
  ^             ^
  |             |
  |             |
  |     ---     |
   --- | D | ---
	    ---

*/
#include <iostream>

class A
{
public:
	A()
	{
	}
	void fA()
	{
		std::cout << "fA()" << std::endl;
	}
};

class B : public A
{
public:
	void fB()
	{
		fA();
		A::fA();

		std::cout << "fB()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of B" << std::endl;
	}
};

class C : public A
{
public:
	void fC()
	{
		fA();
		A::fA();

		std::cout << "fC()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of C" << std::endl;
	}
};

class D : public B, public C
{
public:
	D()
	{
	}
	void fD()
	{
		//fA(); // error. We have 2 copies of fA()
		//A::fA(); // error. We have 2 copies of A

		B::fA();

		// Why can we do this ? Aren't there 2 copies of A() too ?
		// A a1 = A();
		// a1.fA();

		C::fA();

		fB();
		fC();

		//fG(); //error
		B::fG();
		C::fG();

		std::cout << "fC()" << std::endl;
	}
};

int main()
{
	D d1;

	//d1.fA(); // error
	//d1.A::fA(); // error
	d1.B::fA();
	d1.C::fA();

	d1.fB();
	d1.fC();

	//d1.fG(); //error
	d1.B::fG();
	d1.C::fG();

	d1.fD();

	return 0;
}