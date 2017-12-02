//
//  main.cpp
//  VirtualDtor
//
//  Created by abbas raza on 3/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Explore virtual dtor.
 - If in polymorphic scenario
     Base * bptr = new Derived;
     delete bptr;
 
   This will call only the dtor of Base. Causing memory leak.
 - Therefore the dtor of Base class should always be virtual.
 - So base class of any level should have a virtual dtor.
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

int main(int argc, const char * argv[])
{
    A * a = new B;
    delete a; // this will call A dtor only, if A's dtor is not virtual
    
    return 0;
}
