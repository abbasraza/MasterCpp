#include <iostream>
#include <unordered_map>

class Foo {
public:
    Foo(int value) : value_(value) {
        std::cout << "Foo constructor called" << std::endl;
    }

    int getValue() const {
        return value_;
    }

private:
    int value_;
};

int main() {
    std::unordered_map<std::string, Foo *> myMap;

    // Create a Foo object and insert it into the map
    Foo * fooObj = new Foo(42);
    myMap.emplace("key", fooObj);

    // Access the Foo object from the map
    std::cout << "Value in the map: " << myMap["key"]->getValue() << std::endl;

    return 0;
}