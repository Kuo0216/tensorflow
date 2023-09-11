#ifndef MOUNTAIN_H
#define MOUNTAIN_H
#include <iostream>
#include <string>
class Mountain
{
public:
    Mountain()
    {
        std::cout << "basic mountain" << std::endl;
    }
    Mountain(const std::string &name) : name(name)
    {
        std::cout << "initiate string:" << name << std::endl;
    }

    std::string getName() const
    {
        return name;
    }
    void setName(const std::string &newName)
    {
        name = newName;
    }
    void setHight(double hight1)
    {
        hight = hight1;
        width = hight1 - 80;
    }
    Mountain &operator=(const Mountain &other);
    void testMountain();

private:
    std::string name;
    double hight = 0.0;
    double width = 0.0;
};
// std::unordered_map<std::string, Mountain> mountainMap;
//     Mountain mountainA;
//     mountainA.setHight(3458);
//     mountainA.setName("Vault Mountain");
//     std::cout << &mountainA << std::endl;
//     Mountain mountainB("Mount Water");
//     mountainB.setHight(2458);
//     Mountain mountainC;
//     mountainMap["James"] = mountainA;
//     mountainC.setName("tinker Mountain");
//     std::cout << &mountainA << std::endl;
//     mountainMap["Marry"] = mountainB;
//     Country mycountry("American", "James");
//     Country mycountry1("Australia", "Marry");
//     std::string visitorName = mycountry.getVisitorName();

//     if (mountainMap.find(visitorName) != mountainMap.end())
//     {
//         Mountain &visitorMountain = mountainMap[visitorName];
//         std::cout << "Visitor's name: " << visitorName << std::endl;
//         std::cout << "Visitor's Mountain: " << visitorMountain.getName() << std::endl;
//     }
//     else
//     {
//         std::cout << "No mountain found for visitor: " << visitorName << std::endl;
//     }
#endif // MOUNTAIN_H