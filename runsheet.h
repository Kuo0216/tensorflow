#ifndef RUNSHEET_H
#define RUNSHEET_H
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
class Runsheet
{
private:
    std::string product;
    std::string process;
    std::string lot;
    std::string keyDE;
    std::vector<std::string> wipTimevec;
    std::vector<std::string> wipRoutendStepvec; // route route name,step,step name
    std::vector<std::string> wipPUAndRecipevec; // WPU type,PU,Equipment,Recipe,chamber
    bool condition = false;
    std::string corrLot;

public:
    Runsheet();
    Runsheet(const std::vector<std::string> &row);
    Runsheet(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileData(const std::vector<std::string> &, const int &);
    void setwipTimevec(const std::vector<std::string> &);
    void setExp();
    size_t size() const;
    std::string getProduct() const;
    std::string getProcess() const;
    std::string getLot() const;
    std::string getWafer() const;
    std::string getKeyDE() const;
    std::string getwipRounteName() const;
    std::string getwipStepName() const;
    std::string getwipIntime() const;
    std::string getwipOuttime() const;
    std::string getwipPU() const;
    bool getCondition() const;
    friend void writeBasicToStream(std::ofstream &os, const Runsheet);
};
#endif