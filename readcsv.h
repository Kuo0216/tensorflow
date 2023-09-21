#ifndef READCSV_H
#define READCSV_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <bitset>
#include "dataentry.h"
#include <set>
#include "defect.h"
#include "inlinetr.h"
#include "eqlot.h"
#include "dataentryeq.h"
#include "wat.h"
static std::unordered_map<std::string, std::string> UEDA_MaP = {
    {"WAT", "NA"},
    {"EQ_CMP", "CHAMBER"},
    {"RUNSHEET", "NA"},
    {"EQ_LOT", "RUN"},
    {"DEFECT", "DEFECT_COUNT"},
    {"INLINE", "PARAMETER"}};
static std::vector<std::string> inline_TK_DefaultTile{"LOT", "WAFER", "PRODUCT", "PROCESS", "PROCESS_EQ", "PROCESS_TIME", "MEASURE_EQ", "STEP", "RECIPE", "AVG_VALUE", "DEV", "M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "MAX_VALUE", "MIN_VALUE", "PARAMETER", "RANGE", "REDO_FLAG", "ROUTENAME", "SPEC_LOW", "SPEC_HIGH", "TK_RECIPE", "STEPNAME", "MEASURE_DATE", "MEASURE_TIME", "OPERATOR"};
static std::vector<std::string> cmpwaferDefaultTile{"LOT", "WAFER", "CHAMBER", "PRODUCT", "PROCESS", "ROUTENAME", "STEPNAME", "PROCESSINGUNIT", "RECIPE1", "MOVE_IN_TIME", "MOVE_OUT_TIME", "CON_HEAD_PRES", "CON_HEAD_RPM", "CON_PRES_DELTA", "Diff_MaxMin", "EP_TIME_1", "EP_TIME_2", "EP_TIME_3", "HEAD1_RPM", "HEAD2_RPM", "HEAD3_RPM", "HEAD4_RPM", "INNERTUBE1_PRES", "INNERTUBE2_PRES", "INNERTUBE3_PRES", "INNERTUBE4_PRES", "MEMBRANE1_PRES", "MEMBRANE2_PRES", "MEMBRANE3_PRES", "MEMBRANE4_PRES", "PLATEN_RPM", "RETA_RING1_PRES", "RETA_RING1_PRES", "RETA_RING1_PRES", "RETA_RING1_PRES", "SLURRY1_FLOW", "LOTJOBSEQUENCE", "RECIPE_STEP", "PUTYPE", "PUFAMILY", "AREA", "RECIPE2", "MOVE_IN_WAFER_COUNT", "MOVE_OUT_WAFER_COUNT", "MOVE_IN_OPERATOR", "MOVE_OUT_OPERATOR"};
static std::vector<std::string> runsheetDefaultTile{"LOTSEQUENCE", "ROUTEDES", "ROUTE_SEQUENCE", "STEP_SEQUENCE", "WIP_PUFAMILY", "WIP_RETICLE", "WIP_RECIPE2", "MOVE_OUT_WAFER_COUNT", "WIP_MOIN_OPERATOR", "WIP_MVOUT_OPERATOR", "WIP_AREA", "WIP_BOATPOSITION", "ISCUSTOMIZED", "CURRENTQUANTITY", "STDCYCLETIME", "LOTSTATUS", "STEPTYPE", "ROUTE", "STEP", "VIEW_FLAG", "P_TIME", "Q_TIME", "LOT_TYPE", "CORR_LOT", "PRODUCT", "PROCESS", "LOT", "WIP_PUTYPE", "WIP_PU", "WIP_CHAMBER", "WIP_EQUIPMENT", "WIP_EQCHAMBER", "WIP_RECIPE1", "WIP_MVIN_TIME", "ROUTENAME", "STEPNAME", "WIP_MVOUT_TIME", "MOVE_IN_WAFER_COUNT", "ISREWORK"};
static std::vector<std::string> defectDefaultTile{"DD_STEP", "BAD_DIE", "SPECIFICATION", "DD_ROUTE", "PROCESS_ROUTE", "PROCESS_STEP", "DEFECT_COUNT", "WIP_RECIPE", "LOT_TYPE", "CORR_LOT", "PRODUCT", "PROCESS", "LOT", "ORIGINAL_LOT", "PROCESS_DATE", "PROCESS_TIME", "WAFER", "MEASURE_TIME", "MEASURE_DATE", "PROCESS_EQ", "MEASURE_EQ", "SPEC_HIGH", "WEEK", "MONTH", "SPEC_TARGET", "VENDOR_LOT", "OOS_COUNT"};
static std::vector<std::string> eqlotDefaultTile{"LOT", "PROCESS", "PRODUCT", "LOTJOBSEQUENCE", "CHAMBER", "RECIPE_STEP", "PUTYPE", "ROUTE", "STEP", "ROUTENAME", "STEPNAME", "PROCESSINGUNIT", "PUFAMILY", "BOATPOSITION", "AREA", "RECIPE1", "RECIPE2", "RETICLE", "MOVE_IN_TIME", "MOVE_OUT_TIME", "MOVE_IN_OPERATOR", "MOVE_OUT_OPERATOR", "ISREWORK", "ISCUSTOMIZED", "MOVE_IN_WAFER_COUNT", "MOVE_OUT_WAFER_COUNT", "HEADSTATUS", "RUN", "Diff_MaxMin", "HEAD1USAGE", "HEAD1USINTIME", "HEAD2USAGE", "HEAD2USINTIME", "HEAD3USAGE", "HEAD3USINTIME", "HEAD4USAGE", "HEAD4USINTIME", "HEADSTATUS", "PADCOND1USAGE", "PADCOND2USAGE", "PADCOND3USAGE", "PLAT1USAGE", "PLAT1USINTIME", "PLAT2USAGE", "PLAT2USINTIME", "PLAT3USAGE", "PLAT3USINTIME", "POLISH_TIME1", "POLISH_TIME2", "POLISH_TIME3", "maxtime", "mintime"};
static std::vector<std::string> watDefaultTitle{"LOT", "WAFER", "PRODUCT", "PROCESS", "MEASURE_TIME", "AVERAGE", "B_VALUE", "BL_VALUE", "C_VALUE", "L_VALUE", "PARAMETER", "R_VALUE", "WIP_ROUTE", "SPEC_HIGH", "SPEC_LOW", "SPEC_TARGET", "T_VALUE", "TL_VALUE", "TR_VALUE", "WIP_EQUIPMENT", "WIP_MVIN_TIME", "WIP_PU", "WIP_RECIPE", "WIP_PUTYPE", "WIP_STEP", "WIP_ROUTE", "CORR_LOT", "ROUTENAME", "STEPNAME",
                                                "BR_VALUE", "TEST_PROG", "OOS_COUNT", "CTRL_LOW", "CTRL_HIGH", "BR_VALUE", "TEST_PROG", "OOS_COUNT", "CTRL_LOW", "CTRL_HIGH"};
static std::unordered_map<std::string, std::vector<std::string>> watDefaultMap{
    {"WAT", watDefaultTitle},
    {"INLINE", inline_TK_DefaultTile},
    {"DEFECT", defectDefaultTile},
    {"EQ_LOT", eqlotDefaultTile},
    {"RUNSHEET", runsheetDefaultTile},
    {"EQ_CMP", cmpwaferDefaultTile}};
static std::unordered_map<std::string, bool> existMap{
    {"WAT", false},
    {"INLINE", false},
    {"DEFECT", false},
    {"EQ_LOT", false},
    {"EQ_CMP", false}};
void setCaseType(const std::string &key, bool value)
{
    // Check if the key exists in the map
    auto it = existMap.find(key);
    // If the key exists, update its value
    if (it != existMap.end())
    {
        it->second = value;
    }
    else
    {
        // Key does not exist in the map
        std::cout << "Key \"" << key << "\" does not exist in the map." << std::endl;
    }
}
void handleString(std::string &token)
{
    if (!token.empty() && token.back() == '\r')
    {
        token.pop_back();
    }
}
void readHeader_Count_Reapeat(std::vector<int> &counVector, std::string &repeatHeader, std::unordered_map<std::string, int> &titleMap, std::string &token, int &idCounter)
{
    auto it = titleMap.find(token);
    if (it != titleMap.end())
    {
        counVector.push_back(idCounter);
        repeatHeader = token;
    }
    titleMap[token] = idCounter++;
    // std::cout << "With repeated title \t" << token << "\tis at column" << idCounter << '\n';
}
std::string judgeDatafiletype(std::unordered_map<std::string, int> &entryMap)
{
    std::string fileType;
    if (entryMap["AVERAGE"])
    {
        fileType = "WAT"; // NA
    }
    else if (entryMap["CON_HEAD_PRES"])
    {
        fileType = "EQ_CMP"; // CHAMBER
    }
    else if (entryMap["AVG_VALUE"])
    {
        fileType = "INLINE"; // PARAMETER
    }
    else if (entryMap["RUN"])
    {
        fileType = "EQ_LOT"; // PARAMETER
    }
    else if (entryMap["ISREWORK"])
    {
        fileType = "RUNSHEET"; // PARAMETER
    }
    else if (entryMap["DEFECT_COUNT"])
    {
        fileType = "DEFECT"; // PARAMETER
    }
    else
    {
        fileType = "Unknown";
        std::cout << "Unknown File! invalid title format please check !";
    }
    return fileType;
}
void defineColumnMap(std::vector<std::pair<std::string, int>> &theFileCurrentvec, const std::string fileTypeTest, std::vector<int> counVector, std::string repeatStartTitle, std::unordered_map<std::string, int> &titleMap)
{
    auto validFilevec = watDefaultMap[fileTypeTest];
    for (auto x : validFilevec)
    {
        // std::cout << "Push back\t" << x << "\tin the file column of\t " << titleMap[x] << '\n';
        if (x == repeatStartTitle)
        {
            int kk = counVector.size();
            while (!counVector.empty())
            {
                int l = titleMap[x];
                theFileCurrentvec.push_back({x, l - kk});
                counVector.pop_back();
                kk--;
            }
        }
        theFileCurrentvec.push_back({x, titleMap[x]});
    }
}
void handle_sort_remove_unique(std::vector<std::pair<std::string, int>> &theFileCurrentvec)
{
    auto customComparator = [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b)
    {
        return a.second < b.second;
    };
    std::sort(theFileCurrentvec.begin(), theFileCurrentvec.end(), customComparator);
    // for (const auto &pair : theFileCurrentvec)
    // {
    //     std::cout << pair.first << ": " << pair.second << std::endl;
    // }
    auto newEnd = std::unique(theFileCurrentvec.begin(), theFileCurrentvec.end());
    theFileCurrentvec.erase(newEnd, theFileCurrentvec.end());
    // for (auto elem : theFileCurrentvec)
    // {
    //     std::cout << "file template title of\t" << elem.first << "\tin the file column of\t " << elem.second << '\n';
    // }
}
template <typename T>
std::vector<T> readFileResult(const std::ifstream &file, const std::string &filePath)
{
    std::vector<T> entryvec;
    if (!file.is_open())
    {
        std::cout << "Error opening file: " << filePath << std::endl;
        return entryvec; // Return on error
    }
    std::cout << "Read file successfully : " << filePath << std::endl;
    return entryvec;
}
template <typename T>
std::vector<T> readCSV(const std::string &filePath, std::unordered_map<std::string, T> &entryMap)
{
    std::ifstream file(filePath);
    // std::vector<T> entryvec = readFileResult<T>(file, filePath);
    std::vector<T> entryvec = readFileResult<T>(file, filePath);
    std::string line;
    std::getline(file, line); // this is a title
    std::unordered_map<std::string, int> titleMap;
    std::istringstream iss(line);
    std::string token;
    int idCounter = 0;
    std::vector<int> counVector;
    std::string repeatStartTitle;
    while (std::getline(iss, token, ','))
    {
        handleString(token);
        readHeader_Count_Reapeat(counVector, repeatStartTitle, titleMap, token, idCounter);
    }
    std::string fileTypeTest = judgeDatafiletype(titleMap);
    setCaseType(fileTypeTest, true);
    std::cout << '\n';
    std::cout << "The file name : " << filePath << "\twhich is the title of " << fileTypeTest << '\n'; // debug
    std::cout << '\n';
    std::vector<std::pair<std::string, int>> theFileCurrentvec;
    defineColumnMap(theFileCurrentvec, fileTypeTest, counVector, repeatStartTitle, titleMap);
    // std::cout << "size of pushing vector (containing repeated) is\t " << theFileCurrentvec.size() << '\n';
    handle_sort_remove_unique(theFileCurrentvec);
    std::cout << "Handling the title (sorting and removing)" << '\n';
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        std::vector<std::string> reductin_row;
        std::vector<std::pair<std::string, int>> titleTest(theFileCurrentvec);
        unsigned j = 0;
        unsigned k = 0;
        while (std::getline(ss, cell, ','))
        {
            handleString(cell);
            if (k == j)
            {
                reductin_row.push_back(cell);
                titleTest.erase(titleTest.begin());
                j = titleTest.begin()->second;
                k++;
            }
            else
            {
                k++;
            }
            row.push_back(cell);
        }
        if (!UEDA_MaP[fileTypeTest].empty())
        {
            T entry(row, UEDA_MaP[fileTypeTest], theFileCurrentvec);
            std::string hashkey = entry.getKeyDE();
            auto it = entryMap.find(hashkey);
            if (it != entryMap.end())
            {
                // std::cout << hashkey << "\t"
                //           << "Updating\t" << fileTypeTest << "in the file\t" << filePath << "\twatch column : " << UEDA_MaP[fileTypeTest] << '\n';
                it->second.setFileData(row, UEDA_MaP[fileTypeTest], theFileCurrentvec);
            }
            else
            {
                entryMap[hashkey] = entry;
            }
            entryvec.push_back(entry);
        }
    }
    file.close();
    return entryvec;
}
static std::vector<std::string> pTitlevecwat{"LOT", "Wafer", "Product", "WAT_Average", "Inline_TK_avg"};
static std::vector<std::string> pTitlevecinline{"LOT", "Wafer", "Product", "TK Average", "P1 padlife"};
static std::vector<std::string> pTitlevecdefect{"LOT", "Wafer", "Product", "DC Average", "P1 padlife"};
void readMonitorTitle(const std::vector<std::string> &pTitlevec)
{
    for (const auto &elem : pTitlevec)
    {
        if (elem == *pTitlevec.cbegin())
        {
            std::cout << elem;
        }
        else
        {
            std::cout << "\t" << elem;
        }
    }
    std::cout << '\n';
    std::cout << "=================================================================" << '\n';
}
void writeFile(std::ofstream &ofstream, std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> &mergedData3)
{
    ofstream << "LOT,WAFER,PROCWSS,PRODUCT,ROUTENAME,PROCESS_PU,Inline_TK_Average,Inline_Range,Inline_TK_STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,HEAD_UNIT,HEAD_RPM,Innertube,Membrane,RetRing,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME1,EP_TIME2,EP_TIME3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Headusage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3,Moveout_Time\n";
    for (const auto &tuple : mergedData3)
    {
        const InlineTR &a = std::get<0>(tuple);
        const DataEntryEQ &b = std::get<1>(tuple);
        const Eqlot &c = std::get<2>(tuple);
        writeInlineToStream3(ofstream, a);
        writeCMPEQToStream(ofstream, b);
        int unit = b.getHeadUnit();
        writeEqlotToStream(ofstream, c, unit);
        ofstream << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getInlineTK_Calculate_vec()[0][0] << "\t\t|" << c.getPlaten1UsingTime(1) << '\n';
    }
    ofstream.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "TK_EQ_ALL.csv has been created successfully!" << std::endl;
}
void writeFile1(std::ofstream &omegaFile, std::vector<std::tuple<WAT, DataEntryEQ, InlineTR, Eqlot>> &mergedData)
{
    omegaFile << "LOT,WAFER,PRODUCT,WIP_MVIN_TIME,WIP_PU,ROUTENAME,STEPNAME,PARAMETER,SPEC_CLOW,SPEC_TARGET,SPEC_HIGH,AVERAGE,T_VALUE,B_VALUE,C_VALUE,R_VALUE,L_VALUE,WAT_STDEV,HEAD_UNIT,HEAD_RPM,Innertube,Membrane,RetRing,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME1,EP_TIME2,EP_TIME3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Inline_TK_Average,Inline_Range,Inline_TK_STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,Headusage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3,Moveout_Time\n";
    for (const auto &tuple : mergedData)
    {
        const WAT &a = std::get<0>(tuple);
        const DataEntryEQ &b = std::get<1>(tuple);
        const InlineTR &c = std::get<2>(tuple);
        const Eqlot &d = std::get<3>(tuple);
        writeWATToStream(omegaFile, a);
        writeCMPEQToStream(omegaFile, b);
        writeInlineToStream(omegaFile, c);
        int unit = b.getHeadUnit();
        writeEqlotToStream(omegaFile, d, unit);
        omegaFile << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getAverage() << "\t\t|" << c.getInlineTK_Calculate_vec()[0][0] << '\n';
    }
    omegaFile.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "WAT_TK_EQ_ALL.csv has been created successfully!" << std::endl;
}
void writeFile6(std::ofstream &omegaFile, std::vector<std::tuple<Defect, DataEntryEQ, Eqlot>> &mergedData)
{
    omegaFile << "LOT,WAFER,PRODUCT,WIP_MVIN_TIME,WIP_PU,ROUTENAME,STEPNAME,DEFECT_COUNT,SPEC_CLOW,SPEC_HIGH,HEAD_UNIT,HEAD_RPM_P1,Innertube_P1,Membrane_P1,RetRing_P1,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME_1,EP_TIME_2,EP_TIME_3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Head_Usage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3,Move_Out_Time\n";
    for (const auto &tuple : mergedData)
    {
        const Defect &a = std::get<0>(tuple);
        const DataEntryEQ &b = std::get<1>(tuple);
        const Eqlot &c = std::get<2>(tuple);
        // const Eqlot &d = std::get<3>(tuple);
        writeBasicToStream(omegaFile, a);
        writeCMPEQToStream(omegaFile, b);
        int unit = b.getHeadUnit();
        writeEqlotToStream(omegaFile, c, unit);
        omegaFile << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getdefect() << "\t\t|" << c.getEPTime1(1) << '\n';
    }
    omegaFile.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "Defect_EQ_ALL.csv has been created successfully!" << std::endl;
}
void writeFile7(std::ofstream &omegaFile, std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> &mergedData)
{
    omegaFile << "LOT,WAFER,PRODUCT,PROCESS,WIP_MVOUT_TIME,WIP_PU,ROUTENAME,RECIPE,Average,Range,STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,SPEC_CLOW,SPEC_HIGH,SPEC_TARGET,HEAD_UNIT,HEAD_RPM_P1,Innertube_P1,Membrane_P1,RetRing_P1,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME_1,EP_TIME_2,EP_TIME_3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Head_Usage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3,Move_Out_Time\n";
    for (const auto &tuple : mergedData)
    {
        const InlineTR &a = std::get<0>(tuple);
        const DataEntryEQ &b = std::get<1>(tuple);
        const Eqlot &c = std::get<2>(tuple);
        // const Eqlot &d = std::get<3>(tuple);
        writeBasicToStream(omegaFile, a);
        writeCMPEQToStream(omegaFile, b);
        int unit = b.getHeadUnit();
        writeEqlotToStream(omegaFile, c, unit);
        omegaFile << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getInlineTK_Calculate_vec()[0][0] << "\t\t|" << c.getEPTime1(1) << '\n';
    }
    omegaFile.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "Defect_EQ_ALL.csv has been created successfully!" << std::endl;
}
void writeFile8(std::ofstream &omegaFile, std::vector<std::tuple<WAT, InlineTR, DataEntryEQ, Eqlot>> &mergedData)
{
    omegaFile << "LOT,WAFER,PRODUCT,WIP_MVIN_TIME,WIP_PU,ROUTENAME,STEPNAME,PARAMETER,SPEC_CLOW,SPEC_TARGET,SPEC_HIGH,AVERAGE,T_VALUE,B_VALUE,C_VALUE,R_VALUE,L_VALUE,WAT_STDEV,Average,Range,STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,SPEC_CLOW,SPEC_HIGH,SPEC_TARGET,Head_Unit,HEAD_RPM,Innertube,Membrane,RetRing,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME1,EP_TIME2,EP_TIME3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Headusage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3,Moveout_Time\n";
    for (const auto &tuple : mergedData)
    {
        const WAT &a = std::get<0>(tuple);
        const InlineTR &b = std::get<1>(tuple);
        const DataEntryEQ &c = std::get<2>(tuple);
        const Eqlot &d = std::get<3>(tuple);
        // const Eqlot &d = std::get<3>(tuple);
        writeWATToStream(omegaFile, a);
        writeInlineToStream(omegaFile, b);
        writeCMPEQToStream(omegaFile, c);
        int unit = c.getHeadUnit();
        writeEqlotToStream(omegaFile, d, unit);
        omegaFile << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getAverage() << "\t|" << '\n';
    }
    omegaFile.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "WAT_TK_EQ_ALL.csv has been created successfully!" << std::endl;
}
template <typename T>
std::vector<T> readCSV(const std::string &filePath, std::unordered_map<std::string, T> &entryMap, const int &i)
{
    std::ifstream file(filePath);
    // std::vector<T> entryvec = readFileResult<T>(file, filePath);
    std::vector<T> entryvec = readFileResult<T>(file, filePath);
    std::string line;
    std::getline(file, line); // this is a title
    std::unordered_map<std::string, int> titleMap;
    std::istringstream iss(line);
    std::string token;
    int idCounter = 0;
    std::vector<int> counVector;
    std::string repeatStartTitle;
    while (std::getline(iss, token, ','))
    {
        handleString(token);
        readHeader_Count_Reapeat(counVector, repeatStartTitle, titleMap, token, idCounter);
    }
    std::string fileTypeTest = judgeDatafiletype(titleMap);
    setCaseType(fileTypeTest, true);
    std::cout << '\n';
    std::cout << "The file name : " << filePath << "\twhich is the title of " << fileTypeTest << '\n'; // debug
    std::cout << '\n';
    std::vector<std::pair<std::string, int>> theFileCurrentvec;
    defineColumnMap(theFileCurrentvec, fileTypeTest, counVector, repeatStartTitle, titleMap);
    // std::cout << "size of pushing vector (containing repeated) is\t " << theFileCurrentvec.size() << '\n';
    handle_sort_remove_unique(theFileCurrentvec);
    std::cout << "Handling the title (sorting and removing)" << '\n';
    // for (const auto elem : theFileCurrentvec)
    // {
    //     std::cout << elem.first << " at the " << elem.second << std::endl;
    // }
    // std::cout << '\n';
    // std::cout << "the current valid handle column are:" << '\n';
    // std::cout << '\n';
    // std::cout << "Start to handle value row:" << '\n';
    // std::cout << '\n';
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string cell;
        std::vector<std::string> row;
        std::vector<std::string> reductin_row;
        std::vector<std::pair<std::string, int>> titleTest(theFileCurrentvec);
        unsigned j = 0;
        unsigned k = 0;
        while (std::getline(ss, cell, ','))
        {
            handleString(cell);
            if (k == j)
            {
                // std::cout << "Row data column now:\t" << k << " = " << titleTest.begin()->second << " template "
                // << "so the result match! (" << titleTest.begin()->first << ")" << '\n';
                // std::cout << titleTest.begin()->first << " value is : " << cell << '\n';
                reductin_row.push_back(cell);
                titleTest.erase(titleTest.begin());
                j = titleTest.begin()->second;
                k++;
            }
            else
            {
                k++;
            }
            row.push_back(cell);
        }
        // if (row != reductin_row)
        // {
        //     std::cout << "row is\t" << '\n';
        //     for (const auto &elem : row)
        //     {
        //         std::cout << elem << ",";
        //     }
        //     std::cout << '\n';
        //     // std::cout << "rowtest is\t" << '\n';
        //     // for (const auto &elem : reductin_row)
        //     // {
        //     //     std::cout << elem << ",";
        //     // }
        //     // std::cout << '\n';
        // }
        // std::cout << "Size of rowtest" << rowtest.size() << '\n';
        // std::cout << "result of rowtest" << '\n';
        // for (auto elem : rowtest)
        // {
        //     std::cout << elem << ',';
        // }
        // std::cout << '\n';
        if (!UEDA_MaP[fileTypeTest].empty()) // if defect file exist
        {
            T entry(row, UEDA_MaP[fileTypeTest], theFileCurrentvec);
            //(row, watch defect count, filfile current temp;)
            std::string hashkey = entry.getKeyDE(i); // get the key
            auto it = entryMap.find(hashkey);        // if the dataexist , update it;
            if (it != entryMap.end())
            {
                // std::cout << hashkey << "\t"
                //           << "Updating\t" << fileTypeTest << "in the file\t" << filePath << "\twatch column : " << UEDA_MaP[fileTypeTest] << '\n';
                it->second.setFileData(row, UEDA_MaP[fileTypeTest], theFileCurrentvec);
            }
            else
            {
                entryMap[hashkey] = entry;
            }
            entryvec.push_back(entry);
        }
    }
    file.close();
    return entryvec;
}
#endif