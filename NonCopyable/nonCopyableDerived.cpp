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

class NonCopyableDerived : NonCopyable
{
public:
    NonCopyableDerived()
    {
        std::cout << "NonCopyableDerived object created" << std::endl;
    }

    ~NonCopyableDerived()
    {
        std::cout << "NonCopyableDerived object destroyed" << std::endl;
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
    NonCopyableDerived obj1;
    // NonCopyableDerived obj2 = obj1; // copy constructor is called here (obj2 needs to be constructed). This should result in compilation error.

    return 0;
}
