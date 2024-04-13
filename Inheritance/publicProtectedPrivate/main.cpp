/*
Following table shows the accessibility of base class members in derived class
based on the inheritance type.

To simply understand the table, consider the following:

- Public inheritance:
Public members of the base class become public members of the derived class.
Protected members of the base class become protected members of the derived class.
Private members of the base class are not accessible in the derived class.

Also the program below demonstrates the same.

---------------------------------------------------------------
| Inheritance Type | Base Class Member | Derived Class Member |
|------------------|-------------------|----------------------|
|                  | Public            | Public               |
|                  |-------------------|-----------------------
|   Public         | Protected         | Protected            |
|                  |-------------------|-----------------------
|                  | Private           | Not accessible       |
|------------------|-------------------|----------------------|
|                  | Public            | Protected            |
|                  |-------------------|----------------------|
|  Protected       | Protected         | Protected            |
|                  |-------------------|----------------------|
|                  | Private           | Not accessible       |
|------------------|-------------------|----------------------|
|                  | Public            | Private              |
|                  |-------------------|----------------------|
|  Private         | Protected         | Private              |
|                  |-------------------|----------------------|
|                  | Private           | Not accessible       |
---------------------------------------------------------------

*/
#include <iostream>
using namespace std;

// Base class
class Base
{
public:
    int publicVar;

protected:
    int protectedVar;

private:
    int privateVar;

public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {}
    void showBase()
    {
        cout << "Base class members:" << endl;
        cout << "Public variable: " << publicVar << endl;
        cout << "Protected variable: " << protectedVar << endl;
        cout << "Private variable: " << privateVar << endl;
    }
};

// Derived class with public inheritance
class DerivedPublic : public Base
{
public:
    void showDerivedPublic()
    {
        cout << "Derived class (public inheritance) members:" << endl;
        cout << "Public variable: " << publicVar << endl;       // Accessible
        cout << "Protected variable: " << protectedVar << endl; // Accessible
        // cout << "Private variable: " << privateVar << endl; // Not accessible
    }
};

// Derived class with protected inheritance
class DerivedProtected : protected Base
{
public:
    void showDerivedProtected()
    {
        cout << "Derived class (protected inheritance) members:" << endl;
        cout << "Public variable: " << publicVar << endl;       // Accessible
        cout << "Protected variable: " << protectedVar << endl; // Accessible
        // cout << "Private variable: " << privateVar << endl; // Not accessible
    }
};

// Derived class with private inheritance
class DerivedPrivate : private Base
{
public:
    void showDerivedPrivate()
    {
        cout << "Derived class (private inheritance) members:" << endl;
        cout << "Public variable: " << publicVar << endl;       // Accessible
        cout << "Protected variable: " << protectedVar << endl; // Accessible
        // cout << "Private variable: " << privateVar << endl; // Not accessible
    }
};

int main()
{
    DerivedPublic dpub;
    DerivedProtected dprot;
    DerivedPrivate dpriv;

    dpub.showDerivedPublic(); // Accessing base class members in derived class with public inheritance
    cout << endl;

    dprot.showDerivedProtected(); // Accessing base class members in derived class with protected inheritance
    cout << endl;

    dpriv.showDerivedPrivate(); // Accessing base class members in derived class with private inheritance
    cout << endl;

    dpub.publicVar = 10; // Accessible
    dpub.protectedVar = 20; // Not accessible
    dpub.privateVar = 30; // Not accessible


    dprot.publicVar = 10; // Accessible
    dprot.protectedVar = 20; // Not accessible
    dprot.privateVar = 30; // Not accessible

    dpriv.publicVar = 10; // Accessible
    dpriv.protectedVar = 20; // Not accessible
    dpriv.privateVar = 30; // Not accessible


    return 0;
}
