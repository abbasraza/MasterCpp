// C++ program to demonstrate how we will calculate
// area of shapes without virtual function
#include <iostream>

/* 
Calling a non-virtual function will use the function from the same class as the pointer type,
regardless of whether the object was actually created as some other derived type.
*/

/* C++ Primer, Fifth Edition:
=============================

When we call a function defined in a base class through a reference or pointer
to the base class, we do not know the type of the object on which that member
is executed. The object can be a base-class object or an object of a derived class.

if function is virtual:
    If the function is virtual, then the decision as to which function to run is delayed
    until run time. The version of the virtual function that is run is the one defined by
    the type of the object to which the reference is bound or to which the pointer
    points.

calls to nonvirtual functions are bound at compile time:
    On the other hand, calls to nonvirtual functions are bound at compile time.

calls on an object:  
    Similarly, calls to any function (virtual or not) on an object are also bound at
    compile time. The type of an object is fixed and unvarying—there is nothing we
    can do to make the dynamic type of an object differ from its static type.

When are virtuals resolved at run time:
    Virtuals are resolved at run time only if the call is made through a
    reference or pointer. Only in these cases is it possible for an object’s
    dynamic type to differ from its static type.
*/


// Base class
class Shape
{
public:
    // parameterized constructor
    Shape(int l, int w)
    {
        length = l;
        width = w;
    }
    int get_Area()
    {
        std::cout << "This is call to parent class area\n";
        // Returning 1 in user-defined function means true
        return 1;
    }

protected:
    int length, width;
};

// Derived class
class Square : public Shape
{
public:
    Square(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
    // constructor
    int get_Area()
    {
        std::cout << "Square area: " << length * width << '\n';
        return (length * width);
    }
};
// Derived class
class Rectangle : public Shape
{
public:
    Rectangle(int l = 0, int w = 0)
        : Shape(l, w)
    {
    } // declaring and initializing derived class
    // constructor
    int get_Area()
    {
        std::cout << "Rectangle area: " << length * width
             << '\n';
        return (length * width);
    }
};

int main()
{
    Shape *s;

    // Making object of child class Square
    Square sq(5, 5);

    // Making object of child class Rectangle
    Rectangle rec(4, 5);

    s = &sq; // reference variable
    s->get_Area();
    
    s = &rec; // reference variable
    s->get_Area();

    return 0;
}
