/**
 * @file functionHidingAndBasePtr.cpp
 * @brief This program demonstrates the concept of function hiding and accessing hidden function
 * using a pointer of base type that points to an object of derived class.
 */

/* 
Calling a non-virtual function will use the function from the same class as the pointer type,
regardless of whether the object was actually created as some other derived type.
*/

/* C++ Primer, Fifth Edition:
=============================

When we call a function defined in a base class through a reference or pointer
to the base class, we do not know the type of the object on which that member
is executed. The object can be a base-class object or an object of a derived class.

if function is virtual:
    If the function is virtual, then the decision as to which function to run is delayed
    until run time. The version of the virtual function that is run is the one defined by
    the type of the object to which the reference is bound or to which the pointer
    points.

calls to nonvirtual functions are bound at compile time:
    On the other hand, calls to nonvirtual functions are bound at compile time.

calls on an object:  
    Similarly, calls to any function (virtual or not) on an object are also bound at
    compile time. The type of an object is fixed and unvarying—there is nothing we
    can do to make the dynamic type of an object differ from its static type.

When are virtuals resolved at run time:
    Virtuals are resolved at run time only if the call is made through a
    reference or pointer. Only in these cases is it possible for an object’s
    dynamic type to differ from its static type.
*/

#include <iostream>

class Parent
{
public:
    /**
     * @brief Prints "Base Function".
     */
    void print()
    {
        std::cout << "Base Function" << std::endl;
    }
};

class Child : public Parent
{
public:
    /**
     * @brief Prints "Derived Function".
     */
    void print()
    {
        std::cout << "Derived Function" << std::endl;
    }
};

int main()
{
    Child c;

    // pointer of Parent type that points to c
    Parent *ptr = &c;

    // call function of Base class using ptr
    ptr->print();

    return 0;
}
