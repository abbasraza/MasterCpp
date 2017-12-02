//
//  main.cpp
//  VirtualDtor2
//
//  Created by abbas raza on 3/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To show that only base class's dtor should be virtual. Rest follows rules mentioned in VirtualFunction2
 - Ctor order: A-->B-->C
 - Dtor order: C-->B-->A
*/

#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A ctor" << std::endl;
	}
	virtual ~A()
	{
		std::cout << "A dtor" << std::endl;
	}
};

class B : public A
{
public:
	B()
	{
		std::cout << "B ctor" << std::endl;
	}
	~B()
	{
		std::cout << "B dtor" << std::endl;
	}
};

class C : public B
{
public:
	C()
	{
		std::cout << "C ctor" << std::endl;
	}
	~C()
	{
		std::cout << "C dtor" << std::endl;
	}
};

int main(int argc, const char * argv[])
{
	C * c = new C;
	
	A * a = c;
	delete a;

	
	// Similar results will be achieved by this:
	//	B * b = c;
	//	delete b;
	
	return 0;
}

