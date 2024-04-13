/*
In C++, when you derive a class from a base class, constructors of the base class are not inherited by the derived class.
This means that you cannot directly call or access the base class constructors from the derived class. 

However, the derived class does implicitly call the base class constructor as a part of its own construction process.
This happens automatically in the following ways:

1. Default Constructor: If the derived class does not explicitly call a base class constructor in its initialization list,
the default constructor of the base class is implicitly called.

2. Parameterized Constructor: If the derived class provides a parameterized constructor, it can explicitly call a
specific base class constructor in its initialization list using the member initializer syntax (`Derived::Derived(...) : Base(...)`).

3. Copy Constructor and Assignment Operator: Similar to constructors, copy constructors and assignment operators of the base
class are not inherited by the derived class. However, they are implicitly called by the corresponding operations of the derived
class if not overridden.

4. Destructors: Destructors are also not inherited, but the derived class destructor automatically calls the base class
destructor after completing its own destruction.

So, while constructors (and other special member functions) are not directly inherited, 
they are still crucial parts of the object initialization and destruction process in derived classes.

*/
#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Default Constructor" << std::endl;
    }

    Base(int x)
    {
        std::cout << "Base Parameterized Constructor: " << x << std::endl;
    }

    ~Base()
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
public:
    // Default constructor of Derived
    Derived()
    {
        std::cout << "Derived Default Constructor" << std::endl;
    }

    // Parameterized constructor of Derived calling parameterized constructor of Base
    Derived(int x) : Base(x)
    {
        std::cout << "Derived Parameterized Constructor: " << x << std::endl;
    }

    // Destructor of Derived
    ~Derived()
    {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main()
{
    // Creating a Derived object
    Derived d1;
    std::cout << std::endl;

    // Creating another Derived object with a parameter
    Derived d2(10);
    std::cout << std::endl;

    return 0;
}
