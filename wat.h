#ifndef WAT_H
#define WAT_H
#include "dataentry.h"
#include <string>
#include <iostream>
#include <string>
#include "datacheck.h"
#include <vector>
#include <unordered_map>
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
    std::string process;
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
    std::string wipPU;
    std::string routename;
    std::string stepname;
    std::string wipmintime;

public:
    WAT() {}
    std::string getKeyDE() const;
    std::string getkey_Wafer_Routename() const;
    std::string getkey_Routename() const;
    WAT(const std::vector<std::string> &row);
    WAT(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setTValue(const std::vector<std::string> &row);
    void setFileData(const std::vector<std::string> &, const int &);
    void setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
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
    double getSpeclow() const;
    double getSpechigh() const;
    double getSpecTarget() const;
    double getCtrlLow() const;
    double getCtrlHigh() const;
    std::string getProcessTime() const;
    std::string getMeasureTime() const;
    std::string getParameter() const;
    std::string gettestProg() const;
    std::string getTestType() const;
    int getoosCount() const;
    std::string getKeyRoute() const;
    std::string getProduct() const;
    std::string getProcess() const;
    std::string getLot() const;
    std::string getWafer() const;
    std::string getWipPU() const;
    std::string getRoutename() const;
    std::string getStepname() const;
    friend void writeWATToStream(std::ofstream &os, const WAT &a);
};
#endif
