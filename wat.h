#ifndef WAT_H
#define WAT_H
#include "dataentry.h"
#include <string>
#include <iostream>
#include <string>
#include "datacheck.h"
class WAT
{
private:
    double tValue;
    double bValue;
    double cValue;
    double lValue;
    double rValue;
    double blValue;
    double brValue;
    double tlValue;
    double trValue;
    double average;
    std::string testProg;
    int oosCount;
    std::string parameter;
    std::string product;
    double stDevWAT;
    double specLow;
    double specHigh;
    double ctrlLow;
    double ctrlHigh;
    std::string measureTime;
    std::string testType;
    std::string keyDE;
    std::string lot;
    std::string wafer;
    std::string keyRoute;

public:
    WAT() {}
    std::string getKeyDE() const;
    WAT(const std::vector<std::string> &row);
    void setTValue(const std::vector<std::string> &row);
    double getTValue() const;
    double getBValue() const;
    double getCValue() const;
    double getRValue() const;
    double getLValue() const;
    double getBLValue() const;
    double getBRValue() const;
    double getTLValue() const;
    double getTRValue() const;
    double getAverage() const;
    double calculateStandardDeviation() const;
    std::string getParameter() const;
    double getSpeclow() const;
    double getSpechigh() const;
    double getSpecTarget() const;
    double getCtrlLow() const;
    double getCtrlHigh() const;
    std::string getMeasureTime() const;
    std::string gettestProg() const;
    int getoosCount() const;
    std::string getTestType() const;
    friend void writeWATToStream(std::ofstream &os, const WAT &a);
    std::string getKeyRoute() const;
};
#endif
