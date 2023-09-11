#include "dataentry.h"
#include <string>
#include <iostream>
#include "datacheck.h"
#include <fstream>
DataEntry::DataEntry() {}
DataEntry::DataEntry(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    product = row[findValue(titleTest, "PRODUCT")];
    process = row[findValue(titleTest, "PROCESS")];
    lot = row[findValue(titleTest, "LOT")];
    wafer = row[findValue(titleTest, "WAFER")];
    parameter = row[findValue(titleTest, "PARAMETER")];
    corrlot = row[findValue(titleTest, "CORR_LOT")];
    wipTimevec.push_back(row[findValue(titleTest, "WIP_MVIN_TIME")]);
    wipTimevec.push_back(row[findValue(titleTest, "WIP_CHAMBER")]);
    wip_Route_Stepvec.push_back(row[findValue(titleTest, "WIP_ROUTE")]);
    wip_Route_Stepvec.push_back(row[findValue(titleTest, "ROUTENAME")]);
    wip_Route_Stepvec.push_back(row[findValue(titleTest, "WIP_STEP")]);
    wip_Route_Stepvec.push_back(row[findValue(titleTest, "STEPNAME")]);
    wip_PU_Recipevec.push_back(row[findValue(titleTest, "WIP_PUTYPE")]);
    wip_PU_Recipevec.push_back(row[findValue(titleTest, "WIP_PU")]);
    wip_PU_Recipevec.push_back(row[findValue(titleTest, "WIP_EQUIPMENT")]);
    wip_PU_Recipevec.push_back(row[findValue(titleTest, "WIP_RECIPE")]);
    wip_PU_Recipevec.push_back(row[findValue(titleTest, "WIP_EQCHAMBER")]);
    keyde = lot + wafer + parameter + wip_Route_Stepvec[1];
}
void DataEntry::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
void DataEntry::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) {}
std::string DataEntry::getProduct() const
{
    return product;
}
std::string DataEntry::getProcess() const
{
    return process;
}
std::string DataEntry::getLot() const
{
    return lot;
}
std::string DataEntry::getWafer() const
{
    return wafer;
}
std::string DataEntry::getkey_Wafer_Routename() const
{
    return lot.substr(0, 5) + wafer + wip_Route_Stepvec[1];
}
std::string DataEntry::getKeyDE() const
{
    // std::string keyD = lot.substr(0, 5) + wafer;
    return keyde;
}
void DataEntry::setwipTimevec(const std::vector<std::string> &row, std::vector<std::pair<std::string, int>> titleTest)
{
    wipTimevec[0] = row[findValue(titleTest, "WIP_MVIN_TIME")];
    wipTimevec[1] = row[findValue(titleTest, "WIP_CHAMBER")];
}
std::string DataEntry::getwipIntime() const
{
    return wipTimevec[0];
}
std::string DataEntry::getwipOuttime() const
{
    return wipTimevec[1];
}
std::string DataEntry::getwipRounteName() const
{
    return wip_Route_Stepvec[1];
}
std::string DataEntry::getwipStepName() const
{
    return wip_Route_Stepvec[3];
}
std::string DataEntry::getwipPU() const
{
    return wip_PU_Recipevec[1];
}
void writeBasicToStream(std::ofstream &os, const DataEntry &a)
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
void DataEntry::setExp()
{
    condition = true;
}
