#include "dataentry.h"
#include <string>
#include <iostream>
#include "datacheck.h"
#include <fstream>
DataEntry::DataEntry(const std::vector<std::string> &row)
{
    checkRowSize(row, 36);
    product = row[0];
    process = row[1];
    lot = row[3];
    wafer = row[4];
    parameter = row[5];
    corrLot = row[35];
    keyDE = lot + wafer;
    wipTimevec.push_back(row[28]);
    wipTimevec.push_back(row[29]);
    wipRoutendStepvec.push_back(row[24]);
    wipRoutendStepvec.push_back(row[33]);
    wipRoutendStepvec.push_back(row[25]);
    wipRoutendStepvec.push_back(row[34]);
    wipPUAndRecipevec.push_back(row[32]);
    wipPUAndRecipevec.push_back(row[26]);
    wipPUAndRecipevec.push_back(row[30]);
    wipPUAndRecipevec.push_back(row[27]);
    wipPUAndRecipevec.push_back(row[31]);
}
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
std::string DataEntry::getKeyDE() const
{
    std::string keyD = lot.substr(0, 5) + wafer;
    return keyD;
}
void DataEntry::setwipTimevec(const std::vector<std::string> &row)
{
    wipTimevec.push_back(row[28]);
    wipTimevec.push_back(row[29]);
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
    return wipRoutendStepvec[1];
}
std::string DataEntry::getwipStepName() const
{
    return wipRoutendStepvec[3];
}
std::string DataEntry::getwipPU() const
{
    return wipPUAndRecipevec[1];
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