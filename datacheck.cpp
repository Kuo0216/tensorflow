#include "datacheck.h"
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "dataentry.h"
#include "dataentryeq.h"
int unitmapValue(int i)
{
    if (i == 1)
        return 0;
    else if (i == 2)
        return 1;
    else if (i == 3)
        return 2;
    else if (i == 4)
        return 3;
    else
        return -1;
}
int findValue(const std::vector<std::pair<std::string, int>> titleTest, const std::string &searchString)
{
    auto foundPair = std::find_if(titleTest.begin(), titleTest.end(),
                                  [&searchString](const std::pair<std::string, int> &pair)
                                  {
                                      return pair.first == searchString;
                                  });

    if (foundPair != titleTest.end())
    {
        return foundPair->second;
    }
    else
    {
        std::cout << "cant find\t" << searchString << '\n';
        return -1; // Return a default value indicating not found
    }
}
void checkRowSize(const std::vector<std::string> &row, size_t expectedSize)
{
    if (row.size() != expectedSize)
    {
        std::cout << "row size is" << row.size() << std::endl;
        for (auto x : row)
        {
            std::cout << x << std::endl;
        }
        throw std::invalid_argument("Invalid number of columns in the row.");
    }
}
void extractColumnAndWriteToFile(const std::string &inputFile, const std::string &outputFile, int columnNumber)
{
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open())
    {
        std::cerr << "Error opening the file." << std::endl;
        return; // Exit the function if the file cannot be opened
    }

    std::vector<std::string> nthColumnValues;
    std::string line;

    while (std::getline(inFile, line))
    {
        std::stringstream ss(line);
        std::string token;

        for (int i = 1; i <= columnNumber; ++i)
        {
            if (std::getline(ss, token, ',') && i == columnNumber)
            {
                if (!token.empty())
                {
                    nthColumnValues.push_back(token);
                    std::cout << token << std::endl;
                    outFile << token << ',';
                }
            }
        }
    }

    // Close the input and output files when done
    inFile.close();
    outFile.close();
}
void checkfile1(std::ofstream &file)
{
    // Pass an ifstream reference
    if (file.is_open())
    {
        std::cout << "File is open." << std::endl;
        // Perform any additional checks or operations you need here.
    }
    else
    {
        std::cout << "File is not open or does not exist." << std::endl;
        // Handle the case when the file is not open.
    }
}