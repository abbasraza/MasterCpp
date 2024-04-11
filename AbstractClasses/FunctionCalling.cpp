//  Created by abbas raza on 20/08/2023.
//  Copyright © 2023 Self. All rights reserved.

/*
dynamic polymorphism:
~~~~~~~~~~~~~~~~~~~~

In both cases, you're calling the notPureVirtual() function. Since this function is virtual in both the base class
(AbstractBase) and the derived class (Derived), the function call is dynamically dispatched based on the actual type
of the object being used at runtime. This behavior is known as dynamic polymorphism.

When you call derivedObj.notPureVirtual(), you're directly calling the notPureVirtual() function of
the Derived class. This is because the object derivedObj is of type Derived.

When you call basePtr->notPureVirtual(), you're calling the notPureVirtual() function using a pointer
to the base class (AbstractBase). However, because the function is virtual, the actual function to
be called is determined by the runtime type of the object being pointed to. Since the object pointed
to by basePtr is of type Derived, the Derived::notPureVirtual() function is called.

This behavior illustrates the power of polymorphism in C++. The function called is determined by
the actual type of the object, allowing you to write code that works with base class pointers and
still correctly invokes the appropriate derived class functions.

*/

#include <iostream>

class AbstractBase
{
public:
    virtual void pureVirtual() = 0; // Pure virtual function
    virtual void notPureVirtual()
    {
        std::cout << "AbstractBase::notPureVirtual()" << std::endl;
    }
};

class Derived : public AbstractBase
{
public:
    void pureVirtual() override
    {
        std::cout << "Derived::pureVirtual()" << std::endl;
    }

    virtual void notPureVirtual()
    {
        std::cout << "Derived::notPureVirtual()" << std::endl;
    }
};

int main()
{
    Derived derivedObj;
    // AbstractBase abs; // Error: Can't create object of abstract class

    // Calling non-virtual function of Derived class via Derived object
    derivedObj.notPureVirtual(); // Calls Derived::nonVirtual()

    // Call non-virtual function of Derived class via pointer to base class
    AbstractBase *basePtr = &derivedObj;
    basePtr->notPureVirtual(); // Calls notPureVirtual() of Derived class

    return 0;
}
