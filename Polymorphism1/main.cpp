//
//  main.cpp
//  Polymorphism1
//
//  Created by abbas raza on 2/12/17.
//  Copyright © 2017 Self. All rights reserved.
//

/* Purpose of this program:
 - Explore polymorphism.
 - Explore early/static/compile-time function binding.
 - Explore late/dynamic/run-time function binding.
 - Binding vs linking:
 
 Binding is a word that is used in more than one context. It always has to do
 with the connecting of one thing to another however when the act of binding
 happens can vary.
 
 There is a concept of Binding Time or the point at which some component is
 bound to some other component. A basic list of binding time is:
 (1) binding at compile time
 (2) binding at link time
 (3) binding at load time
 (4) binding at run time
 
 1) Binding at compile time happens when the source code is compiled. For C/C++
 there are two main stages, the Preprocessor which does source text replacement
 such as define replacement or macro replacement and the compilation of the
 source text which converts the source text into machine code along with the
 necessary instructions for the linker.
 
 2) Binding at link time is when the external symbols are linked to a specific set
 of object files and libraries. You may have several different static libraries
 that have the same set of function names but the actual implementation of the
 function is different. So you can choose which library implementation to use by
 selecting different static libraries.
 
 3) Binding at load time is when the loader loads the executable into memory along
 with any dynamic or shared libraries. The loader binds function calls to a
 particular dynamic or shared library and the library chosen can vary.
 
 4) Binding at run time is when the program is actually running and makes choices
 depending on the current thread of execution.
 
 
 So linking is actually just one of the types of binding. Take a look at this
 stackoverflow static linking vs dynamic linking which provides more information
 about linking and libraries.
 
 You may also be interested in std::bind in C++ so here is a stackoverflow
 article std::function and std::bind what are they when they should be used.
 
 
 Benefits and drawbacks:
 The longer you wait before something is bound to something else can provide a
 needed degree of flexibility in how the software can be used. However often
 there is a trade off between delaying binding and run time efficiency as well
 as complexity of the source.
 
 For an example of bind time consider an application that opens a file and reads
 from the file then closes it. You can pick a couple of different times when the
 file name is bound to the file open.
 
 You might hard code the file name, binding at compile time, which means that it
 can only be used with that one file. To change the file name you have to change
 the source and recompile.
 
 You might have the file name entered by the user such as with a user prompt or
 a command line argument, binding the file name to the file open at run time. To
 change the file name you no longer need to recompile, you can just run the
 program again with a different file name.

 Example program:
 
     void function()
     {
         do something
     }
 
     int main()
     {
         function(); // function binding happens here
 
         return 1;
     }
 
 
 So here in program we define a function() and call it in main().
 function() is placed in code section and have an address let's say 0xABCD
 So what we do when we call function() is jump in assmbly to address of function() i.e 0xABCD
 
 so
 function()
 will be replaced with
 jump 0xABCD
 
 obviously with other operations like saving register states.
 
 This is called function binding.
 
 
 In above case, its compile time / early/ static binding.
 Let's say function() body is present in another file. In that case binding will be performed at
 linking time.
 Let's say function() body is present in a library. then the binding will be performed at
 compile time / link time / load time / runtime?
 I guess if we want to use that library statically, then binding will be performed at link time.
 If we want to use that library dynamically, then binding will be done at load time.
 when will binding be performed at run-time with library???
 
 In below program, lets say if we ask user at run-time to input list of animals of different kind
 then at this Polymorphic Call
     animals[i]->speak();
 
 we don't know at compile-time / link time / load time where to jump exactly against this call.
 so it will be decided at run time. So its called run-time/late/dynamic binding.
 
 
 - Virtual tables method? TODO
*/

#include <iostream>

class Animal
{
private:
    std::string name;
public:
    Animal(std::string n = "") : name(n)
    {
    }
    void get_name()
    {
        std::cout << name << std::endl;
    }
    virtual void speak()
    {
        std::cout << "????" << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(std::string n = "") : Animal(n)
    {
        
    }
    void speak()
    {
        std::cout << "Mewoo Mewoo" << std::endl;
    }
};

class Dog : public Animal
{
public:
    Dog(std::string n = "") : Animal(n)
    {
        
    }
    void speak()
    {
        std::cout << "Woof Woof" << std::endl;
    }
};

void print_animals(Animal * animals[], size_t count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << "Name of animal: ";
        animals[i]->get_name(); // This is static/early/compile-time binding. Compiler knows which speak function will be called.
        std::cout << "says: ";
        /* Polymorphic Call */
        // This is dynamic/late/run-time binding. Compiler doesn't know which speak function will be called
        // until run-time.
        animals[i]->speak();
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    /* This is polymorphism. i.e using array of animals pointing to different animal types. and accessing those animals
       then using Animal pointer. Instead of accessing Cat using Cat * ,  And Dog using Dog *.
    */
    Animal * animals[] = {new Cat("my cat"), new Cat("Neighbors cat"), new Dog("My dog"), new Dog("Neighbours dog")};
    
    print_animals(animals, sizeof(animals) / sizeof(Animal *));

    Animal ani;
    ani.speak(); // This is static/early/compile-time binding. Compiler knows which speak function will be called.
    
    for (int i = 0; i < sizeof(animals) / sizeof(Animal *); ++i)
    {
        delete animals[i];
    }
    return 0;
}
