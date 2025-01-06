#include <iostream>
#include <memory>

// Abstract base class
class Animal 
{
public:
    virtual ~Animal() {}
    virtual void speak() = 0;
};

// Concrete classes
class Dog : public Animal 
{
public:
    void speak() override 
    {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal 
{
public:
    void speak() override 
    {
        std::cout << "Meow!" << std::endl;
    }
};

// Factory class
class AnimalFactory 
{
public:
    static std::unique_ptr<Animal> createAnimal(const std::string& type) 
    {
        if (type == "Dog") 
        {
            return std::make_unique<Dog>();
        } 
        else if (type == "Cat") 
        {
            return std::make_unique<Cat>();
        } 
        else 
        {
            return nullptr;
        }
    }
};

int main() 
{
    std::unique_ptr<Animal> dog = AnimalFactory::createAnimal("Dog");
    dog->speak(); // Outputs: Woof!

    std::unique_ptr<Animal> cat = AnimalFactory::createAnimal("Cat");
    cat->speak(); // Outputs: Meow!

    return 0;
}