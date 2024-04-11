//
//  main.cpp
//  PureVirtualFunction1
//
//  Created by abbas raza on 3/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Explore pure virtual functions. = 0 at the end which just tells compiler that virtual function is pure.
 - Abstract class. A class for which we don't ever want/need to create an object. For example Animal class.
   We never create Animal object but we create Cat, Dog objects. So we can make Animal class abstract by
   making virtual function the pure virtual function.
 - Objects of abstract class can't be created.
 - Any derived class should override the base class's pure virtual functions. Otherwise derived will become
   abstract too and we won't be able to create the objects of derived class.
 - Atlease one function is pure virtual, then class becomes abstract.
 - Useful when we want derived classes to provide definition of function by themselves. If they forget, error will
   be reported by compiler.
 - A pure virtual function can have body. Can't do inline. This means base is providing the derived classes a sample
   implementation of that function. Its upto derived class to use it (by calling directly inside the overriden function)
   or not.
 - Non virtual functions can't be made = 0;
 - virtual can only be used inside class definition.
*/

#include <iostream>

class A
{
public:
    A()
    {
        
    }
    virtual void show() = 0;
    //void show2() = 0; // can't do this.
};

// we can do this.
//void A::show()
//{
//
//}

class B : public A
{
public:
    void show() // if no overriding, then B becomes abstract
    {
        //A::show(); // this will fail if there is no definition of pure virtual function show();
        std::cout << "show() of derived called" << std::endl;
    }
};

int main(int argc, const char * argv[])
{
    //A a; // error. cant create object of abstract class.
    B b;
    b.show();
    
    return 0;
}
