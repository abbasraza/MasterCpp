/**
 * @file nonCopyable.cpp
 * @brief This file contains the implementation of the NonCopyable class.
 */

#include <iostream>

/**
 * @class NonCopyable
 * @brief A class that demonstrates non-copyable behavior.
 *
 * The NonCopyable class is designed to prevent copying of objects.
 * It achieves this by declaring the copy constructor and assignment operator as private,
 * which makes them inaccessible to other code.
 */
class NonCopyable
{
private:
    // Private copy constructor
    NonCopyable(const NonCopyable &);

    // Private assignment operator
    NonCopyable &operator=(const NonCopyable &);

public:
    // Default constructor
    NonCopyable()
    {
        std::cout << "NonCopyable object created" << std::endl;
    }

    // Destructor
    ~NonCopyable()
    {
        std::cout << "NonCopyable object destroyed" << std::endl;
    }
};

/**
 * @brief The entry point of the program.
 *
 * This function demonstrates the non-copyable behavior of the NonCopyable class.
 * It attempts to create a copy of a NonCopyable object and assign one NonCopyable object to another,
 * both of which should result in compilation errors.
 *
 * @return 0 on successful execution.
 */
int main()
{
    // Attempting to create a copy of NonCopyable object
    // This should result in a compilation error
    // NonCopyable obj1;
    // NonCopyable obj2 = obj1; // copy constructor is called here (obj2 needs to be constructed). This should result in compilation error.

    // Attempting to assign one NonCopyable object to another
    // This should also result in a compilation error
    NonCopyable obj3, obj4; // default constructors are already called here
    obj3 = obj4; // now assignment operator is called. This should result in compilation error.

    return 0;
}
