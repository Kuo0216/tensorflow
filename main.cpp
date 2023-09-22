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
#include "Eigen/Dense"
#include "calculate.h"
// #include "reg.h"
#include "gsl/gsl_statistics_double.h"
// #include <stdio.h>
// #include "gsl/gsl_sf_bessel.h"
static std::unordered_map<std::string, std::string> keytypeMap{
    {"DEFECT_ANALYSIS", "DEFECT_KEY"},
    {"TK_ANALYSIS", "TK_KEY"}};
std::vector<double> excludeValues = {0, -1};
template <typename T>
void calculateMeanAndStdDev(std::vector<T> &group, std::vector<T> &excludeValues, double &mean, double &stddev);
int main()
{

    std::vector<double> groupA = {11.2, 0, 0, -1, -1, -1, -1, -1, -1, -0};
    std::vector<double> groupB = {10.5, 10.8, 11.2, 11.0, 11.6, 10.9, 11.3, 11.7, 10.8, 11.5};
    // // Calculate the F-test p-value
    double meanA, stddevA;

    std::cout << "hello" << '\n';
    calculateMeanAndStdDev(groupA, excludeValues, meanA, stddevA);
    std::cout << "Group A: Mean = " << meanA << ", Standard Deviation = " << stddevA << std::endl;
    // Calculate and display statistics for groupB, excluding specified values
    double meanB, stddevB;
    calculateMeanAndStdDev(groupB, excludeValues, meanB, stddevB);
    std::cout << "Group B: Mean = " << meanB << ", Standard Deviation = " << stddevB << std::endl;
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
    // std::unordered_map<std::string, WAT> watMap;
    // std::vector<WAT> dataEntriesWAT = readCSV<WAT>(filePath, watMap);
    // // dataEntriesWAT.clear();
    // // dataEntriesWAT.shrink_to_fit();
    // std::unordered_map<std::string, InlineTR> inlineMap;
    // std::vector<InlineTR> dataEntriesInline = readCSV<InlineTR>(filePathInline, inlineMap);
    // // dataEntriesInline.clear();
    // // dataEntriesInline.shrink_to_fit();
    // std::unordered_map<std::string, DataEntryEQ> dataEQMap;
    // std::vector<DataEntryEQ> dataEntriesEQ = readCSV<DataEntryEQ>(filePathEQ, dataEQMap);
    // // dataEntriesEQ.clear();
    // // dataEntriesEQ.shrink_to_fit();
    // std::unordered_map<std::string, Eqlot> dataEQLOTtMap;
    // std::vector<Eqlot> dataEntriesEQLOT = readCSV<Eqlot>(filePathEQLOT, dataEQLOTtMap);
    // // dataEntriesEQLOT.clear();
    // // dataEntriesEQLOT.shrink_to_fit();
    // std::unordered_map<std::string, Runsheet> dataRunsheetMap;
    // std::vector<Runsheet> dataEntriesRunsheet = readCSV<Runsheet>(filePathRunsheet, dataRunsheetMap);
    // // dataEntriesRunsheet.clear();
    // // dataEntriesRunsheet.shrink_to_fit();
    // std::unordered_map<std::string, Defect> dataDefectMap;
    // std::vector<Defect> dataEntriesDefect = readCSV<Defect>(filePathDefect, dataDefectMap);
    // dataEntriesDefect.clear();
    // dataEntriesDefect.shrink_to_fit();
    // std::vector<std::tuple<WAT, DataEntryEQ, InlineTR, Eqlot>> mergedData = lookup(watMap, dataEQMap, inlineMap, dataEQLOTtMap);
    // std::ofstream omegaFile("/Users/kuochangjung/C++/UMCREADDMM/WAT_TK_EQ_ALL.csv");
    // // std::ofstream omegaFile("WAT_TK_EQ_ALL.csv");
    // checkfile1(omegaFile);
    // readMonitorTitle(pTitlevecwat);
    // writeFile1(omegaFile, mergedData);
    // std::cout << '\n';
    // std::cout << "=================\tsecond file\t=====================" << std::endl;
    // std::cout << '\n';
    // std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> mergedData3 = lookup(inlineMap, dataEQMap, dataEQLOTtMap);
    // std::ofstream omegaFile5("/Users/kuochangjung/C++/UMCREADDMM/TK_EQ_ALL.csv");
    // // std::ofstream omegaFile5("TK_EQ_ALL.csv");
    // checkfile1(omegaFile5);
    // readMonitorTitle(pTitlevecinline);
    // writeFile(omegaFile5, mergedData3);
    // std::vector<std::tuple<Defect, DataEntryEQ, Eqlot>> mergedData4 = lookup(dataDefectMap, dataEQMap, dataEQLOTtMap);
    std::unordered_map<std::string, Defect> dataDefectMaptrace;
    std::vector<Defect> dataEntriesDefect_trace = readCSV<Defect>(filePathDefect, dataDefectMaptrace, 1);
    dataEntriesDefect_trace.clear();
    dataEntriesDefect_trace.shrink_to_fit();
    std::unordered_map<std::string, DataEntryEQ> dataEQMap_D_Trace;
    std::vector<DataEntryEQ> dataEntriesEQ_D_Trace = readCSV<DataEntryEQ>(filePathEQ, dataEQMap_D_Trace, 1);
    dataEntriesEQ_D_Trace.clear();
    dataEntriesEQ_D_Trace.shrink_to_fit();
    std::unordered_map<std::string, Eqlot> dataEQLOTtMaptrace;
    std::vector<Eqlot> dataEntriesEQLOTtrace = readCSV<Eqlot>(filePathEQLOT, dataEQLOTtMaptrace, 1);
    dataEntriesEQLOTtrace.clear();
    dataEntriesEQLOTtrace.shrink_to_fit();
    std::vector<std::tuple<Defect, DataEntryEQ, Eqlot>> merged_Defect_Trace = lookup(dataDefectMaptrace, dataEQMap_D_Trace, dataEQLOTtMaptrace, 1);
    std::ofstream file_D_EQ_ANA("/Users/kuochangjung/C++/UMCREADDMM/Defect_EQ_ALL.csv");
    // std::ofstream file_D_EQ_ANA("Defect_EQ_ALL.csv");
    checkfile1(file_D_EQ_ANA);
    readMonitorTitle(pTitlevecdefect);
    writeFile6(file_D_EQ_ANA, merged_Defect_Trace);
    std::unordered_map<std::string, InlineTR> inlineMaptrace;
    std::vector<InlineTR> dataEntriesInlinetrace = readCSV<InlineTR>(filePathInline, inlineMaptrace, 2);
    dataEntriesInlinetrace.clear();
    dataEntriesInlinetrace.shrink_to_fit();
    std::unordered_map<std::string, DataEntryEQ> dataEQMap_T_Trace;
    std::vector<DataEntryEQ> dataEntriesEQ_T_Trace = readCSV<DataEntryEQ>(filePathEQ, dataEQMap_T_Trace, 2);
    dataEntriesEQ_T_Trace.clear();
    dataEntriesEQ_T_Trace.shrink_to_fit();
    std::unordered_map<std::string, Eqlot> dataEQLOTtMap_T_Trace;
    std::vector<Eqlot> dataEntriesEQLOT_T_Trace = readCSV<Eqlot>(filePathEQLOT, dataEQLOTtMap_T_Trace, 2);
    dataEntriesEQLOT_T_Trace.clear();
    dataEntriesEQLOT_T_Trace.shrink_to_fit();
    std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> mergedData_TK_analysis = lookup(inlineMaptrace, dataEQMap_T_Trace, dataEQLOTtMap_T_Trace, 2);
    std::ofstream file_Inline_TK_EQ_ALL("/Users/kuochangjung/C++/UMCREADDMM/Inline_TK_EQ_ALL.csv");
    // std::ofstream file_Inline_TK_EQ_ALL("Inline_EQ_ALL.csv");
    checkfile1(file_Inline_TK_EQ_ALL);
    readMonitorTitle(pTitlevecdefect);
    writeFile7(file_Inline_TK_EQ_ALL, mergedData_TK_analysis);
    std::unordered_map<std::string, WAT> watMaptest3;
    std::vector<WAT> dataEntriesWATtest3 = readCSV<WAT>(filePath, watMaptest3, 3);
    dataEntriesWATtest3.clear();
    dataEntriesWATtest3.shrink_to_fit();
    std::unordered_map<std::string, InlineTR> inlineMaptest3;
    std::vector<InlineTR> dataEntriesInlinetest3 = readCSV<InlineTR>(filePathInline, inlineMaptest3, 3);
    dataEntriesInlinetest3.clear();
    dataEntriesInlinetest3.shrink_to_fit();
    std::unordered_map<std::string, DataEntryEQ> dataEQMaptest3;
    std::vector<DataEntryEQ> dataEntriesEQtest3 = readCSV<DataEntryEQ>(filePathEQ, dataEQMaptest3, 3);
    dataEntriesEQtest3.clear();
    dataEntriesEQtest3.shrink_to_fit();
    std::unordered_map<std::string, Eqlot> dataEQLOTtMaptest3;
    std::vector<Eqlot> dataEntriesEQLOTtest3 = readCSV<Eqlot>(filePathEQLOT, dataEQLOTtMaptest3, 3);
    dataEntriesEQLOTtest3.clear();
    dataEntriesEQLOTtest3.shrink_to_fit();
    std::vector<std::tuple<WAT, InlineTR, DataEntryEQ, Eqlot>> mergedData8 = lookup(watMaptest3, inlineMaptest3, dataEQMaptest3, dataEQLOTtMaptest3, 3);
    for (auto &elem : mergedData8)
    {
        if (std::get<0>(elem).getWafer() == "3")
        {
            std::get<0>(elem).setEXP();
            std::cout << "setting ok" << '\n';
        }
        std::cout << std::get<0>(elem).getLot() << '\n';
    }
    std::ofstream omegaFile8("/Users/kuochangjung/C++/UMCREADDMM/WATNEW_TK_EQ_ALL.csv");
    // std::ofstream omegaFile8("WATNEW_TK_EQ_ALL.csv");
    checkfile1(omegaFile8);
    readMonitorTitle(pTitlevecdefect);
    writeFile8(omegaFile8, mergedData8);
    return 0;
}