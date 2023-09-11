#include "wat.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <cmath>
WAT::WAT(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) : tValue(0.0), bValue(0.0), cValue(0.0), lValue(0.0), rValue(0.0),
                                                                                                                                  blValue(0.0), brValue(0.0), tlValue(0.0), trValue(0.0), oosCount(0.0), stDevWAT(0.0), average(0.0), specLow(0.0), specHigh(0.0), ctrlLow(0.0), ctrlHigh(0.0)
{
    average = convertAndHandle<double>(row[findValue(titleTest, "AVERAGE")]);
    tValue = convertAndHandle<double>(row[findValue(titleTest, "T_VALUE")]);
    bValue = convertAndHandle<double>(row[findValue(titleTest, "B_VALUE")]); // 14
    cValue = convertAndHandle<double>(row[findValue(titleTest, "C_VALUE")]); // 15
    lValue = convertAndHandle<double>(row[findValue(titleTest, "L_VALUE")]); // 16
    rValue = convertAndHandle<double>(row[findValue(titleTest, "R_VALUE")]); // 17
    blValue = convertAndHandle<double>(row[findValue(titleTest, "BL_VALUE")]);
    brValue = convertAndHandle<double>(row[findValue(titleTest, "BR_VALUE")]);
    tlValue = convertAndHandle<double>(row[findValue(titleTest, "TL_VALUE")]);
    trValue = convertAndHandle<double>(row[findValue(titleTest, "TR_VALUE")]);
    testProg = row[findValue(titleTest, "TEST_PROG")];
    oosCount = convertAndHandle<int>(row[findValue(titleTest, "OOS_COUNT")]);
    parameter = row[findValue(titleTest, "PARAMETER")];
    product = row[findValue(titleTest, "PRODUCT")];
    process = row[findValue(titleTest, "PROCESS")];
    stDevWAT = calculateStandardDeviation();
    specLow = convertAndHandle<double>(row[findValue(titleTest, "SPEC_LOW")]);
    specHigh = convertAndHandle<double>(row[findValue(titleTest, "SPEC_HIGH")]);
    ctrlLow = convertAndHandle<double>(row[findValue(titleTest, "CTRL_LOW")]);
    ctrlHigh = convertAndHandle<double>(row[findValue(titleTest, "CTRL_HIGH")]);
    measureTime = row[findValue(titleTest, "MEASURE_TIME")];
    wipmintime = row[findValue(titleTest, "WIP_MVIN_TIME")];
    lot = row[findValue(titleTest, "LOT")];
    wafer = row[findValue(titleTest, "WAFER")];
    wipPU = row[findValue(titleTest, "WIP_PU")];
    routename = row[findValue(titleTest, "ROUTENAME")];
    stepname = row[findValue(titleTest, "STEPNAME")];
    keyRoute = lot.substr(0, 5) + wafer + routename;
    keyDE = lot + wafer + parameter + routename;
}
void WAT::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    std::cout << "WAT data" << std::endl;
}
void WAT::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    std::cout << "WAT set_file_data_init" << std::endl;
}
std::string WAT::getKeyDE() const
{
    // std::string keyD = lot.substr(0, 5) + wafer;
    return keyDE;
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
    os << b.getLot() << ","
       << b.getWafer() << ","
       << b.getProduct() << ","
       << b.getProcessTime() << ","
       << b.getWipPU() << ","
       << b.getRoutename() << ","
       << b.getStepname() << ","
       << b.getParameter() << ","
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
void WAT::setFileData(const std::vector<std::string> &row, const int &i)
{
    if (i == 1)
    {
        // 3set cuz 3 platen
    }
    else if (i == 2)
    { // 22
      // 3set cuz 3 platen
    }
    else if (i == 3)
    {
        // 3set cuz 3 platen
    }
}
std::string WAT::getkey_Wafer_Routename() const
{
    return lot.substr(0, 5) + wafer + routename;
}
std::string WAT::getkey_Routename() const
{
    return lot.substr(0, 5) + routename;
}
std::string WAT::getProduct() const
{
    return product;
}
std::string WAT::getProcess() const
{
    return process;
}
std::string WAT::getLot() const
{
    return lot;
}
std::string WAT::getWafer() const
{
    return wafer;
}
std::string WAT::getProcessTime() const
{
    return wipmintime;
}
std::string WAT::getWipPU() const
{
    return wipPU;
}
std::string WAT::getRoutename() const
{
    return routename;
}
std::string WAT::getStepname() const
{
    return stepname;
}