//
//  main.cpp
//  Inheritance3
//
//  Created by abbas raza on 6/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Single inheritance and need of scope resolution.
 
 ---
| A |
 ---
  ^
  |
  |
 ---
| B |
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
};

int main()
{
	B b1;

	b1.fB();
	b1.fA();
	b1.A::fA();

	return 0;
}
