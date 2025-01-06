#include <iostream>
#include <optional>
#include <string>

class MyClass {
public:
    std::optional<std::string> optionalMember;

    MyClass() = default;

    MyClass(const std::string& value) : optionalMember(value) {}
};

int main() {
    // Class not initialized with a value
    MyClass obj1;
    if (obj1.optionalMember.has_value()) {
        std::cout << "obj1 optionalMember: " << obj1.optionalMember.value() << std::endl;
    } else {
        std::cout << "obj1 optionalMember is not set." << std::endl;
    }

    // Class initialized with a value
    MyClass obj2;
    obj2.optionalMember = "Hello, World!";
    if (obj2.optionalMember.has_value()) {
        std::cout << "obj2 optionalMember: " << obj2.optionalMember.value() << std::endl;
    } else {
        std::cout << "obj2 optionalMember is not set." << std::endl;
    }

    return 0;
}