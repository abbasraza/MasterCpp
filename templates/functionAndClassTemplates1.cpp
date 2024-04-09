/**
 * @file example1.cpp
 * @brief This file demonstrates the usage of function and class templates in C++.
 * 
 * Definitions of class functions are inside class declaration.
 * 
 * The code defines a function template `findMax` that finds the maximum element in a generic array.
 * It also defines a class template `Container` that represents a generic container.
 * The class template has a specialization for integers, which only allows non-negative integers to be added.
 * 
 * The main function demonstrates the usage of the function template and the class template.
 * It creates an array of integers and an array of doubles, and finds the maximum value in each array using the `findMax` function template.
 * It also creates instances of the `Container` class template, adds elements to them, and displays the contents of the containers.
 */
#include <iostream>
#include <vector>

template<typename T>
T findMax(T arr[], int size) {
    T max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

template<typename T>
class Container {
private:
    std::vector<T> elements;
public:
    /**
     * @brief Adds an element to the container.
     * @param element The element to be added.
     */
    void add(const T& element) {
        elements.push_back(element);
    }
    
    /**
     * @brief Displays the elements in the container.
     */
    void display() const {
        for (const auto& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

template<>
class Container<int> {
private:
    std::vector<int> elements;
public:
    void add(const int& element) {
        if (element >= 0) {
            elements.push_back(element);
        }
    }
    
    void display() const {
        for (const auto& elem : elements) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    int intArray[] = {5, 10, 3, 8, 15};
    double doubleArray[] = {2.5, 6.7, 3.2, 9.8, 1.6};
    
    std::cout << "Max integer value: " << findMax(intArray, 5) << std::endl;
    std::cout << "Max double value: " << findMax(doubleArray, 5) << std::endl;
    
    Container<int> intContainer;
    intContainer.add(5);
    intContainer.add(-3);
    intContainer.add(10);
    std::cout << "Int container: ";
    intContainer.display();
    
    Container<double> doubleContainer;
    doubleContainer.add(2.5);
    doubleContainer.add(6.7);
    doubleContainer.add(-1.3);
    std::cout << "Double container: ";
    doubleContainer.display();
    
    return 0;
}
