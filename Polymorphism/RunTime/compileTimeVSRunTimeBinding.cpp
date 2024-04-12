#include <iostream>
// This program demonstrates the difference between compile-time and run-time binding.

class Base
{
public:
    virtual void print()
    {
        std::cout << "print Base class" << std::endl;
    }

    void show()
    {
        std::cout << "show Base class" << std::endl;
    }
};

class Derived : public Base
{
public:
    // print () is already virtual function in
    // Derived class, we could also declared as
    // virtual void print () explicitly
    void print()
    {
        std::cout << "print Derived class" << std::endl;
    }

    void show()
    {
        std::cout << "show Derived class" << std::endl;
    }
};

int main()
{
    Base *bptr;
    Derived d;
    bptr = &d;

    // Virtual function, binded at
    // runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, binded
    // at compile time
    bptr->show();

    return 0;
}
