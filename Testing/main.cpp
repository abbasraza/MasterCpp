//
//  main.cpp
//  Testing
//
//  Created by abbas raza on 16/10/2017.
//  Copyright © 2017 Self. All rights reserved.
//
#include <iostream>

class A
{
public:
    A() { std::cout << getName(); } // note addition of constructor
    
    virtual const char* getName() { return "A"; }
};

class B : public A
{
public:
    virtual const char* getName() { return "B"; }
};

class C : public B
{
public:
    virtual const char* getName() { return "C"; }
};

class D : public C
{
public:
    virtual const char* getName() { return "D"; }
};

int main()
{
    C c;
    
    return 0;
}
