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
#include "fttest.h"
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
    // std::vector<std::tuple<WAT, DataEntryEQ, InlineTR, Eqlot>> mergedData0 = lookup(watMap, dataEQMap, inlineMap, dataEQLOTtMap);
    // std::vector<std::tuple<DataEntry, WAT, DataEntryEQ, InlineTR, Eqlot>> mergedData1 = lookup(dataEntryMap, watMap, dataEQMap, inlineMap, dataEQLOTtMap);
    std::ofstream omegaFile("/Users/kuochangjung/C++/UMCREADDMM/WAT_TK_EQ_ALL.csv");
    if (!omegaFile.is_open())
    {
        std::cout << "Error opening omega.csv!" << std::endl;
    }
    std::cout << "LOT: "
              << "\tWafer: "
              << "\tProduct: "
              << "\tWAT Average "
              << "\tInline_TK_Average " << '\n';
    std::cout << "=================================================================" << '\n';
    omegaFile << "LOT,WAFER,PRODUCT,WIP_MVIN_TIME,WIP_PU,ROUTENAME,STEPNAME,PARAMETER,SPEC_CLOW,SPEC_TARGET,SPEC_HIGH,AVERAGE,T_VALUE,B_VALUE,C_VALUE,R_VALUE,L_VALUE,WAT_STDEV,HEAD_UNIT,HEAD_RPM,Innertube,Membrane,RetRing,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME1,EP_TIME2,EP_TIME3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Inline_TK_Average,Inline_Range,Inline_TK_STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,Headusage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3\n";
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
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "=================\tsecond file\t=====================" << std::endl;
    std::vector<std::tuple<InlineTR, DataEntryEQ, Eqlot>> mergedData3 = lookup(inlineMap, dataEQMap, dataEQLOTtMap);
    std::ofstream omegaFile5("/Users/kuochangjung/C++/UMCREADDMM/TK_EQ_ALL.csv");
    if (!omegaFile5.is_open())
    {
        std::cout << "Error opening omega.csv!" << std::endl;
    }
    std::cout << "LOT: "
              << "\tWafer: "
              << "\tProduct: "
              << "\tTK Average "
              << "\tP1 padlife " << '\n';
    std::cout << "=================================================================" << '\n';
    omegaFile5 << "LOT,WAFER,PROCWSS,PRODUCT,ROUTENAME,PROCESS_PU,Inline_TK_Average,Inline_Range,Inline_TK_STDEV,M1,M2,M3,M4,M5,M6,M7,M8,M9,HEAD_UNIT,HEAD_RPM,Innertube,Membrane,RetRing,Head_RPM_P2,Innertube_P2,Membrane_P2,Retring_P2,HEAD_RPM_P3,Innertube_P3,Membrane_P3,Retring_P3,EP_TIME1,EP_TIME2,EP_TIME3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM,Slurry1Flow,Headusage,Pad1_life,Pad2_life,Pad3_life,Condition_1,Condition_2,Condition_3\n";
    for (const auto &tuple : mergedData3)
    {
        const InlineTR &a = std::get<0>(tuple);
        const DataEntryEQ &b = std::get<1>(tuple);
        const Eqlot &c = std::get<2>(tuple);
        writeInlineToStream3(omegaFile5, a);
        writeCMPEQToStream(omegaFile5, b);
        int unit = b.getHeadUnit();
        writeEqlotToStream(omegaFile5, c, unit);
        omegaFile5 << '\n';
        std::cout << a.getLot() << "\t|" << a.getWafer() << "\t|" << a.getProduct() << "\t|" << a.getInlineTK_Calculate_vec()[0][0] << "\t\t|" << c.getPlaten1UsingTime(1) << '\n';
    }
    omegaFile5.close();
    std::cout << "=================================================================" << '\n';
    std::cout << "TK_EQ_ALL.csv has been created successfully!" << std::endl;

    std::vector<std::tuple<Defect, DataEntryEQ, Eqlot>> mergedData4 = lookup(dataDefectMap, dataEQMap, dataEQLOTtMap);
    return 0;
}