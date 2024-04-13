// This is similar to function prototype/declaration in C.


/* In C++, a forward declaration refers to declaring a class, function, or variable before
its actual definition is encountered in the source code.
This allows you to use the declared entity before it's fully defined.
Forward declarations are typically used in scenarios where the full definition of an entity
is not required, such as when declaring function prototypes, resolving circular dependencies
between classes, or improving compilation time by reducing header file dependencies.
*/

// Forward declaration of class.

class B; // if we comment this here, we will get compilation error in class A ==> ‘B’ does not name a type

class A {
    B* bPtr;
};

// Full definition of class B
class B {
};

int main()
{
    return 0;
}