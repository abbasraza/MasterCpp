
//  Created by abbas raza on 29/08/2023.
//  Copyright © 2017 Self. All rights reserved.

/**
 * @brief This program demonstrates the use of unique pointers and how to get a raw pointer from a unique pointer.
 * 
 * A unique pointer is a smart pointer that owns and manages the object it points to.
 * It ensures that the object is deleted when the unique pointer goes out of scope.
 * This program creates a unique pointer to an object of MyClass and sets its member variable i to 10.
 * It then gets a raw pointer from the unique pointer and sets its member variable i to 15.
 * The program then deletes the object using the raw pointer, which causes a double free error
 * because the object is already deleted when the unique pointer goes out of scope.
 */

#include <iostream>
#include <memory>
class MyClass
{
public:
    int i;
    MyClass()
    { // Constructor
        std::cout << "\n created\n";
    }
    ~MyClass()
    { // Destructor
        std::cout << "\n destroyed\n";
    }
};
int main()
{
    MyClass * ptr3 = nullptr;

    if (true)
    {
        std::unique_ptr<MyClass> ptr(new MyClass());
        ptr->i = 10;

        std::cout << "value of i pointed by unique ptr: " << ptr->i << std::endl;

        //get raw pointer from  unique pointer
        ptr3 = ptr.get();
        
        ptr3->i = 15;

        std::cout << "value of i again pointed by unique ptr: " << ptr->i << std::endl;


        /* this destroys the allocated object*/
        delete ptr3;

    }

    /* after unique ptr goes out of scope, object will be destroyed again
    
    double free.....
    */

    std::cout << "out of scope" << std::endl;
    return 0;
}

/* 



 created
value of i pointed by unique ptr: 10
value of i again pointed by unique ptr: 15

 destroyed

 destroyed
free(): double free detected in tcache 2
*/