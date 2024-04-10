//
//  remove.cpp
//  How to remove an element from vector
//
//  Copyright © 2023 Self. All rights reserved.
//

/* this will generate a seg fault because we are using the same iterator after erase
    When we erase the last element 5; the vector end changes. 
    lets say vector end was at address 5 previously
    now we erase last element
    vector end will be at address 4 now
    then we ++it
    so it will point to address 6 now
    ANDD in for loop condition, 6 ! = 4
    ++it
    this will go forever
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{

    vector<int> myvector;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);

    // Vector becomes 1, 2, 3, 4, 5
    // Printing the vector
    cout << "Vector:" << endl;

    //here 'it' will be an integer pointer pointing at first element of vector
    //
    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;

    cout << std::endl;


    /*
        myvector.begin():
        The begin() member function returns an iterator pointing to the first element of the vector.
        It provides an abstraction over the elements, allowing you to traverse the vector using iterators,
        which works seamlessly with the standard library algorithms.
        This function is useful for iterating over the vector and performing operations on its elements.

        this won't work
            std::cout << "Begin Address: " << myvector.begin() << std::endl;

    */

    std::cout << "Start Address: " << myvector.data() << std::endl;
    std::cout << "End Address: " << myvector.data() + myvector.size() << std::endl;


    /*
        myvector.end() is another member function of std::vector in C++, which returns an iterator pointing
        to the position just after the last element of the vector.

        Here's what you need to know about myvector.end():

        It provides a way to indicate the "one-past-the-end" position in the vector.
        It does not point to any valid element, and it should not be dereferenced.
        It's commonly used as the stopping condition in loops to iterate over a range of elements in the vector.
    */
    for (auto& it : myvector)
    {
        //printing address of element in vector
        cout << it << endl;
        if (it == 5)
        /*
            Yes, the erase function for std::vector does change the begin() and end() iterators.
            When you erase elements from a vector using the erase function, the vector's size is reduced,
            and the elements after the erased elements are shifted to fill the gap left by the removed elements.
            As a result, both begin() and end() iterators are affected by the erasure.
        */
            myvector.erase(it);
    }


    std::cout << "Start Address after erasing 1 element: " << myvector.data() << std::endl;
    std::cout << "End Address after erasing 1 element: " << myvector.data() + myvector.size() << std::endl;


    cout << endl << "Vector After erase" << endl;

    // Printing the vector
    for (auto it = myvector.begin(); it != myvector.end(); ++it)
        cout << ' ' << *it;
    
    cout << endl;

    return 0;
}
