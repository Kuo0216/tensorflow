#ifndef DEAFECT_H
#define DEAFECT_H
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
class Defect
{
private:
    std::string product;
    std::string process;
    std::string lot;
    std::string wafer;
    std::vector<std::string> wipTimevec;        // movein 0 moveout 1
    std::vector<std::string> wipRoutendStepvec; // route route name,step,step name
    std::vector<std::string> wipPUAndRecipevec; // WPU type,PU,Equipment,Recipe,chamber
    bool condition = false;
    double defect_count = 0;
    double defect_spec_low = 0;
    double defect_spec_high = 100;
    std::string corrLot;

public:
    Defect();
    Defect(const std::vector<std::string> &row);
    Defect(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
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
    std::string getKeyDE(const int &) const;
    std::string getKeyRouteName() const;
    std::string getKeyRouteName(const int &i) const;
    std::string getwipRounteName() const;
    std::string getwipStepName() const;
    std::string getwipIntime() const;
    std::string getwipOuttime() const;
    std::string getwipPU() const;
    double getSpecLow() const;
    double getSpecHigh() const;
    double getdefect() const;
    bool getCondition() const;
    friend void writeBasicToStream(std::ofstream &os, const Defect &a);
};
#endif