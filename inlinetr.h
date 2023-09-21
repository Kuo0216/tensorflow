#ifndef INLINETR_H
#define INLINETR_H
#include <string>
#include <vector>
class InlineTR
{
private:
    // std::string keyDE;
    std::string parameter;
    std::vector<std::vector<double>> inline_TKvec; // M1 to M9
    std::vector<std::vector<double>> inlineTK_Calculate_vec;
    // average 0,range 1,stdev 2,max 3,min 4,speclow 5,spechigh 6, spec target 7,range spec 8
    // std::string keyRoute;
    std::string lot;             // 0
    std::string wafer;           // 1
    std::string route;           // 4
    std::string product;         // 5
    std::string process;         // 6
    std::string step;            // 7
    std::string routeName;       // 8
    std::string stepName;        // 9
    std::string processUnit;     // 10
    std::string measDate;        // 11
    std::string recipe1;         // 13
    std::string measPU;          // 15
    std::string moveOutTime;     // 16
    std::string moveOutOperator; // 20
public:
    InlineTR() {}
    InlineTR(const std::vector<std::string> &row);
    void setFileData(const std::vector<std::string> &, const int &);
    void setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    InlineTR(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    std::vector<std::vector<double>> getInlineTK_Calculate_vec() const;
    std::vector<std::vector<double>> getInlineTKvec() const;
    std::string getKeyDE() const;
    std::string getKeyDE(const int &i) const;
    std::string getKeyWafer() const;
    // std::string getKeyEQ_Route_PU_MoveOut() const;
    std::string getKeyRouteName(const int &i) const;
    std::string getRecipe() const;
    std::string getKeyRouteName() const;
    std::string getMoveOutTime() const;
    std::string getParameter() const;
    std::string getLot() const;
    std::string getWafer() const;
    std::string getProduct() const;
    std::string getProcess() const;
    std::string getRouteName() const;
    std::string getStepName() const;
    std::string getProcessPU() const;
    size_t size() const;
    friend void writeCMPEQToStream(std::ofstream &os, const InlineTR &a);
    friend void writeBasicToStream(std::ofstream &os, const InlineTR &a);
    friend void writeInlineToStream(std::ofstream &os, const InlineTR &d);
    friend void writeInlineToStream3(std::ofstream &os, const InlineTR &d);
};
#endif // DATAENTRYEQ_H