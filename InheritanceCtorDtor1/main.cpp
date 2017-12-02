//
//  main.cpp
//  InheritanceCtorDtor1
//
//  Created by abbas raza on 3/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To clarify in which order ctors and dtors are called if we use inheritance.
 - Rule is:
     On object creation, ctor of Base is called first then ctor of Derived is called.
     On object deletion, reverse i.e dtor of Derived is called first and then dtor of Base.
 
 - Reason:
 A derived class should be able to call methods and use data members of its base
 class. On the other hand, a base class does not normally call methods or use
 members of its derived class (generally, it doesn't know which derived class it'
 s a part of).
 
 For this reason, base class is constructed first and destroyed last, so that it'
 s valid while the constructor and destructor of its derived classes runs.
 
 There are many other scenarios that follow this pattern. For example, at the
 closing brace of a block, local variables declared in that block are destroyed
 in the reverse order of construction, because a variable created later could
 depend on the one created earlier.
 
 
 - Example:
 
 class A {
 protected:
    std::string name;
 public:
    virtual ~A() {
    }
 };

 class B : public A {
 public:
    virtual ~B() {
        std::cerr << "destroying object " << name << std::endl;
    }
 };
 
 so if we destroy A which is the Base first, then B will not be able to access its members.
 
 
*/
#include <iostream>

class A
{
public:
    A()
    {
        std::cout << "A ctor" << std::endl;
    }
    ~A()
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
    B * b = new B; // A ctor --> B ctor
    delete b; // B dtor --> A dtor
    
    return 0;
}

