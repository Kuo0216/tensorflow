#include "wat.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <cmath>
WAT::WAT(const std::vector<std::string> &row) : tValue(0.0), bValue(0.0), cValue(0.0), lValue(0.0), rValue(0.0),
                                                blValue(0.0), brValue(0.0), tlValue(0.0), trValue(0.0), oosCount(0.0), stDevWAT(0.0), average(0.0), specLow(0.0), specHigh(0.0), ctrlLow(0.0), ctrlHigh(0.0)
{
    average = convertAndHandle<double>(row[12]);
    tValue = convertAndHandle<double>(row[13]);
    bValue = convertAndHandle<double>(row[14]); // 14
    cValue = convertAndHandle<double>(row[15]); // 15
    lValue = convertAndHandle<double>(row[16]); // 16
    rValue = convertAndHandle<double>(row[17]); // 17
    blValue = convertAndHandle<double>(row[18]);
    brValue = convertAndHandle<double>(row[19]);
    tlValue = convertAndHandle<double>(row[20]);
    trValue = convertAndHandle<double>(row[21]);
    testProg = row[22];
    oosCount = convertAndHandle<int>(row[23]);
    keyDE = row[3] + row[4];
    parameter = row[5];
    product = row[0];
    stDevWAT = calculateStandardDeviation();
    specLow = convertAndHandle<double>(row[6]);
    specHigh = convertAndHandle<double>(row[8]);
    ctrlLow = convertAndHandle<double>(row[9]);
    ctrlHigh = convertAndHandle<double>(row[10]);
    measureTime = row[11];
    testProg = row[22];
    lot = row[3];
    wafer = row[4];
    keyRoute = lot.substr(0, 5) + row[4] + row[24];
}
void WAT::setTValue(const std::vector<std::string> &row)
{
    tValue = convertAndHandle<double>(row[13]);
    bValue = convertAndHandle<double>(row[14]);
    cValue = convertAndHandle<double>(row[15]);
    lValue = convertAndHandle<double>(row[16]);
    rValue = convertAndHandle<double>(row[17]);
    blValue = convertAndHandle<double>(row[18]);
    brValue = convertAndHandle<double>(row[19]);
    tlValue = convertAndHandle<double>(row[20]);
    trValue = convertAndHandle<double>(row[21]);
    keyDE = row[3] + row[4];
    specLow = convertAndHandle<double>(row[6]);
    specHigh = convertAndHandle<double>(row[8]);
    measureTime = row[11];
    testProg = row[22];
    oosCount = convertAndHandle<int>(row[23]);
    keyRoute = row[3] + row[4] + row[25];
}
std::string WAT::getKeyDE() const
{
    std::string keyD = lot.substr(0, 5) + wafer;
    return keyD;
}
std::string WAT::getTestType() const
{
    return testType;
}
int WAT::getoosCount() const
{
    return oosCount;
}
std::string WAT::gettestProg() const
{
    return testProg;
}
std::string WAT::getMeasureTime() const
{
    return measureTime;
}
double WAT::getCtrlLow() const
{
    return ctrlLow;
}
double WAT::getCtrlHigh() const
{
    return ctrlHigh;
};
double WAT::getSpecTarget() const
{
    return (specLow + specHigh) * 0.5;
}
double WAT::getSpeclow() const
{
    return specLow;
};
double WAT::getSpechigh() const
{
    return specHigh;
};
std::string WAT::getParameter() const
{
    return parameter;
}
double WAT::getTValue() const
{
    return tValue;
}
double WAT::getBValue() const
{
    return bValue;
}
double WAT::getCValue() const
{
    return cValue;
}
double WAT::getRValue() const
{
    return rValue;
}
double WAT::getLValue() const
{
    return lValue;
}
double WAT::getBLValue() const
{
    return bValue;
}
double WAT::getBRValue() const
{
    return rValue;
}
double WAT::getTLValue() const
{
    return tValue;
}
double WAT::getTRValue() const
{
    return rValue;
}
double WAT::getAverage() const
{
    return average;
}
double WAT::calculateStandardDeviation() const
{
    // Store the non-zero values in a vector for calculation
    std::vector<double> values;
    if (tValue != 0.0)
        values.push_back(tValue);
    if (bValue != 0.0)
        values.push_back(bValue);
    if (cValue != 0.0)
        values.push_back(cValue);
    if (lValue != 0.0)
        values.push_back(lValue);
    if (rValue != 0.0)
        values.push_back(rValue);
    if (brValue != 0.0)
        values.push_back(brValue);
    if (blValue != 0.0)
        values.push_back(blValue);
    if (tlValue != 0.0)
        values.push_back(blValue);
    if (trValue != 0.0)
        values.push_back(blValue);
    if (values.size() < 2)
    {
        // Not enough values to calculate standard deviation
        return 0.0; // Return some default value or handle this case as needed
    }
    // Calculate the mean (average)
    double mean = 0.0;
    for (double value : values)
    {
        mean += value;
    }
    mean /= values.size();
    // Calculate the squared differences
    double squaredDifferencesSum = 0.0;
    for (double value : values)
    {
        double diff = value - mean;
        squaredDifferencesSum += diff * diff;
    }
    // Divide the sum of squared differences by the count - 1 (sample standard deviation)
    double variance = squaredDifferencesSum / (values.size() - 1);
    // Take the square root to get the standard deviation
    double stdDeviation = std::sqrt(variance);
    return stdDeviation;
}
void writeWATToStream(std::ofstream &os, const WAT &b)
{
    os << b.getParameter() << ","
       << b.getSpeclow() << ","
       << b.getSpecTarget() << ","
       << b.getSpechigh() << ","
       << b.getAverage() << ","
       << b.getTValue() << ","
       << b.getBValue() << ","
       << b.getCValue() << ","
       << b.getRValue() << ","
       << b.getLValue() << ","
       << b.calculateStandardDeviation() << ",";
}
std::string WAT::getKeyRoute() const
{
    return keyRoute;
}