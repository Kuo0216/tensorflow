#ifndef DATACHECK_H
#define DATACHECK_H
#include <string>
#include <vector>
#include <iostream>
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
    return T(); // Default value for T
}
void checkRowSize(const std::vector<std::string> &row, size_t expectedSize);
#endif // DATACHECK_H
