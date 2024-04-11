/*
If we have a function in base class and another function with the same name in derived class,
can the base class function be called from derived class object? 
This is an interesting question and as an experiment, as shown in the code below.

Overloading doesn’t work for derived class in the C++ programming language.
There is no overload resolution between Base and Derived.
The compiler looks into the scope of Derived, finds the single function “double f(double)” and calls it.
It never disturbs the (enclosing) scope of Base.
In C++, there is no overloading across scopes and derived class scopes are not an exception to this general rule.
*/

#include <iostream>
class Base
{
public:
    int f(int i)
    {
        std::cout << "f(int): " << std::endl;
        return i + 3;
    }
};

class Derived : public Base
{
public:
    double f(double d)
    {
        std::cout << "f(double): " << std::endl;
        return d + 3.3;
    }
};

int main()
{
    Derived d;
    d.f(3); // Calls Derived::f(double)
    d.f(3.3); // Calls Derived::f(double)

    return 0;
}
