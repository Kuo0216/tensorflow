#ifndef READCSV_H
#define READCSV_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
template <typename T>
std::vector<T> readCSV(const std::string &filePath, std::unordered_map<std::string, T> &entryMap)
{
    std::vector<T> entryvec;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
        return entryvec; // Return on error
    }
    std::string line;
    std::getline(file, line); // Skip the header row
    std::unordered_map<std::string, int> titleMap;
    std::istringstream iss(line);
    std::string token;
    int idCounter = 0;

    while (std::getline(iss, token, ','))
    {

        titleMap[token] = idCounter++;
    }

    for (const auto &entry : titleMap)
    {
        std::cout << "Title: " << entry.first << ", ID: " << entry.second << std::endl;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, ','))
        {
            row.push_back(cell);
        }
        T entry(row);
        int tt = titleMap["WAFER"];
        auto it = entryMap.find(entry.getKeyDE());
        if (it != entryMap.end())
        {
            if (row[3] == "1" || row[3] == "2" || row[3] == "3")
            {
                it->second = entry;
                // it->second.setChamber(row, row[3]);
            }
        }
        else
        {
            entryMap[entry.getKeyDE()] = entry;
        }
        entryvec.push_back(entry);
    }
    file.close();
    return entryvec;
}
template <typename T>
std::vector<T> CMPreadCSV(const std::string &filePath, std::unordered_map<std::string, T> &entryMap)
{
    std::vector<T> entryvec;
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
        return entryvec;
    }
    std::string line;
    std::getline(file, line); // Skip the header row
    std::unordered_map<std::string, int> titleMap;
    std::istringstream iss(line);
    std::string token;
    int idCounter = 0;

    while (std::getline(iss, token, ','))
    {

        titleMap[token] = idCounter++;
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        while (std::getline(ss, cell, ','))
        {
            row.push_back(cell);
        }
        T entry(row);
        auto it = entryMap.find(entry.getKeyDE());
        int chamberColumn = titleMap["CHAMBER"];
        if (it != entryMap.end())
        {
            if (row[chamberColumn] == "1" || row[chamberColumn] == "2" || row[chamberColumn] == "3")
            {
                int i = std::stoi(row[chamberColumn]);
                // it->second = entry;
                it->second.setPlaten(row, i);
            }
        }
        else
        {
            // Entry with this key doesn't exist, add it to the map
            entryMap[entry.getKeyDE()] = entry;
        }
        entryvec.push_back(entry);
    }
    file.close();
    return entryvec;
}
#endif