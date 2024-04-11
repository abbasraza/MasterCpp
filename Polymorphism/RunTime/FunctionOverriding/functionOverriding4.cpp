// C++ program to access overridden function
// in main() using the scope resolution operator ::

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
    c.print();

    // access print() function of the Base class
    c.Parent::print();
    return 0;
}
