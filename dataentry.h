#ifndef DATAENTRY_H
#define DATAENTRY_H
#include <string>
#include <vector>
#include <fstream>
class DataEntry
{
private:
    std::string product;
    std::string process;
    std::string lot;
    std::string wafer;
    std::string keyDE;
    std::vector<std::string> wipTimevec;
    std::vector<std::string> wipRoutendStepvec; // route route name,step,step name
    std::vector<std::string> wipPUAndRecipevec; // WPU type,PU,Equipment,Recipe,chamber
    bool condition = false;

public:
    std::string parameter;
    std::string corrLot;
    DataEntry() {}
    DataEntry(const std::vector<std::string> &row);
    size_t size() const;
    std::string getProduct() const;
    std::string getProcess() const;
    std::string getLot() const;
    std::string getWafer() const;
    std::string getKeyDE() const;
    void setwipTimevec(const std::vector<std::string> &);
    std::string getwipRounteName() const;
    std::string getwipStepName() const;
    std::string getwipIntime() const;
    std::string getwipOuttime() const;
    std::string getwipPU() const;
    void setExp();
    bool getCondition() const;
    friend void writeBasicToStream(std::ofstream &os, const DataEntry &a);
};
#endif