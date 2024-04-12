//
//  main.cpp
//  VirtualFunction2
//
//  Created by abbas raza on 29/11/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - To explore virtual functions.
 
 ============================================================================================================
 Rules:
 ======
Base * ptr = &(derived);
ptr->function();

A) Base has function definition:
    i) If Base is not derived (Base has no parent):
        1) if base has that as non-virtual function, call that function.
        2) if base has that as virtual function, execute the last definition of function() going from Base---> Derived;

    ii) If Base is a derived class (Base has parent):
        1) if Base has that as non-virtual function, go Base --to--> (Parents of base)
            1.0) if found any virtual definition up, execute the last definition of function() going from Base---> Derived;
            1.1) if not found any virtual definition up, execute Base's function.
        2) if base has that as virtual function, execute the last definition of function() going from Base---> Derived;

B) If Base doesn't have function definition:
    i) If Base is not derived (Base has no parent):
        1) error

    ii) If Base is a derived class (Base has parent):
        1) go from Base --to--> (Parents of base)
            1.0) if found any virtual definition up, execute the last definition of function() going from Base---> Derived;
            1.1) if not found any virtual definition up, execute first definition Base --to--> (Parents of base).
 
 - Never call virtual function in ctor and dtor.
============================================================================================================

 -Examples:
 
class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B: public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};


B b;
A  * a = &b;
a->show(); --> A's show

======================================================

class A {
public:
};

class B : public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};


B b;
A  * a = &b;
a->show(); --> Error;

======================================================

class A {
public:
    virtual void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};


B b;
A  * a = &b;
a->show(); --> B's show;

======================================================

class A {
public:
    virtual void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
};


int main()
{
B b;
A  * a = &b;
a->show(); // --> A's show;
b.show(); // A's shows;
return 1;
}

======================================================

class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    virtual void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};


int main()
{
    B b;
    A  * a = &b;
    a->show(); //--> A's show;
    return 1;
}

======================================================

class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};
class C : public B {
public:
    void show()
    {
        std::cout << "C ka show()" << std::endl;
    }
};



int main()
{
    C c;
    A  * a = &c;
    B * b = &c;
    a->show(); // --> A's show;
    b->show(); //--> B's show;
    return 1;
}

======================================================

class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
};
class C : public B {
public:
    void show()
    {
        std::cout << "C ka show()" << std::endl;
    }
};


int main()
{

    C c;
    A  * a = &c;
    B * b = &c;
    a->show(); //--> A's show;
    b->show(); //--> A's show;

    return 1;
}

======================================================
class A {
public:
    virtual void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};
class C : public B {
public:
    void show()
    {
        std::cout << "C ka show()" << std::endl;
    }
};


int main()
{

    C c;
    A  * a = &c;
    B * b = &c;
    a->show(); //--> C's show;
    b->show(); //--> C's show;

    return 1;
}


======================================================
class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    virtual void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};
class C : public B {
public:
    void show()
    {
        std::cout << "C ka show()" << std::endl;
    }
};


int main()
{

    C c;
    A  * a = &c;
    B * b = &c;
    a->show(); //--> A's show;
    b->show(); //--> C's show;

    return 1;
}
======================================================

class A {
public:
    void show()
    {
                std::cout << "A ka show()" << std::endl;
    }
};

class B : public A {
public:
    void show()
    {
        std::cout << "B ka show()" << std::endl;
    }
};
class C : public B {
public:
    virtual void show()
    {
        std::cout << "C ka show()" << std::endl;
    }
};


int main()
{

    C c;
    A  * a = &c;
    B * b = &c;
    a->show(); //--> A's show;
    b->show(); //--> B's show;

    return 1;
}
======================================================
class A
{
public:
    virtual const char* getName() { return "A"; }
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
// Note: no getName() function here
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    A &rBase = c;
    std::cout << rBase.getName() << '\n'; // prints "B"
 
    return 0;
}
======================================================

class A
{
public:
    virtual const char* getName() { return "A"; }
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    B &rBase = c; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n'; // prints "C"
 
    return 0;
}
======================================================
class A
{
public:
    const char* getName() { return "A"; } // note: not virtual
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    A &rBase = c;
    std::cout << rBase.getName() << '\n'; //prints A
 
    return 0;
}
======================================================
class A
{
public:
    virtual const char* getName() { return "A"; }
};
 
class B: public A
{
public:
    const char* getName() { return "B"; }  // note: not virtual
};
 
class C: public B
{
public:
    const char* getName() { return "C"; } // note: not virtual
};
 
class D: public C
{
public:
    const char* getName() { return "D"; } // note: not virtual
};
 
int main()
{
    C c;
    B &rBase = c; // note: rBase is a B this time
    std::cout << rBase.getName() << '\n'; // prints "C"
 
    return 0;
}
======================================================

class A
{
public:
    virtual const char* getName() const { return "A"; } // note: function is const
};
 
class B: public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C: public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D: public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c;
    A &rBase = c;
    std::cout << rBase.getName() << '\n'; // calls "A"
 
    return 0;
}


======================================================

Never call virtual function in ctor and dtor.

class A
{
public:
    A() { std::cout << getName(); } // note addition of constructor
 
    virtual const char* getName() { return "A"; }
};
 
class B : public A
{
public:
    virtual const char* getName() { return "B"; }
};
 
class C : public B
{
public:
    virtual const char* getName() { return "C"; }
};
 
class D : public C
{
public:
    virtual const char* getName() { return "D"; }
};
 
int main()
{
    C c; // prints "A". for creating C, first B is created. For creating B first A is created. So when A is created, B,C doesn't exist yet. Therefore A's getName gets called.
 
    return 0;
}

 */
#include <iostream>

class A
{
public:
    virtual const char * getName()
    {
        return "A";
    } // only the most base function is virtual
};

class B: public A
{
public:
    const char * getName()
    {
        return "B";
    }  // note: not virtual
};

class C: public B
{
public:
    const char * getName()
    {
        return "C";
    } // note: not virtual
};

class D: public C
{
public:
    const char * getName()
    {
        return "D";
    } // note: not virtual
};

int main()
{
    C c;
    B * b1 = &c;
    std::cout << b1->getName() << '\n';
    
    return 0;
}

