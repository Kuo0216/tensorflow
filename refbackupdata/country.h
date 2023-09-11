#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include <unordered_map>
#include "mountain.h" // Include the Mountain class header
class Country
{
public:
    Country(const std::string &countryName, const std::string &visitorName) : countryName(countryName), visitorName(visitorName) {}

    std::string getCountryName() const
    {
        return countryName;
    }

    std::string getVisitorName() const
    {
        return visitorName;
    }

private:
    std::string countryName;
    std::string visitorName;
    int countryID = 0;
};
#endif // COUNTRY_H
