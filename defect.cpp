#include "defect.h"
#include <string>
#include <iostream>
#include "datacheck.h"
#include <fstream>
Defect::Defect() {}
Defect::Defect(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    product = row[findValue(titleTest, "PRODUCT")];
    process = row[findValue(titleTest, "PROCESS")];
    lot = row[findValue(titleTest, "LOT")];
    wafer = row[findValue(titleTest, "WAFER")];
    corrLot = row[findValue(titleTest, "CORR_LOT")];
    wipTimevec.push_back(row[findValue(titleTest, "PROCESS_TIME")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "DD_ROUTE")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "PROCESS_ROUTE")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "DD_STEP")]);
    wipRoutendStepvec.push_back(row[findValue(titleTest, "PROCESS_STEP")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "PROCESS_EQ")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "PROCESS_EQ")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "WIP_RECIPE")]);
    wipPUAndRecipevec.push_back(row[findValue(titleTest, "LOT_TYPE")]);
    // keyDE =
    defect_count = convertAndHandle<double>(row[findValue(titleTest, "DEFECT_COUNT")], defaultDouble);
}
void Defect::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
void Defect::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
std::string Defect::getProduct() const
{
    return product;
}
std::string Defect ::getProcess() const
{
    return process;
}
std::string Defect::getLot() const
{
    return lot;
}
std::string Defect::getWafer() const
{
    return wafer;
}
std::string Defect::getKeyDE() const
{
    return lot + wafer + wipRoutendStepvec[1] + wipPUAndRecipevec[2];
}
std::string Defect::getwipIntime() const
{
    return wipTimevec[0];
}
std::string Defect::getwipOuttime() const
{
    return wipTimevec[1];
}
std::string Defect::getwipRounteName() const
{
    return wipRoutendStepvec[1];
}
std::string Defect::getwipStepName() const
{
    return wipRoutendStepvec[3];
}
std::string Defect::getwipPU() const
{
    return wipPUAndRecipevec[1];
}
void writeBasicToStream(std::ofstream &os, const Defect &a)
{
    os << a.getLot() << ","
       << a.getWafer() << ","
       << a.getProduct() << ","
       << a.getwipIntime() << ","
       << a.getwipPU() << ","
       << a.getwipRounteName() << ","
       << a.getwipStepName() << ","
       << a.getdefect() << ","
       << a.getSpecLow() << ","
       << a.getSpecHigh() << ",";
}
void Defect::setExp()
{
    condition = true;
}
std::string Defect::getKeyRouteName() const
{
    return lot.substr(0, 5) + wipRoutendStepvec[1] + wipPUAndRecipevec[2];
}
std::string Defect::getKeyRouteName(const int &i) const
{
    if (i == 1)
    {
        return lot.substr(0, 5) + wipRoutendStepvec[1] + wipPUAndRecipevec[0];
    }
    else
    {
        return lot.substr(0, 5) + wipRoutendStepvec[1] + wipPUAndRecipevec[2];
    }
}
std::string Defect::getKeyDE(const int &i) const
{
    if (i == 1)
    {
        return lot.substr(0, 5) + wafer + wipRoutendStepvec[1] + wipPUAndRecipevec[0];
    }
    else
    {
        return lot + wafer + wipRoutendStepvec[1] + wipPUAndRecipevec[2];
    }
}
double Defect::getdefect() const
{
    return defect_count;
}
double Defect::getSpecLow() const
{
    return defect_spec_low;
}
double Defect::getSpecHigh() const
{
    return defect_spec_high;
}