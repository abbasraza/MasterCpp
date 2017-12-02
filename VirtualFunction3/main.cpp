//
//  main.cpp
//  VirtualFunction3
//
//  Created by abbas raza on 30/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 
 - Shows example of virtual functions.
 - See rules described in VirtualFunction2 folder.
 
*/
#include <iostream>

class A
{
public:
    virtual const char * getName() { return "A"; }
};

class B: public A
{
public:
    virtual const char * getName() { return "B"; }
};

class C: public B
{
public:
    // Note: no getName() function here
};

class D: public C
{
public:
    virtual const char * getName() { return "D"; }
};

int main()
{
    C c;
    A * a1 = &c;
    std::cout << a1->getName() << '\n';

    return 0;
}

