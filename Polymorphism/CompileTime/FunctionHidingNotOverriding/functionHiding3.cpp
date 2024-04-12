// C++ program to access hidden function
// in main() using the scope resolution operator ::

/* 
Function Hiding:

Function hiding occurs when a derived class defines a function with the same name
as a function in the base class, BUT the function in the base class is not marked as virtual.

In this case, the function in the base class is hidden by the function in the derived class.
However, this hiding only happens for functions in the base class that have the same name
as functions in the derived class. Other functions in the base class remain accessible
through the derived class.
*/


#include <iostream>

class Parent
{
public:
    void print()
    {
        std::cout << "Base Function" << std::endl;
    }
};

class Child : public Parent
{
public:
    void print()
    {
        std::cout << "Derived Function" << std::endl;
    }
};

int main()
{
    Child c;
    c.print();

    // access print() function of the Base class
    c.Parent::print();
    return 0;
}
