#include "dataentry.h"
#include "inlinetr.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <stdexcept>
// InlineTR::InlineTR(const std::vector<std::string> &row)
//     : inline_TKvec(1, std::vector<double>(9, 0.0)), inlineTK_Calculate_vec(1, std::vector<double>(9, 0.0))
// {
//     checkRowSize(row, 45);
//     lot = row[0];
//     wafer = row[2];
//     parameter = row[9];
//     route = row[4];
//     product = row[5]; // done
//     process = row[3]; // done
//     step = row[7];
//     routeName = row[6];    // done
//     stepName = row[8];     // done
//     processUnit = row[14]; // done
//     measDate = row[11];
//     recipe1 = row[35]; // done
//     measPU = row[15];
//     moveOutTime = row[12];     // done                                                                          // 20
//     moveOutOperator = row[34]; // done
//     keyDE = lot.substr(0, 5) + wafer + routeName + processUnit + moveOutTime;
//     keyRoute = lot.substr(0, 5) + wafer + routeName; // 3set cuz 3 platen
// }
// InlineTR &InlineTR::setFileData(const std::vector<std::string> &row)
// {
//     if (row[9] == "F-RNG")
//     {
//         inlineTK_Calculate_vec[0][9] = convertAndHandle<double>(row[16]); // 3set cuz 3 platen;by4
//     }
//     else if (row[9] == "TK-GOOD")
//     { // 22
//         for (int j = 0; j < 9; j++)
//         {
//             inline_TKvec[0][j] = convertAndHandle<double>(row[21 + j]);
//         }
//         inlineTK_Calculate_vec[0][0] = convertAndHandle<double>(row[16]);
//         inlineTK_Calculate_vec[0][2] = convertAndHandle<double>(row[19]);
//         inlineTK_Calculate_vec[0][1] = convertAndHandle<double>(row[20]);
//         inlineTK_Calculate_vec[0][3] = convertAndHandle<double>(row[17]);
//         inlineTK_Calculate_vec[0][4] = convertAndHandle<double>(row[18]);
//         inlineTK_Calculate_vec[0][5] = convertAndHandle<double>(row[31]);
//         inlineTK_Calculate_vec[0][6] = convertAndHandle<double>(row[32]);
//         inlineTK_Calculate_vec[0][7] = 0.5 * (inlineTK_Calculate_vec[0][5] + inlineTK_Calculate_vec[0][6]); // 3set cuz 3 platen;by4
//                                                                                                             // 3set cuz 3 platen
//     }
//     else if (row[9] == "TK-GOOD-RANGE")
//     {
//         inlineTK_Calculate_vec[0][8] = convertAndHandle<double>(row[31]); // 3set cuz 3 platen
//     }
//     keyRoute = lot.substr(0, 5) + wafer + routeName;
//     return *this;
// }
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
    keyDE = lot.substr(0, 5) + wafer + routeName + processUnit + moveOutTime;
    keyRoute = lot.substr(0, 5) + wafer + processUnit + routeName + moveOutTime; // 3set cuz 3 platen
    setFileDataInit(row, parameter, titleTest);
}
void InlineTR::setFileData(const std::vector<std::string> &row, const int &i)
{
    if (row[i] == "F-RNG")
    {
        inlineTK_Calculate_vec[0][9] = convertAndHandle<double>(row[16]); // 3set cuz 3 platen;by4
    }
    else if (row[i] == "TK-GOOD")
    { // 22
        for (int j = 0; j < i; j++)
        {
            inline_TKvec[0][j] = convertAndHandle<double>(row[21 + j]);
        }
        inlineTK_Calculate_vec[0][0] = convertAndHandle<double>(row[16]);
        inlineTK_Calculate_vec[0][2] = convertAndHandle<double>(row[19]);
        inlineTK_Calculate_vec[0][1] = convertAndHandle<double>(row[20]);
        inlineTK_Calculate_vec[0][3] = convertAndHandle<double>(row[17]);
        inlineTK_Calculate_vec[0][4] = convertAndHandle<double>(row[18]);
        inlineTK_Calculate_vec[0][5] = convertAndHandle<double>(row[31]);
        inlineTK_Calculate_vec[0][6] = convertAndHandle<double>(row[32]);
        inlineTK_Calculate_vec[0][7] = 0.5 * (inlineTK_Calculate_vec[0][5] + inlineTK_Calculate_vec[0][6]); // 3set cuz 3 platen;by4
                                                                                                            // 3set cuz 3 platen
    }
    else if (row[i] == "TK-GOOD-RANGE")
    {
        inlineTK_Calculate_vec[0][8] = convertAndHandle<double>(row[31]); // 3set cuz 3 platen
    }
    keyRoute = lot.substr(0, 5) + wafer + routeName;
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
    keyRoute = lot.substr(0, 5) + wafer + routeName;
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
    keyRoute = lot.substr(0, 5) + wafer + routeName + recipe1;
}
size_t InlineTR::size() const
{
    return 45;
}
std::string InlineTR::getKeyDE() const
{
    return keyRoute;
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
std::string InlineTR::getMoveOutTime() const
{
    return moveOutTime;
}
std::string InlineTR::getKeyEQ_Route_PU_MoveOut() const
{
    return lot.substr(0, 5) + wafer + routeName + processUnit + moveOutTime;
}
std::string InlineTR::getParameter() const
{
    return parameter;
}
std::string InlineTR::getKeyWafer() const
{
    return lot.substr(0, 5) + wafer;
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
       << d.getInlineTKvec()[0][8] << ",";
}
std::string InlineTR::getLot() const { return lot; }
std::string InlineTR::getWafer() const { return wafer; }
std::string InlineTR::getProduct() const { return product; }
std::string InlineTR::getProcess() const { return process; }
std::string InlineTR::getRouteName() const { return routeName; }
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