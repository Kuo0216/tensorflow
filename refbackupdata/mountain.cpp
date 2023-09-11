#include "mountain.h"
#include <string>
Mountain &Mountain::operator=(const Mountain &other)
{
    if (this != &other)
    {
        name = other.name;
        hight = other.hight;
        width = other.width;
    }
    return *this;
}
void Mountain::testMountain()
{
}