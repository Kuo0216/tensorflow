#include "runsheet.h"
#include <string>
#include <iostream>
#include "datacheck.h"
#include <fstream>
Runsheet::Runsheet() {}

Runsheet::Runsheet(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    product = row[findValue(titleTest, "PRODUCT")];
    process = row[findValue(titleTest, "PROCESS")];
    lot = row[findValue(titleTest, "LOT")];
    corrLot = row[findValue(titleTest, "CORR_LOT")];
    wipTimevec.push_back(row[findValue(titleTest, "WIP_MVIN_TIME")]);
    wipTimevec.push_back(row[findValue(titleTest, "WIP_MVOUT_TIME")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "ROUTE")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "ROUTENAME")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "STEP")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "STEPNAME")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_PUTYPE")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_PU")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_EQUIPMENT")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_RECIPE1")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_EQCHAMBER")]);
    keyDE = wipPUAndRecipevec[1] + wipTimevec[0];
}
void Runsheet::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
void Runsheet::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
std::string Runsheet::getWafer() const
{
    return wipRoutendStepvec[0];
}
std::string Runsheet::getProduct() const
{
    return product;
}
std::string Runsheet::getProcess() const
{
    return process;
}
std::string Runsheet::getLot() const
{
    return lot;
}
std::string Runsheet::getKeyDE() const
{
    std::string keyD = lot + wipPUAndRecipevec[1] + wipTimevec[1];
    return keyD;
}
std::string Runsheet::getwipIntime() const
{
    return wipTimevec[0];
}
std::string Runsheet::getwipOuttime() const
{
    return wipTimevec[1];
}
std::string Runsheet::getwipRounteName() const
{
    return wipRoutendStepvec[1];
}
std::string Runsheet::getwipStepName() const
{
    return wipRoutendStepvec[3];
}
std::string Runsheet::getwipPU() const
{
    return wipPUAndRecipevec[1];
}
void writeBasicToStream(std::ofstream &os, const Runsheet &a)
{
    os << a.getLot() << ","
       << a.getWafer() << ","
       << a.getProduct() << ","
       << a.getwipIntime() << ","
       << a.getwipPU() << ","
       << a.getwipRounteName() << ","
       << a.getwipStepName() << ","
       << a.getKeyDE() << ",";
}
void Runsheet::setExp()
{
    condition = true;
}
