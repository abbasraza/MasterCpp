// CPP Program to demonstrate derived class redefines base
// class member method using the 'using' keyword

/*
In C++, function overloading is possible i.e., two or more functions from the same class
can have the same name but different parameters. However, if a derived class redefines
the base class member method then all the base class methods with the same name become hidden in the derived class. 
*/

// The 'using' keyword is used to unhide the hidden base class methods in the derived class.

#include <iostream>


class Base
{
public:
    void fun()
    {
        std::cout << "Base::fun() called" << std::endl;
    }
};

class Derived : public Base
{
public:
    using Base::fun;

    void fun(char c) // Makes Base::fun() unhidden
    {
        std::cout << "Derived::fun(char c) called" << std::endl;
    }
};

// Driver Code
int main()
{
    Derived d;
    d.fun(); // Works fine now
    return 0;
}