#include <iostream>
#include <optional>

std::optional<int> divide(int a, int b)
{
    if (b != 0)
    {
        return a / b;
    }
    else
    {
        return std::nullopt;
    }
}

int main()
{
    int x = 10;
    int y = 0;

    std::optional<int> result = divide(x, y);

    if (result)
    {
        std::cout << "Result: " << *result << std::endl;
    }
    else
    {
        std::cout << "Division by zero!" << std::endl;
    }

    return 0;
}
