
/*

//  Created by abbas raza on 21/08/2023.
//  Copyright © 2023 Self. All rights reserved.


This C++ program demonstrates the use of mutexes for
thread synchronization. The program defines a global integer variable
`g_i` and two functions, `safe_increment` and `unsafe_increment`,
that increment the value of `g_i` by a specified number of iterations.

The `safe_increment` function uses a `std::lock_guard` object to lock
a global mutex `g_i_mutex` before incrementing `g_i`. This ensures that
only one thread can access `g_i` at a time, preventing race conditions
and other synchronization issues.

The `unsafe_increment` function increments `g_i` without any
synchronization, which can lead to race conditions and other
synchronization issues if called by multiple threads.

The `main` function defines a lambda function called `test` that takes
in a function pointer and a string view. The `test` function initializes
`g_i` to zero and then creates two threads that call the given function
with an input parameter of 1,000,000. The `test` function then waits for
the threads to complete and prints out the final value of `g_i`.

The purpose of this code is to demonstrate the importance of thread
synchronization when accessing shared resources in a multithreaded
environment. The `safe_increment` function uses a mutex to ensure that
only one thread can access `g_i` at a time, while the `unsafe_increment`
function does not use any synchronization and can lead to race conditions.

To improve the code's readability, the `safe_increment` and
`unsafe_increment` functions could be broken down into smaller, more
modular functions that perform specific tasks. Additionally, the program
could be optimized for performance by using more efficient algorithms
for thread synchronization and data sharing.
*/

#include <iostream>
#include <mutex>
#include <string_view>
#include <syncstream>
#include <thread>

// A global variable to be incremented by multiple threads
volatile int g_i = 0;

// A mutex to protect the global variable g_i
std::mutex g_i_mutex;

// A function to increment the global variable g_i in a thread-safe manner
void safe_increment(int iterations)
{
    // Lock the mutex to protect the shared resource
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    while (iterations-- > 0)
        g_i = g_i + 1;
    std::cout << "thread #" << std::this_thread::get_id() << ", g_i: " << g_i << '\n';

    // g_i_mutex is automatically released when lock goes out of scope
}

// A function to increment the global variable g_i in an unsafe manner
void unsafe_increment(int iterations)
{
    while (iterations-- > 0)
        g_i = g_i + 1;
    std::cout << "thread #" << std::this_thread::get_id()
                                << ", g_i: " << g_i << '\n';
}

int main()
{
    // A lambda function to test the safe_increment and unsafe_increment functions
    auto test = [](std::string_view fun_name, auto fun)
    {
        g_i = 0;
        std::cout << fun_name << ":\nbefore, g_i: " << g_i << '\n';
        {
            // Create two threads to call the given function
            std::thread t1(fun, 1'000'000);
            std::thread t2(fun, 1'000'000);

            // Wait for the threads to finish
            t1.join();
            t2.join();
        }
        std::cout << "after, g_i: " << g_i << "\n\n";
    };

    // Test the safe_increment and unsafe_increment functions
    test("safe_increment", safe_increment);
    test("unsafe_increment", unsafe_increment);
}
/* output:

safe_increment:
before, g_i: 0
thread #140737345746496, g_i: 1000000
thread #140737337353792, g_i: 2000000
after, g_i: 2000000

unsafe_increment:
before, g_i: 0
thread #140737337353792, g_i: 1045699
thread #140737345746496, g_i: 1258403
after, g_i: 1258403

*/