#ifndef DATACHECK_H
#define DATACHECK_H
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <locale.h>
constexpr int defaultInt = -1;
constexpr double defaultDouble = -1.0;
int unitmapValue(int i);
int findValue(const std::vector<std::pair<std::string, int>> titleTest, const std::string &searchString);
template <typename T>
T convertAndHandle(const std::string &value)
{
    try
    {
        if (!value.empty())
        {
            return static_cast<T>(std::stod(value));
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid argument error in convertAndHandle: " << e.what() << value << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Other error in convertAndHandle: " << e.what() << std::endl;
    }
    return T(); // Default value for T
}
template <typename T>
T convertAndHandle(const std::string &value, const T &defaultValue)
{
    if (value.empty())
    {
        // Handle empty string here, possibly by returning a default value.
        std::cout << "Input string is empty" << std::endl;
        return defaultValue;
    }

    try
    {
        // Check if the string contains non-printable characters
        std::locale loc;
        for (char c : value)
        {
            if (!std::isprint(c, loc))
            {
                // Handle non-printable characters here, possibly by replacing them or skipping them.
                std::cout << "Non-printable character found: " << static_cast<int>(c) << std::endl;
                // You can return a default value or continue processing.
                return defaultValue;
            }
        }

        // Attempt to convert the string to T
        return static_cast<T>(std::stod(value));
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid argument error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Other error in convertAndHandle: " << e.what() << std::endl;
    }

    return defaultValue; // Default value for T
}
template <typename T>
T convertAndHandle(const std::string &value, const T &defaultValue, const std::vector<std::string> &row)
{
    if (value.empty())
    {
        // Handle empty string here, possibly by returning a default value.
        std::cout << "Input string is empty" << row[0] << row[1] << row[2] << row[3] << std::endl;
        return defaultValue;
    }

    try
    {
        // Check if the string contains non-printable characters
        std::locale loc;
        for (char c : value)
        {
            if (!std::isprint(c, loc))
            {
                // Handle non-printable characters here, possibly by replacing them or skipping them.
                std::cout << "Non-printable character found: " << static_cast<int>(c) << std::endl;
                // You can return a default value or continue processing.
                return defaultValue;
            }
        }

        // Attempt to convert the string to T
        return static_cast<T>(std::stod(value));
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid argument error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Other error in convertAndHandle: " << e.what() << std::endl;
    }

    return defaultValue; // Default value for T
}
template <typename T>
T convertAndHandle(const std::string &value, const T &defaultValue, const std::vector<std::string> &row, const std::string &finditems)
{
    if (value.empty())
    {
        // Handle empty string here, possibly by returning a default value.
        std::cout << finditems << " Input string is empty at the" << row[0] << row[1] << row[2] << row[3] << std::endl;
        return defaultValue;
    }

    try
    {
        // Check if the string contains non-printable characters
        std::locale loc;
        for (char c : value)
        {
            if (!std::isprint(c, loc))
            {
                // Handle non-printable characters here, possibly by replacing them or skipping them.
                std::cout << "Non-printable character found: " << static_cast<int>(c) << std::endl;
                // You can return a default value or continue processing.
                return defaultValue;
            }
        }

        // Attempt to convert the string to T
        return static_cast<T>(std::stod(value));
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Invalid argument error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Other error in convertAndHandle: " << e.what() << std::endl;
    }

    return defaultValue; // Default value for T
}
template <typename T>
T convertAndHandle(const std::string &value, const std::vector<std::string> &row)
{
    try
    {
        if (!value.empty())
        {
            return static_cast<T>(std::stod(value));
        }
    }
    catch (const std::invalid_argument &e)
    {
        for (const auto &elem : row)
        {
            std::cout << elem << '\n';
        }
        std::cout << "Invalid argument error in convertAndHandle: " << e.what() << value << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Out of range error in convertAndHandle: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Other error in convertAndHandle: " << e.what() << std::endl;
    }
    return T(); // Default value for T
}
void checkRowSize(const std::vector<std::string> &row, size_t expectedSize);
void checkfile1(std::ofstream &file);

#endif // DATACHECK_H
