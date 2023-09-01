
//  Created by abbas raza on 29/08/2023.
//  Copyright © 2017 Self. All rights reserved.

/**
 * @brief This program demonstrates the use of unique_ptr in C++.
 * 
 * The program creates a MyClass object using a unique_ptr and demonstrates how to properly move or assign ownership of a unique_ptr.
 * It also shows that a unique_ptr cannot be copied, and that it cannot be converted to a raw pointer.
 * 
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
    std::unique_ptr<MyClass> ptr2 = nullptr;
    MyClass * ptr3 = nullptr;

    if (true)
    {
        // Scope of the following MyClass object is this if-block
        std::unique_ptr<MyClass> ptr(new MyClass());
        /*  following assigment:
            ptr2 = ptr;
            
             will cause following compilation error:
            use of deleted function ‘std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = MyClass; _Dp = std::default_delete<MyClass>]’

            The reason you are getting the error is because a copy is taking place. Copying a unique pointer is not allowed because the unique_ptr copy constructor is deleted in the implementation. If you need to pass a unique_ptr, you can do so by using move or by using a reference.
        */


        ptr2 = ptr;

        /*
        
              // Disable copy from lvalue.
      unique_ptr(const unique_ptr&) = delete;
      unique_ptr& operator=(const unique_ptr&) = delete;

        The code is using C++11 features to explicitly delete the copy constructor and copy assignment operator for a std::unique_ptr. This is done to prevent copying a std::unique_ptr instance, which enforces the unique ownership semantics of this smart pointer.

        Here's what each part of the code does:

        unique_ptr(const unique_ptr&) = delete;

        This line declares a copy constructor for std::unique_ptr but immediately marks it as deleted by using the = delete syntax. In C++, this syntax tells the compiler that you do not want the copy constructor to be generated automatically, and if someone tries to use it, it should result in a compilation error.

        By deleting the copy constructor, you prevent instances of std::unique_ptr from being copied. This is important because unique pointers are designed to have exclusive ownership of the managed object. Copying a unique pointer would violate this exclusivity, potentially leading to resource leaks and undefined behavior.

        unique_ptr& operator=(const unique_ptr&) = delete;

        Similarly, this line declares a copy assignment operator for std::unique_ptr and marks it as deleted. This operator is used when you try to assign one unique pointer to another using the = operator. By deleting it, you prevent the assignment of one unique pointer to another, reinforcing the unique ownership guarantee.

        In summary, by explicitly deleting the copy constructor and copy assignment operator for std::unique_ptr, you ensure that instances of std::unique_ptr cannot be copied, which helps maintain the exclusive ownership semantics and the safety provided by unique pointers in C++.





        */
        /* proper moving/assignment of unique pointer */
        // ptr2 = std::move(ptr);
        // if (ptr == nullptr)
        //     std::cout << "ptr is nullptr after ownership move\n";

        
        /* 
            ptr3 = ptr;
            gives following compilation error:
                no suitable conversion function from "std::unique_ptr<MyClass, std::default_delete<MyClass>>" to "MyClass *" exists
            
            This is because you cannot convert unique_ptr to raw pointer. You can get the raw pointer by calling get() method of unique_ptr.
            here ptr3 is raw pointer to MyClass object. while ptr is unique_ptr to MyClass object.
            
        */
        ptr3 = ptr;



        ptr->i = 5;
        std::cout << "\n" << ptr->i << "\n";
    }
    // The pointer gets deallocated automatically at this point.
    // Thus, the destructor of MyClass is called here.
    std::cout << "out of scope" << std::endl;
    return 0;
}