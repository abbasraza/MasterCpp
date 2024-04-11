#include <iostream>
using namespace std;

class MyClass
{
public:
    static int myStaticVariable;
    int myNonStaticVariable;
};

// Definition of the static member variable
int MyClass::myStaticVariable = 5;

// This will give error similar to below:
// a nonstatic member reference must be relative to a specific object
// a nonstatic data member may not be defined outside its class
//int MyClass::myNonStaticVariable = 5; // Error: 'int MyClass::myNonStaticVariable' is not a static data member of 'class MyClass'

int main()
{
    // Accessing the static member variable using the class name
    cout << MyClass::myStaticVariable << endl; // Output: 5

    // Modifying the static member variable using the class name
    MyClass::myStaticVariable = 10;

    // Accessing the modified static member variable using the class name
    cout << MyClass::myStaticVariable << endl; // Output: 10
    
    // This will give error
    // a nonstatic member reference must be relative to a specific object
    //MyClass::myNonStaticVariable = 10;

    return 0;
}
