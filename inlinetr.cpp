#include "dataentry.h"
#include "inlinetr.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <stdexcept>

InlineTR::InlineTR(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) : inline_TKvec(1, std::vector<double>(9, 0.0)), inlineTK_Calculate_vec(1, std::vector<double>(10, 0.0))
{
    lot = row[findValue(titleTest, "LOT")];
    wafer = row[findValue(titleTest, "WAFER")];
    parameter = row[findValue(titleTest, "PARAMETER")];
    route = row[findValue(titleTest, "ROUTENAME")];
    product = row[findValue(titleTest, "PRODUCT")]; // done
    process = row[findValue(titleTest, "PROCESS")]; // done
    step = row[findValue(titleTest, "STEP")];
    routeName = row[findValue(titleTest, "ROUTENAME")];    // done
    stepName = row[findValue(titleTest, "STEPNAME")];      // done
    processUnit = row[findValue(titleTest, "PROCESS_EQ")]; // done
    measDate = row[findValue(titleTest, "MEASURE_DATE")];
    recipe1 = row[findValue(titleTest, "RECIPE")]; // done
    measPU = row[findValue(titleTest, "MEASURE_EQ")];
    moveOutTime = row[findValue(titleTest, "PROCESS_TIME")]; // done                                                                          // 20
    moveOutOperator = row[findValue(titleTest, "OPERATOR")]; // donePROCESS_TIME
    setFileDataInit(row, parameter, titleTest);
}

