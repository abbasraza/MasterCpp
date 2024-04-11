// C++ program to demonstrate function overriding

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
    return 0;
}
