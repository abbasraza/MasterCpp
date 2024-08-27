/**
 * @file optional2.cpp
 * @brief This file demonstrates the usage of std::optional to handle file reading operations.
 */

#include <iostream>
#include <optional>
#include <vector>
#include <functional>

/**
 * @brief Reads a file and returns its content as an optional string.
 * 
 * @return std::optional<std::string> The content of the file if read successfully, otherwise std::nullopt.
 */
std::optional<std::string> readFile() 
{
    std::string content = "FILE CONTENTS HERE>.......";
    bool fileReadSuccess = false; // lets say file reading failed.
    
    if (fileReadSuccess) 
    {
        return content;
    }

    return std::nullopt;
}

int main() 
{
    auto content = readFile();

    if (content.has_value())
    {
        std::cout << "File content: " << content.value() << std::endl;
    }
    else
    {
        std::cout << "File not found." << std::endl;
    }

    return 0;
}