void InlineTR::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    if (row[findValue(titleTest, focusitem)] == "F-RNG")
    {
        inlineTK_Calculate_vec[0][9] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]); // 3set cuz 3 platen;by4
    }
    else if (row[findValue(titleTest, focusitem)] == "TK-GOOD")
    { // 22
        inline_TKvec[0][0] = convertAndHandle<double>(row[findValue(titleTest, "M1")]);
        inline_TKvec[0][1] = convertAndHandle<double>(row[findValue(titleTest, "M2")]);
        inline_TKvec[0][2] = convertAndHandle<double>(row[findValue(titleTest, "M3")]);
        inline_TKvec[0][3] = convertAndHandle<double>(row[findValue(titleTest, "M4")]);
        inline_TKvec[0][4] = convertAndHandle<double>(row[findValue(titleTest, "M5")]);
        inline_TKvec[0][5] = convertAndHandle<double>(row[findValue(titleTest, "M6")]);
        inline_TKvec[0][6] = convertAndHandle<double>(row[findValue(titleTest, "M7")]);
        inline_TKvec[0][7] = convertAndHandle<double>(row[findValue(titleTest, "M8")]);
        inline_TKvec[0][8] = convertAndHandle<double>(row[findValue(titleTest, "M9")]);
        inlineTK_Calculate_vec[0][0] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]);
        inlineTK_Calculate_vec[0][2] = convertAndHandle<double>(row[findValue(titleTest, "DEV")]);
        inlineTK_Calculate_vec[0][3] = convertAndHandle<double>(row[findValue(titleTest, "MIN_VALUE")]);
        inlineTK_Calculate_vec[0][4] = convertAndHandle<double>(row[findValue(titleTest, "MAX_VALUE")]);
        inlineTK_Calculate_vec[0][5] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_HIGH")]);
        inlineTK_Calculate_vec[0][6] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_LOW")]);
        inlineTK_Calculate_vec[0][7] = 0.5 * (inlineTK_Calculate_vec[0][5] + inlineTK_Calculate_vec[0][6]); // 3set cuz 3 platen;by4
                                                                                                            // 3set cuz 3 platen
    }
    else if (row[findValue(titleTest, focusitem)] == "TK-GOOD-RANGE")
    {
        inlineTK_Calculate_vec[0][1] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]);
        inlineTK_Calculate_vec[0][8] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_HIGH")]); // 3set cuz 3 platen
    }
}
void InlineTR::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    if (focusitem == "F-RNG")
    {
        inlineTK_Calculate_vec[0][9] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]); // 3set cuz 3 platen;by4
    }
    else if (focusitem == "TK-GOOD")
    { // 22
        inline_TKvec[0][0] = convertAndHandle<double>(row[findValue(titleTest, "M1")]);
        inline_TKvec[0][1] = convertAndHandle<double>(row[findValue(titleTest, "M2")]);
        inline_TKvec[0][2] = convertAndHandle<double>(row[findValue(titleTest, "M3")]);
        inline_TKvec[0][3] = convertAndHandle<double>(row[findValue(titleTest, "M4")]);
        inline_TKvec[0][4] = convertAndHandle<double>(row[findValue(titleTest, "M5")]);
        inline_TKvec[0][5] = convertAndHandle<double>(row[findValue(titleTest, "M6")]);
        inline_TKvec[0][6] = convertAndHandle<double>(row[findValue(titleTest, "M7")]);
        inline_TKvec[0][7] = convertAndHandle<double>(row[findValue(titleTest, "M8")]);
        inline_TKvec[0][8] = convertAndHandle<double>(row[findValue(titleTest, "M9")]);
        inlineTK_Calculate_vec[0][0] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]);
        inlineTK_Calculate_vec[0][1] = convertAndHandle<double>(row[findValue(titleTest, "DEV")]);
        inlineTK_Calculate_vec[0][3] = convertAndHandle<double>(row[findValue(titleTest, "MIN_VALUE")]);
        inlineTK_Calculate_vec[0][4] = convertAndHandle<double>(row[findValue(titleTest, "MAX_VALUE")]);
        inlineTK_Calculate_vec[0][5] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_HIGH")]);
        inlineTK_Calculate_vec[0][6] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_LOW")]);
        inlineTK_Calculate_vec[0][7] = 0.5 * (inlineTK_Calculate_vec[0][5] + inlineTK_Calculate_vec[0][6]); // 3set cuz 3 platen;by4
                                                                                                            // 3set cuz 3 platen
    }
    else if (focusitem == "TK-GOOD-RANGE")
    {
        inlineTK_Calculate_vec[0][2] = convertAndHandle<double>(row[findValue(titleTest, "AVG_VALUE")]);
        inlineTK_Calculate_vec[0][8] = convertAndHandle<double>(row[findValue(titleTest, "SPEC_HIGH")]); // 3set cuz 3 platen
    }
}
size_t InlineTR::size() const
{
    return 45;
}
std::string InlineTR::getKeyDE() const
{
    return lot.substr(0, 5) + wafer + routeName + recipe1;
}
std::string InlineTR::getKeyDE(const int &i) const
{
    if (i == 1)
    {
        return lot.substr(0, 5) + wafer + routeName + processUnit;
    }
    else if (i == 2)
    {
        return lot.substr(0, 5) + wafer + routeName + recipe1 + moveOutTime;
    }
    else if (i == 3)
    {
        return lot.substr(0, 5) + wafer + routeName + recipe1;
    }
    else
    {
        return lot.substr(0, 5) + wafer + routeName + recipe1;
    }
}
std::vector<std::vector<double>> InlineTR::getInlineTKvec() const
{
    return inline_TKvec;
}
std::vector<std::vector<double>> InlineTR::getInlineTK_Calculate_vec() const
{
    return inlineTK_Calculate_vec;
}
void writeCMPEQToStream(std::ofstream &os, const InlineTR &d)
{
    os << d.getInlineTK_Calculate_vec()[0][1] << ",";
    ;
}
std::string InlineTR::getKeyRouteName() const
{
    return lot + routeName + recipe1;
}
std::string InlineTR::getKeyRouteName(const int &i) const
{
    if (i == 2)
    {
        return lot + routeName + recipe1 + moveOutTime;
    }
    else if (i == 1)
    {
        return lot + routeName + recipe1;
    }
    else
    {
        return lot + routeName + recipe1;
    }
}
std::string InlineTR::getMoveOutTime() const
{
    return moveOutTime;
}
std::string InlineTR::getParameter() const
{
    return parameter;
}
std::string InlineTR::getKeyWafer() const
{
    return lot.substr(0, 5) + wafer;
}
std::string InlineTR::getRecipe() const
{
    return recipe1;
}
void writeInlineToStream(std::ofstream &os, const InlineTR &d)
{
    os << d.getInlineTK_Calculate_vec()[0][0] << ","
       << d.getInlineTK_Calculate_vec()[0][1] << ","
       << d.getInlineTK_Calculate_vec()[0][2] << ","
       << d.getInlineTKvec()[0][0] << ","
       << d.getInlineTKvec()[0][1] << ","
       << d.getInlineTKvec()[0][2] << ","
       << d.getInlineTKvec()[0][3] << ","
       << d.getInlineTKvec()[0][4] << ","
       << d.getInlineTKvec()[0][5] << ","
       << d.getInlineTKvec()[0][6] << ","
       << d.getInlineTKvec()[0][7] << ","
       << d.getInlineTKvec()[0][8] << ","
       << d.getInlineTK_Calculate_vec()[0][4] << ","
       << d.getInlineTK_Calculate_vec()[0][5] << ","
       << d.getInlineTK_Calculate_vec()[0][6] << ",";
}
void writeBasicToStream(std::ofstream &os, const InlineTR &a)
{
    os << a.getLot() << ","
       << a.getWafer() << ","
       << a.getProduct() << ","
       << a.getProcess() << ","
       << a.getMoveOutTime() << ","
       << a.getProcessPU() << ","
       << a.getRouteName() << ","
       << a.getRecipe() << ","
       << a.getInlineTK_Calculate_vec()[0][0] << ","
       << a.getInlineTK_Calculate_vec()[0][1] << ","
       << a.getInlineTK_Calculate_vec()[0][2] << ","
       << a.getInlineTKvec()[0][0] << ","
       << a.getInlineTKvec()[0][1] << ","
       << a.getInlineTKvec()[0][2] << ","
       << a.getInlineTKvec()[0][3] << ","
       << a.getInlineTKvec()[0][4] << ","
       << a.getInlineTKvec()[0][5] << ","
       << a.getInlineTKvec()[0][6] << ","
       << a.getInlineTKvec()[0][7] << ","
       << a.getInlineTKvec()[0][8] << ","
       << a.getInlineTK_Calculate_vec()[0][4] << ","
       << a.getInlineTK_Calculate_vec()[0][5] << ","
       << a.getInlineTK_Calculate_vec()[0][6] << ",";
}
std::string InlineTR::getLot() const { return lot; }
std::string InlineTR::getWafer() const { return wafer; }
std::string InlineTR::getProduct() const { return product; }
std::string InlineTR::getProcess() const { return process; }
std::string InlineTR::getRouteName() const { return routeName; }
std::string InlineTR::getStepName() const { return stepName; };
std::string InlineTR::getProcessPU() const { return processUnit; }
void writeInlineToStream3(std::ofstream &os, const InlineTR &d)
{
    os << d.getLot() << ","
       << d.getWafer() << ","
       << d.getProduct() << ","
       << d.getProcess() << ","
       << d.getRouteName() << ","
       << d.getProcessPU() << ","
       << d.getInlineTK_Calculate_vec()[0][0] << ","
       << d.getInlineTK_Calculate_vec()[0][1] << ","
       << d.getInlineTK_Calculate_vec()[0][2] << ","
       << d.getInlineTKvec()[0][0] << ","
       << d.getInlineTKvec()[0][1] << ","
       << d.getInlineTKvec()[0][2] << ","
       << d.getInlineTKvec()[0][3] << ","
       << d.getInlineTKvec()[0][4] << ","
       << d.getInlineTKvec()[0][5] << ","
       << d.getInlineTKvec()[0][6] << ","
       << d.getInlineTKvec()[0][7] << ","
       << d.getInlineTKvec()[0][8] << ",";
}