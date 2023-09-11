#include "datacheck.h"
#include <iostream>
#include <stdexcept>
#include "dataentry.h"
#include "dataentryeq.h"
void checkRowSize(const std::vector<std::string> &row, size_t expectedSize)
{
    if (row.size() != expectedSize)
    {
        throw std::invalid_argument("Invalid number of columns in the row.");
    }
}
