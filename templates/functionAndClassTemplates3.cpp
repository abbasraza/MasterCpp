#include <iostream>
#include <vector>
/**
 * @file example2.cpp
 * @brief This file demonstrates the usage of function and class templates in C++.
 * 
 * Definitions of class functions are outside class declaration.
 * 
 * The code defines a function template `findMax` that finds the maximum element in a generic array.
 * It also defines a class template `Container` that represents a generic container.
 * The class template has a specialization for integers, which only allows non-negative integers to be added.
 * 
 * The main function demonstrates the usage of the function template and the class template.
 * It creates an array of integers and an array of doubles, and finds the maximum value in each array using the `findMax` function template.
 * It also creates instances of the `Container` class template, adds elements to them, and displays the contents of the containers.
 */


// Class template for a generic container
template<typename T>
class Container {
private:
    static std::string name;
    std::vector<T> elements;
public:
    // Container();
    void add(const T& element);
    void display() const;
    void printName();
};


// // Class template function definition
// template<typename T>
// Container<T>::Container() {
//     name = "default";
// }

template<typename T>
void Container<T>::add(const T& element) {
    elements.push_back(element);
}

// Class template function definition
template<typename T>
void Container<T>::display() const {
    for (const auto& elem : elements) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void  Container<T>::printName()
{
    std::cout << name << std::endl;
}

template<>
std::string Container<int>::name = "integer container";

template<>
std::string Container<double>::name = "double container";


int main() {
        
    // Using class template
    Container<int> intContainer;
    intContainer.add(5);
    intContainer.add(-3); // Won't be added due to specialization
    intContainer.add(10);
    intContainer.display();
    intContainer.printName();
    
    Container<double> doubleContainer;
    doubleContainer.add(2.5);
    doubleContainer.add(6.7);
    doubleContainer.add(-1.3); // Will be added
    doubleContainer.display();
    doubleContainer.printName();

    
    return 0;
}
