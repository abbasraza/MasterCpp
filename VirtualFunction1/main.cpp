//
//  main.cpp
//  VirtualFunction1
//
//  Created by abbas raza on 27/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To explore polymorphism.
 - Early/static binding.
 - Late/dynamic binding.
 - Virtual functions.
 - Function overloading. having more than 1 function with same name but different arguments.
 - Function overriding. Base has show() and Derived has show(). Both show() have same arguments.
 
 - If Base has function show and Derived has same function show. Then
     Derived d;
     Base * b = &d;
 
     b->show();
     it will call Base's show. Static/early binding here.
 
 - If Base has function show and Derived doesn't have function show. Then.
     Derived d;
     Base * b = &d;
 
     b->show();
     it will call Base's show.
 
 - If Base doesn't have show() and Derived has show() then
     Derived d;
     Base * b = &d;
 
     b->show();
     it will result in compile error. Because there is no show() in Base.
 
 - Now assume Derived has show() and what we want is to call Derived's show() with this
     Derived d;
     Base * b = &d;
 
     b->show(); // How can it call Derived's show??
   Here comes virtual functions into play.
 
 class Base
 {
 public:
     virtual void show()
     {
         std::cout << "show() of base called" << std::endl;
     }
 };

 class Derived : public Base
 {
 public:
     void show()
     {
         std::cout << "show() of derived called" << std::endl;
     }
 };
 
 Derived d;
 Base * b = &d;
 
 b->show(); ---> This will call Derived's show(). Its called late/dynamic binding
 
 Base b1;
 b1.show(); ---> This will call Base's show()

 - Use of dynamic cast:
   Dynamic cast is used to convert a Base to Derived in a safe way.
   it checks if Base is really part of Derived. if so it returns a pointer to Derived.
   Otherwise returns NULL.
   As can be seen in example below:
 
     Derived d1;
     Base * b1 = &d1;
 
     Derived * d2 = dynamic_cast<Derived *>(b1); // d2 is not null here.
     std::cout << "Is d2 NULL: " << (d2 ? "NO" : "YES") << std::endl;
 
     Base b2;

     Derived * d3 = dynamic_cast<Derived *>(&b2); // d3 is null
     std::cout << "Is d3 NULL: " << (d3 ? "NO" : "YES") << std::endl;

 - Static cast and reinterpret_cast do above unsafely. They don't return null and
   assume that Base was part of Derived.
*/

#include <iostream>
class Base
{
public:
    virtual void show()
    {
        std::cout << "show() of base called" << std::endl;
    }
};

class Derived : public Base
{
public:
    void show()
    {
        std::cout << "show() of derived called" << std::endl;
    }
};

int main(int argc, const char * argv[]) {

    Derived d1;
    Base * b1 = &d1;

    Base b2;
    
    Derived * d2 = dynamic_cast<Derived *>(b1);
    std::cout << "Is d2 NULL: " << (d2 ? "NO" : "YES") << std::endl;
    
    Derived * d3 = dynamic_cast<Derived *>(&b2);
    std::cout << "Is d3 NULL: " << (d3 ? "NO" : "YES") << std::endl;


    return 0;
}
