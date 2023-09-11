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
#include "mountain.h"
#include "country.h"
#include "wat.h"
#include "lookup.h"
#include <utility>
#include "Eigen/Dense"
#include "reg.h"
int main()
{ //

    Eigen::VectorXd vec3(5);
    vec3 << 1, 2, 3, 4, 5;
    Eigen::VectorXd vec4(5);
    vec4 << 2, 4, 6, 8, 10;
    double regression_coefficient = calculateRegressionCoefficient(vec3, vec4);
    std::cout << "Regression Coefficient: " << regression_coefficient << std::endl;
    Eigen::MatrixXd m(2, 2);
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1);
    std::cout << m << std::endl;
    std::vector<double> vec1{1, 2, 3, 4, 5};
    std::vector<double> vec2{2, 4, 6, 8, 10};
    double res = calculateRegressionCoefficient(vec1, vec2);
    std::cout << "The answer is " << res << std::endl;
    std::string filePath = "/Users/kuochangjung/C++/UMCREADDMM/beta.csv";
    std::string filePathEQ = "/Users/kuochangjung/C++/UMCREADDMM/beta1.csv";
    std::unordered_map<std::string, DataEntry> dataEntryMap;
    std::vector<DataEntry> dataEntries = readCSV<DataEntry>(filePath, dataEntryMap);
    std::unordered_map<std::string, WAT> watMap;
    std::vector<WAT> dataEntriesWAT = readCSV<WAT>(filePath, watMap);
    std::unordered_map<std::string, DataEntryEQ> dataEQMap;
    std::vector<DataEntryEQ> dataEntriesEQ = CMPreadCSV<DataEntryEQ>(filePathEQ, dataEQMap);
    std::vector<std::tuple<DataEntry, WAT, DataEntryEQ>> mergedData = lookup(dataEntryMap, watMap, dataEQMap);
    std::ofstream omegaFile("/Users/kuochangjung/C++/UMCREADDMM/omega.csv");
    if (!omegaFile.is_open())
    {
        std::cout << "Error opening omega.csv!" << std::endl;
        return 1;
    }
    omegaFile << "LOT,WAFER,PRODUCT,WIPTIME,WIPPU,ROUTENAME,STEPNAME,KEY,PARAMETER,SPECLOW,SPECTARGET,SPECHIGH,AVERAGE,TVALUE,BVALUE,CVALUE,RVALUE,LEFTVALUE,WAT_STDEV,HEADUNIT,HeadRPM,InnerTube,Membrane,RetRing,HeadRPMP2,InnerTubeP2,MembraneP2,RetRingP2,HeadRPMP3,InnerTubeP3,MembraneP3,RetRingP3,EP1,EP2,EP3,CON1_HEAD_PRES,CON1_HEAD_RPM,CON2_HEAD_PRES,CON2_HEAD_RPM,CON3_HEAD_PRES,CON3_HEAD_RPM\n";
    // Print the merged data
    for (const auto &tuple : mergedData)
    {
        const DataEntry &a = std::get<0>(tuple);
        const WAT &b = std::get<1>(tuple);
        const DataEntryEQ &c = std::get<2>(tuple);
        std::cout << "LOT: " << a.getLot() << " Wafer: " << a.getWafer() << " Product: " << a.getProduct() << "WAT: " << b.calculateStandardDeviation() << std::endl;
        writeBasicToStream(omegaFile, a);
        writeWATToStream(omegaFile, b);
        writeCMPEQToStream(omegaFile, c);
        omegaFile << '\n';
    }
    std::cout << std::endl;
    omegaFile.close();
    std::cout << "omega.csv has been created successfully!" << std::endl;
    return 0;
}