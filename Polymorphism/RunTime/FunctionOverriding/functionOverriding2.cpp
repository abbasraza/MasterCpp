// C++ program to demonstrate function overriding
// by calling the overridden function
// of a member function from the child class

#include <iostream>
using namespace std;

class Parent
{
public:
    void print()
    {
        cout << "Base Function" << endl;
    }
};

class Child : public Parent
{
public:
    void print()
    {
        cout << "Derived Function" << endl;

        // call of overridden function
        Parent::print();
    }
};

int main()
{
    Child c;
    c.print();
    return 0;
}
