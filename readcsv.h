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
static std::unordered_map<std::string, std::string> UEDA_MaP = {
    {"WAT", "NA"},
    {"EQ_CMP", "CHAMBER"},
    {"RUNSHEET", "NA"},
    {"EQ_LOT", "RUN"},
    {"DEFECT", "DEFECT_COUNT"},
    {"INLINE", "PARAMETER"}};
static std::vector<std::string> inline_TK_DefaultTile{"LOT", "WAFER", "PRODUCT", "PROCESS", "PROCESS_EQ", "PROCESS_TIME", "MEASURE_EQ", "STEP", "RECIPE", "AVG_VALUE", "DEV", "M1", "M2", "M3", "M4", "M5", "M6", "M7", "M8", "M9", "MAX_VALUE", "MIN_VALUE", "PARAMETER", "RANGE", "REDO_FLAG", "ROUTENAME", "SPEC_LOW", "SPEC_HIGH", "TK_RECIPE", "STEPNAME", "MEASURE_DATE", "MEASURE_TIME", "OPERATOR"};
static std::vector<std::string> cmpwaferDefaultTile{"LOT", "WAFER", "CHAMBER", "PRODUCT", "PROCESS", "ROUTENAME", "STEPNAME", "PROCESSINGUNIT", "RECIPE1", "MOVE_IN_TIME", "MOVE_OUT_TIME", "CON_HEAD_PRES", "CON_HEAD_RPM", "CON_PRES_DELTA", "Diff_MaxMin", "EP_TIME1", "EP_TIME2", "EP_TIME3", "HEAD1_RPM", "HEAD2_RPM", "HEAD3_RPM", "HEAD4_RPM", "INNERTUBE1_PRES", "INNERTUBE2_PRES", "INNERTUBE3_PRES", "INNERTUBE4_PRES", "MEMBRANE1_PRES", "MEMBRANE2_PRES", "MEMBRANE3_PRES", "MEMBRANE4_PRES", "PLATEN_RPM", "RETA_RING1_PRES", "RETA_RING1_PRES", "RETA_RING1_PRES", "RETA_RING1_PRES", "SLURRY1_FLOW", "LOTJOBSEQUENCE", "RECIPE_STEP", "PUTYPE", "PUFAMILY", "AREA", "RECIPE2", "MOVE_IN_WAFER_COUNT", "MOVE_OUT_WAFER_COUNT", "MOVE_IN_OPERATOR", "MOVE_OUT_OPERATOR"};
static std::vector<std::string> runsheetDefaultTile{"LOTSEQUENCE", "ROUTEDES", "ROUTE_SEQUENCE", "STEP_SEQUENCE", "WIP_PUFAMILY", "WIP_RETICLE", "WIP_RECIPE2", "MOVE_OUT_WAFER_COUNT", "WIP_MOIN_OPERATOR", "WIP_MVOUT_OPERATOR", "WIP_AREA", "WIP_BOATPOSITION", "ISCUSTOMIZED", "CURRENTQUANTITY", "STDCYCLETIME", "LOTSTATUS", "STEPTYPE", "ROUTE", "STEP", "VIEW_FLAG", "P_TIME", "Q_TIME", "LOT_TYPE", "CORR_LOT", "PRODUCT", "PROCESS", "LOT", "WIP_PUTYPE", "WIP_PU", "WIP_CHAMBER", "WIP_EQUIPMENT", "WIP_EQCHAMBER", "WIP_RECIPE1", "WIP_MVIN_TIME", "ROUTENAME", "STEPNAME", "WIP_MVOUT_TIME", "MOVE_IN_WAFER_COUNT", "ISREWORK"};
static std::vector<std::string> defectDefaultTile{"DD_STEP", "BAD_DIE", "SPECIFICATION", "DD_ROUTE", "PROCESS_ROUTE", "PROCESS_STEP", "DEFECT_COUNT", "RECIPE", "LOT_TYPE", "CORR_LOT", "PRODUCT", "PROCESS", "LOT", "ORIGINAL_LOT", "PROCESS_DATE", "PROCESS_TIME", "WAFER", "MEASURE_TIME", "MEASURE_DATE", "PROCESS_EQ", "MEASURE_EQ", "SPEC_HIGH", "WEEK", "MONTH", "SPEC_TARGET", "VENDOR_LOT", "OOS_COUNT"};
static std::vector<std::string> eqlotDefaultTile{"LOT", "PROCESS", "PRODUCT", "LOTJOBSEQUENCE", "CHAMBER", "RECIPE_STEP", "PUTYPE", "ROUTE", "STEP", "ROUTENAME", "STEPNAME", "PROCESSINGUNIT", "PUFAMILY", "BOATPOSITION", "AREA", "RECIPE1", "RECIPE2", "RETICLE", "MOVE_IN_TIME", "MOVE_OUT_TIME", "MOVE_IN_OPERATOR", "MOVE_OUT_OPERATOR", "ISREWORK", "ISCUSTOMIZED", "MOVE_IN_WAFER_COUNT", "MOVE_OUT_WAFER_COUNT", "HEADSTATUS", "RUN", "Diff_MaxMin", "HEAD1USAGE", "HEAD1USINTIME", "HEAD2USAGE", "HEAD2USINTIME", "HEAD3USAGE", "HEAD3USINTIME", "HEAD4USAGE", "HEAD4USINTIME", "HEADSTATUS", "PADCOND1USAGE", "PADCOND2USAGE", "PADCOND3USAGE", "PLAT1USAGE", "PLAT1USINTIME", "PLAT2USAGE", "PLAT2USINTIME", "PLAT3USAGE", "PLAT3USINTIME", "POLISH_TIME1", "POLISH_TIME2", "POLISH_TIME3", "maxtime", "mintime"};
static std::vector<std::string> watDefaultTitle{"LOT", "WAFER", "PRODUCT", "PROCESS", "MEASURE_TIME", "AVERAGE", "B_VALUE", "BL_VALUE", "C_VALUE", "L_VALUE", "PARAMETER", "R_VALUE", "WIP_ROUTE", "SPEC_HIGH", "SPEC_LOW", "SPEC_TARGET", "T_VALUE", "TL_VALUE", "TR_VALUE", "WIP_EQUIPMENT", "WIP_MVIN_TIME", "WIP_PU", "WIP_PUTYPE", "WIP_STEP", "WIP_ROUTE", "CORR_LOT", "ROUTENAME", "STEPNAME",
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
        if (row != reductin_row)
        {
            std::cout << "row is\t" << '\n';
            for (const auto &elem : row)
            {
                std::cout << elem << ",";
            }
            std::cout << '\n';
            // std::cout << "rowtest is\t" << '\n';
            // for (const auto &elem : reductin_row)
            // {
            //     std::cout << elem << ",";
            // }
            // std::cout << '\n';
        }
        // std::cout << "Size of rowtest" << rowtest.size() << '\n';
        // std::cout << "result of rowtest" << '\n';
        // for (auto elem : rowtest)
        // {
        //     std::cout << elem << ',';
        // }
        // std::cout << '\n';

        if (!UEDA_MaP[fileTypeTest].empty())
        {
            T entry(row, UEDA_MaP[fileTypeTest], theFileCurrentvec);
            std::string hashkey = entry.getKeyDE();
            auto it = entryMap.find(hashkey);
            if (it != entryMap.end())
            {

                std::cout << hashkey << "\t"
                          << "Updating\t" << fileTypeTest << "in the file\t" << filePath << "\twatch column : " << UEDA_MaP[fileTypeTest] << '\n';
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