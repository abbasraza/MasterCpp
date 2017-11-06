//
//  main.cpp
//  Inheritance6
//
//  Created by abbas raza on 6/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Multiple inheritance and scope resolution.
 - A and B both have functions fG().

 ---        ---
| A |      | B |
 ---        ---
  ^          ^
  |          |
  |          |
  |   ---    |
   --| C | --
	  ---

*/
#include <iostream>

class A
{
public:
	void fA()
	{
		std::cout << "fA()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of A" << std::endl;
	}
};

class B
{
public:
	void fB()
	{
		std::cout << "fB()" << std::endl;
	}
	void fG()
	{
		std::cout << "fG() of B" << std::endl;
	}
};

class C : public A, public B
{
public:
	void fC()
	{
		fA();
		A::fA();
		
		fB();
		B::fB();
		
		// fG(); // error
		A::fG();
		B::fG();

		std::cout << "fC()" << std::endl;
	}
};

int main()
{
	C c1;
	
	c1.fA();
	c1.A::fA();
	
	c1.fB();
	c1.B::fB();
	
	// c1.fG(); // error
	c1.A::fG();
	c1.B::fG();

	return 0;
}