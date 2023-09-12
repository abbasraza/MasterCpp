//
//  scoped_object_example1.cpp
//  A simple example of using RAII and Scoped Objects to create and write to a file.
//
//  Created by Abbas on 10/12/2021.
//

#include <iostream>
#include <fstream>
#include <string>

class ScopedFile
{
public:
    /**
     * @brief Construct a new Scoped File object and open the file for writing.
     * 
     * @param filename The name of the file to create.
     * @param content The content to write to the file.
     */
    ScopedFile(const std::string &filename, const std::string &content)
        : filename_(filename)
    {
        // Open the file for writing when the object is created
        file_.open(filename);
        if (!file_.is_open())
        {
            std::cerr << "Failed to open file: " << filename << std::endl;
        }
        else
        {
            file_ << content;
            std::cout << "File " << filename << " created and written." << std::endl;
        }
    }

    /**
     * @brief Destroy the Scoped File object and close the file.
     * 
     */
    ~ScopedFile()
    {
        // Close the file when the object goes out of scope
        if (file_.is_open())
        {
            file_.close();
            std::cout << "File " << filename_ << " closed." << std::endl;
        }
    }

private:
    std::ofstream file_; /**< The file stream object. */
    std::string filename_; /**< The name of the file. */
};

/**
 * @brief The main function.
 * 
 * @return int The exit status of the program.
 */
int main()
{
    ScopedFile file("example.txt", "Hello, RAII and Scoped!");

    // The file is automatically closed when the 'file' object goes out of scope
    // You can perform other operations here.

    return 0;
} // 'file' object goes out of scope, and the file is closed automatically
