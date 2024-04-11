// C++ program to access overridden function using pointer
// of Base type that points to an object of Derived class
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
