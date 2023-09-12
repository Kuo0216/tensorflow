#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "dataentry.h"
#include "dataentryeq.h"
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include "datacheck.h"
#include "readcsv.h"
#include "wat.h"
#include "lookup.h"
#include <utility>
#include "inlinetr.h"
// #include "fttest.h"
#include "runsheet.h"
#include "defect.h"
#include "eqlot.h"
int main()
{
    // std::vector<double> groupA = {11.2, 12.5, 14.3, 13.7, 12.8, b13.9, 11.7, 12.3, 12.6, 13.0};
    // std::vector<double> groupB = {10.5, 10.8, 11.2, 11.0, 11.6, 10.9, 11.3, 11.7, 10.8, 11.5};
    // // Calculate the F-test p-value
    // double pValue = calculateFTestPValue(groupA, groupB);
    // double p1Value = calculateTTestPValue(groupA, groupB);
    // std::cout << "F-test p-Value: " << pValue << std::endl;
    // std::cout << "T-test p-Value: " << p1Value << std::endl;
    //  std::string filePath = "WAT.csv";
    // std::string filePathEQ = "EQWAFERCMP.csv";
    // std::string filePathInline = "INLINE.csv";
    // std::string filePathRunsheet = "RUNSHEET.csv";
    // std::string filePathDefect = "DEFECT.csv";
    // std::string filePathEQLOT = "EQLOTCMP.csv";
    std::string filePath = "/Users/kuochangjung/C++/UMCREADDMM/WAT.csv";
    std::string filePathEQ = "/Users/kuochangjung/C++/UMCREADDMM/EQWAFERCMP.csv";
    std::string filePathInline = "/Users/kuochangjung/C++/UMCREADDMM/INLINE.csv";
    std::string filePathRunsheet = "/Users/kuochangjung/C++/UMCREADDMM/RUNSHEET.csv";
    std::string filePathDefect = "/Users/kuochangjung/C++/UMCREADDMM/DEFECT.csv";
    std::string filePathEQLOT = "/Users/kuochangjung/C++/UMCREADDMM/EQLOTCMP.csv";
    std::unordered_map<std::string, WAT> watMap;
    std::vector<WAT> dataEntriesWAT = readCSV<WAT>(filePath, watMap);
    std::unordered_map<std::string, DataEntryEQ> dataEQMap;
    std::vector<DataEntryEQ> dataEntriesEQ = readCSV<DataEntryEQ>(filePathEQ, dataEQMap);
    std::unordered_map<std::string, InlineTR> inlineMap;
    std::vector<InlineTR> dataEntriesInline = readCSV<InlineTR>(filePathInline, inlineMap);
    std::unordered_map<std::string, Eqlot> dataEQLOTtMap;
    std::vector<Eqlot> dataEntriesEQLOT = readCSV<Eqlot>(filePathEQLOT, dataEQLOTtMap);
    std::unordered_map<std::string, Runsheet> dataRunsheetMap;
    std::vector<Runsheet> dataEntriesRunsheet = readCSV<Runsheet>(filePathRunsheet, dataRunsheetMap);
    std::unordered_map<std::string, Defect> dataDefectMap;
    std::vector<Defect> dataEntriesDefect = readCSV<Defect>(filePathDefect, dataDefectMap);
    std::vector<std::tuple<WAT, DataEntryEQ, InlineTR, Eqlot>> mergedData = lookup(watMap, dataEQMap, inlineMap, dataEQLOTtMap);
    std::ofstream omegaFile("/Users/kuochangjung/C++/UMCREADDMM/WAT_TK_EQ_ALL.csv");
    checkfile1(omegaFile);
    readMonitorTitle(pTitlevecwat);
    writeFile1(omegaFile, mergedData);
    std::cout << '\n';
    std::cout << "=================\tsecond file\t=====================" << std::endl;
    std::cout << '\n';
    std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> mergedData3 = lookup(inlineMap, dataEQMap, dataEQLOTtMap);
    std::ofstream omegaFile5("/Users/kuochangjung/C++/UMCREADDMM/TK_EQ_ALL.csv");
    checkfile1(omegaFile5);
    readMonitorTitle(pTitlevecinline);
    writeFile(omegaFile5, mergedData3);
    std::vector<std::tuple<Defect, DataEntryEQ, Eqlot>> mergedData4 = lookup(dataDefectMap, dataEQMap, dataEQLOTtMap);
    return 0;
}