#include <iostream>

/**
 * @class File
 * @brief Represents a file and provides functionality to read and write data to it.
 */
class File
{
private:
    FILE *file; /**< Pointer to the file */

    /**
     * @brief Private copy constructor to prevent copying of File objects.
     * @param other The File object to be copied.
     */
    File(const File &other);

    /**
     * @brief Private assignment operator to prevent assignment of File objects.
     * @param other The File object to be assigned.
     * @return Reference to the assigned File object.
     */
    File &operator=(const File &other);

public:
    /**
     * @brief Constructor that opens a file.
     * @param filename The name of the file to be opened.
     */
    File(const char *filename)
    {
        file = fopen(filename, "w+");
        if (!file)
        {
            std::cerr << "Failed to open file" << std::endl;
        }
    }

    /**
     * @brief Destructor that closes the file.
     */
    ~File()
    {
        if (file)
        {
            fclose(file);
        }
    }

    /**
     * @brief Function to write data to the file.
     * @param data The data to be written to the file.
     */
    void write(const char *data)
    {
        if (file)
        {
            fputs(data, file);
        }
    }
};

/**
 * @brief The entry point of the program.
 * @return The exit status of the program.
 */
int main()
{
    // Create a File object
    File file("example.txt");

    // Attempt to create a copy of the File object
    // This should result in a compilation error due to private copy constructor
    // File file2 = file;

    // Attempt to assign one File object to another
    // This should also result in a compilation error due to private assignment operator
    // File file3("copy.txt");
    // file3 = file;

    return 0;
}
