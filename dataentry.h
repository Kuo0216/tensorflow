#ifndef DATAENTRY_H
#define DATAENTRY_H
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
const static std::unordered_map<std::string, bool> dataMap{
    {"LOT", true},
    {"PRODUCT", true},
    {"PROCESS", true},
};
class DataEntry
{
private:
    std::string lot;
    std::string wafer;
    std::string product;
    std::string process;
    std::string parameter;
    std::string keyde;
    std::string corrlot;
    std::vector<std::string> wipTimevec;
    std::vector<std::string> wip_Route_Stepvec; // route route name,step,step name
    std::vector<std::string> wip_PU_Recipevec;  // WPU type,PU,Equipment,Recipe,chamber
    bool condition = false;

public:
    DataEntry();
    DataEntry(const std::vector<std::string> &row);
    DataEntry(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileData(const std::vector<std::string> &, const int &);
    void setwipTimevec(const std::vector<std::string> &, std::vector<std::pair<std::string, int>> titleTest);
    void setExp();
    size_t size() const;
    std::string getProduct() const;
    std::string getProcess() const;
    std::string getLot() const;
    std::string getWafer() const;
    std::string getKeyDE() const;
    std::string getkey_Wafer_Routename() const;
    std::string getwipRounteName() const;
    std::string getwipStepName() const;
    std::string getwipIntime() const;
    std::string getwipOuttime() const;
    std::string getwipPU() const;
    bool getCondition() const;
    friend void writeBasicToStream(std::ofstream &os, const DataEntry &a);
};
#endif