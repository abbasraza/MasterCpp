#include <iostream>
#include <vector>
/**
 * @file example2.cpp
 * @brief This file demonstrates the usage of function and class templates in C++.
 * 
 * Definitions of class functions are outside class declaration.
 * 
 * We've defined a class template that includes a static member. We then specialize
 * this static member for two specific types. 
 * 
 * When objects of this class are instantiated, all objects of the same type share the same static member.
 * In this case, all integer container instances share the same name member. 
 * 
 * If the name member was not static, we wouldn't be able to specialize it,
 * because each object would have its own distinct name member.
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

//template specialization for a class member
/* The name member in the Container class template is declared as static,
which means it is shared among all instances of the class. When specializing a
member of a class template, it is necessary to specialize the static member as well.
This allows each specialization to have its own unique value for the name member.
If the name member is not declared as static, it cannot be specialized because it would
require modifying the member for each instance of the class, which is not allowed.*/
template<>
std::string Container<int>::name = "integer container";

//template specialization for a class member
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

    Container<int> intContainer2;
    intContainer2.printName();


    
    return 0;
}
