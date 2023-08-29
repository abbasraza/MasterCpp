//
//  binding_args_to_func.cpp
//  Binding args to function
//
//  Created by abbas raza on 29/08/2023.
//  Copyright © 2017 Self. All rights reserved.
//


/**
 * This program demonstrates how to bind arguments to a function using std::bind from the functional library.
 * It defines a function called add that takes two integer arguments and returns their sum.
 * It then creates a new function called addFive that is a copy of the add function, but with the second argument fixed to the value 5.
 * The program calls the addFive function with the argument 10 and stores the result in a variable called result.
 * Finally, it outputs the result to the console.
 */

#include <functional> // include the functional library
#include <iostream> // include the iostream library

// define a function called add that takes two integer arguments and returns their sum
int add(int x, int y)
{
    return x + y;
}

// main function
int main()
{
    // create a new function called addFive that is a copy of the add function, but with the second argument fixed to the value 5
    auto addFive = std::bind(add, std::placeholders::_1, 5);

    /*
    Here, std::placeholders::_1 is a placeholder that represents the first argument of the add function.
    By binding the second argument of add to the value 5, we create a new function addFive that takes a single integer argument and returns the sum of that argument and 5.

    We can then call addFive with a single argument to produce a result:
    */

    // call the addFive function with the argument 10 and store the result in a variable called result
    int result = addFive(10); // result is 15

    // output the result to the console
    std::cout << result << std::endl;
}