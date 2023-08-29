//
//  function_callback.cpp
//  Function callbacks in c++ using function and bind templates
//
//  Created by abbas raza on 29/08/2023.
//  Copyright © 2017 Self. All rights reserved.
//



#include <iostream>
#include <functional>
/*
The code provided is a C++ program that demonstrates the use of callback functions and the std::function and std::bind templates. The program defines a function called performOperation that takes in two integers and a callback function, and calls the callback function with the input integers as arguments. The result of the callback function is then printed to the console.

The program also defines a callback function called multiply that takes in two integers and returns their product.

In the main function, two integers num1 and num2 are initialized to 8 and 4, respectively. The program then uses the std::bind template to create a new callback function called multiplyByTwo that is a partial application of the multiply function with the second argument bound to the value 2. The performOperation function is then called with num1, num2, and multiplyByTwo as arguments, which calls the multiplyByTwo function with num1 and num2 as arguments and prints the result to the console.

The purpose of this code is to demonstrate the use of callback functions and function templates in C++. Callback functions are useful for passing behavior as an argument to a function, allowing for greater flexibility and modularity in code. The std::function template provides a type-safe way to define callback functions, while the std::bind template allows for partial application of functions, which can be useful for creating new functions with specific arguments.

To improve the code's readability, the performOperation and multiply functions could be broken down into smaller, more modular functions that perform specific tasks. Additionally, the program could be optimized for performance by using more efficient algorithms for function binding and callback invocation.


std::function and std::bind are used in C++ instead of function pointers because they provide more flexibility and type safety.

Function pointers are a low-level feature of C and C++ that allow functions to be passed as arguments to other functions. However, function pointers have several limitations. They can only point to functions with a specific signature, and they cannot be used to bind arguments to a function.

std::function is a template class that provides a type-safe way to define callback functions. It can be used to store any callable object, including function pointers, member function pointers, and lambda expressions. std::function provides a uniform interface for calling the stored callable object, regardless of its type.

std::bind is a template function that allows for partial application of functions. It can be used to create a new function object that calls a given function with some of its arguments already bound to specific values. This can be useful for creating new functions with specific arguments, or for passing functions with a specific signature as arguments to other functions.

Overall, std::function and std::bind provide more flexibility and type safety than function pointers, making them a more powerful and convenient tool for defining and using callback functions in C++.



*/


// A function that takes two integers and a callback function
void performOperation(int a, int b, const std::function<int(int, int)>& callback) {
    int result = callback(a, b);
    std::cout << "Result: " << result << std::endl;
}

// Callback function for multiplication
int multiply(int x, int y) {
    return x * y;
}

int main() {
    int num1 = 8, num2 = 4;

    // Using std::bind to create a callback with bound arguments
    auto multiplyByTwo = std::bind(multiply, std::placeholders::_1, 2);

    // Using the bound callback
    performOperation(num1, num2, multiplyByTwo); // Output: Result: 16

    return 0;
}
