// CPP Program to demonstrate derived class redefines base
// class member method

/*
In C++, function overloading is possible i.e., two or more functions from the same class
can have the same name but different parameters. However, if a derived class redefines
the base class member method then all the base class methods with the same name become hidden in the derived class. 
*/

#include <iostream>

class Base
{
public:
    void fun()
    {
        std::cout << "Base::fun() called" << std::endl;
    }

    void fun(int i)
    {
        std::cout << "Base::fun(int i) called" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Makes Base::fun() and Base::fun(int )
    // hidden
    void fun(char c)
    {
        std::cout << "Derived::fun(char c) called" << std::endl;
    }
};

// Driver Code
int main()
{
    Derived d;
    d.fun('e'); // No Compiler Error
    return 0;
}
