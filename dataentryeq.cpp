#include "dataentry.h"
#include "dataentryeq.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
DataEntryEQ::DataEntryEQ(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) : moveInWaferCount(0.0), moveOutWaferCount(0.0), moveInOperator(0.0),
                                                                                                                                                  diffMaxMin(0.0), head1Rpm(0.0), head2Rpm(0.0), head3Rpm(0.0), head4Rpm(0.0),
                                                                                                                                                  patenRpm(0.0), slurry1Flow(0.0),
                                                                                                                                                  headUnit(0), headRPMvec(3, std::vector<double>(5, 0.0)), innerTubePresvec(3, std::vector<double>(5, 0.0)), membranePresvec(3, std::vector<double>(5, 0.0)), retaRingPresvec(3, std::vector<double>(5, 0.0)), conHeadPresvec(3, 0.0), conHeadRpmvec(3, 0.0), epTimevec(3, 0.0),
                                                                                                                                                  conPresDeltavec(3, 0.0)
{
    lot = row[findValue(titleTest, "LOT")];                                                                         // 0
    wafer = row[findValue(titleTest, "WAFER")];                                                                     // 1
    lotJobSequence = row[findValue(titleTest, "LOTJOBSEQUENCE")];                                                   // 2
    chamber = row[findValue(titleTest, "CHAMBER")];                                                                 // 3
    recipeStep = row[findValue(titleTest, "RECIPE_STEP")];                                                          // 4
    product = row[findValue(titleTest, "PRODUCT")];                                                                 // 5
    process = row[findValue(titleTest, "PROCESS")];                                                                 // 6
    puType = row[findValue(titleTest, "PUTYPE")];                                                                   // 7
    routeName = row[findValue(titleTest, "ROUTENAME")];                                                             // 8
    stepName = row[findValue(titleTest, "STEPNAME")];                                                               // 9
    processUnit = row[findValue(titleTest, "PROCESSINGUNIT")];                                                      // 10
    puFamily = row[findValue(titleTest, "PUFAMILY")];                                                               // 11
    area = row[findValue(titleTest, "AREA")];                                                                       // 12
    recipe1 = row[findValue(titleTest, "RECIPE1")];                                                                 // 13
    recipe2 = row[findValue(titleTest, "RECIPE2")];                                                                 // 14
    moveInTime = row[findValue(titleTest, "MOVE_IN_TIME")];                                                         // 15
    moveOutTime = row[findValue(titleTest, "MOVE_OUT_TIME")];                                                       // 16
    moveInWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_IN_WAFER_COUNT")], defaultDouble);   // 17
    moveOutWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_OUT_WAFER_COUNT")], defaultDouble); // 18
    moveInOperator = convertAndHandle<double>(row[findValue(titleTest, "MOVE_IN_OPERATOR")], defaultDouble);        // 19                                                     // 20
    moveOutOperator = row[findValue(titleTest, "MOVE_OUT_OPERATOR")];
    diffMaxMin = convertAndHandle<double>(row[findValue(titleTest, "Diff_MaxMin")], -1);
    head1Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM")], 0, row); // 28
    head2Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD2_RPM")], 0, row);
    head3Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD3_RPM")], 0, row);
    head4Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD4_RPM")], 0, row);
    patenRpm = convertAndHandle<double>(row[findValue(titleTest, "PLATEN_RPM")], 0, row); // 40
    slurry1Flow = convertAndHandle<double>(row[findValue(titleTest, "SLURRY1_FLOW")], 0, row);
    // keyDE =
    if (head1Rpm != 0.0)
    {
        headUnit = 1;
    }
    else if (head2Rpm != 0.0)
    {
        headUnit = 2;
    }
    else if (head3Rpm != 0.0)
    {
        headUnit = 3;
    }
    else if (head4Rpm != 0.0)
    {
        headUnit = 4;
    }
    else
    {
        headUnit = 5;
    }
    setFileDataInit(row, focusitem, titleTest); // INIT
}
int DataEntryEQ::getHeadUnit() const
{
    return headUnit;
}
void DataEntryEQ::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    // std::string ch{focusitem};
    std::string chNostring = row[findValue(titleTest, focusitem)];
    int chNO = 0, unitNo = 0;
    chNO = convertAndHandle<int>(chNostring); // if chamber int ==2 or chamber int ==3
    double h1 = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM")]);
    double h2 = convertAndHandle<double>(row[findValue(titleTest, "HEAD2_RPM")]);
    double h3 = convertAndHandle<double>(row[findValue(titleTest, "HEAD3_RPM")]);
    double h4 = convertAndHandle<double>(row[findValue(titleTest, "HEAD4_RPM")]);
    if (h1 != 0)
    {
        unitNo = 1;
    }
    else if (h2 != 0)
    {
        unitNo = 2;
    }
    else if (h3 != 0)
    {
        unitNo = 3;
    }
    else if (h4 != 0)
    {
        unitNo = 4;
    }
    else
    {
        unitNo = 5;
    }
    int i = unitmapValue(chNO), j = unitmapValue(unitNo);
    headRPMvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM") + j]);
    innerTubePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "INNERTUBE1_PRES") + j]); // 3set cuz 3 platen;by4
    membranePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "MEMBRANE1_PRES") + j]);   // 3set cuz 3 platen;by4
    retaRingPresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "RETA_RING1_PRES") + j]);  // 3set cuz 3 platen;by4
    conHeadPresvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);            // 3set cuz 3 platen         // 21
    conHeadRpmvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_RPM")]);
    conPresDeltavec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_PRES_DELTA")]); // 3set cuz 3 platen
    epTimevec[i] = convertAndHandle<double>(row[findValue(titleTest, "EP_TIME_1") + i]);
    // keyRoute = processUnit + routeName;
}
void DataEntryEQ::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{

    // std::string ch{focusitem};
    std::unordered_map<std::string, int> chMap{
        {"1", 0}, {"2", 1}, {"3", 2}};
    int i = chMap[chamber], j = unitmapValue(headUnit);
    headRPMvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM") + j]);
    innerTubePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "INNERTUBE1_PRES") + j]); // 3set cuz 3 platen;by4
    membranePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "MEMBRANE1_PRES") + j]);   // 3set cuz 3 platen;by4
    retaRingPresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "RETA_RING1_PRES") + j]);  // 3set cuz 3 platen;by4
    conHeadPresvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);            // 3set cuz 3 platen         // 21
    conHeadRpmvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_RPM")]);              // 3set cuz 3 platenPM
    conPresDeltavec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_PRES_DELTA")]);
    epTimevec[i] = convertAndHandle<double>(row[findValue(titleTest, "EP_TIME_1") + i]);
    // keyRoute =
} // 3set cuz 3 platen
size_t DataEntryEQ::size() const
{
    return 45;
}
double DataEntryEQ::getCMPeqp(const int &platen, const std::vector<std::vector<double>> &eqvec) const
{
    int k = unitmapValue(platen);
    if (headUnit == 1)
    {
        return eqvec[k][0];
    }
    else if (headUnit == 2)
    {
        return eqvec[k][1];
    }
    else if (headUnit == 3)
    {
        return eqvec[k][2];
    }
    else if (headUnit == 4)
    {
        return eqvec[k][3];
    }
    return 0.0;
}
std::string DataEntryEQ::getKeyDE() const
{
    return lot + wafer + routeName + recipe1;
    ;
}
std::vector<std::vector<double>> DataEntryEQ::getHeadRPMvec() const
{
    return headRPMvec;
}
std::vector<std::vector<double>> DataEntryEQ::getInnerTubePresvec() const
{
    return innerTubePresvec;
}
std::vector<std::vector<double>> DataEntryEQ::getMembranePresvec() const
{
    return membranePresvec;
}
std::vector<std::vector<double>> DataEntryEQ::getRetaRingPresvec() const
{
    return retaRingPresvec;
}
void writeCMPEQToStream(std::ofstream &os, const DataEntryEQ &c)
{
    os << c.headUnit << ","
       << c.getCMPeqp(1, c.getHeadRPMvec()) << ","
       << c.getCMPeqp(1, c.getInnerTubePresvec()) << ","
       << c.getCMPeqp(1, c.getMembranePresvec()) << ","
       << c.getCMPeqp(1, c.getRetaRingPresvec()) << ","
       << c.getCMPeqp(2, c.getHeadRPMvec()) << ","
       << c.getCMPeqp(2, c.getInnerTubePresvec()) << ","
       << c.getCMPeqp(2, c.getMembranePresvec()) << ","
       << c.getCMPeqp(2, c.getRetaRingPresvec()) << ","
       << c.getCMPeqp(3, c.getHeadRPMvec()) << ","
       << c.getCMPeqp(3, c.getInnerTubePresvec()) << ","
       << c.getCMPeqp(3, c.getMembranePresvec()) << ","
       << c.getCMPeqp(3, c.getRetaRingPresvec()) << ","
       << c.getEpTime(1) << ","
       << c.getEpTime(2) << ","
       << c.getEpTime(3) << ","
       << c.getConHeadPres(1) << ","
       << c.getConHeadRpmvec(1) << ","
       << c.getConHeadPres(2) << ","
       << c.getConHeadRpmvec(2) << ","
       << c.getConHeadPres(3) << ","
       << c.getConHeadRpmvec(3) << ","
       << c.getSlurryFlow() << ",";
}
double DataEntryEQ::getEpTime(const int &platen) const
{
    double result = 0.0;
    int k = unitmapValue(platen);
    return epTimevec[k];
}
double DataEntryEQ::getConHeadPres(const int &platen) const
{
    double result = 0.0;
    int k = unitmapValue(platen);
    return conHeadPresvec[k];
}
double DataEntryEQ::getConHeadRpmvec(const int &platen) const
{
    double result = 0.0;
    int k = unitmapValue(platen);
    return conHeadRpmvec[k];
}
// std::string DataEntryEQ::getKeyRoute() const
// {
//     return processUnit + routeName;
//     ;
// }
double DataEntryEQ::getSlurryFlow() const
{
    return slurry1Flow;
}
std::string DataEntryEQ::getMoveOutTime() const
{
    return moveOutTime;
}
std::string DataEntryEQ::getKeyDE(const int &i) const
{
    if (i == 1)
    {
        return lot.substr(0, 5) + wafer + routeName + processUnit;
    }
    else if (i == 2)
    {
        return lot + wafer + routeName + recipe1 + moveOutTime;
    }
    else if (i == 3)
    {
        return lot.substr(0, 5) + wafer + routeName + recipe1;
    }
    else
    {
        return lot + wafer + routeName + recipe1;
    }
}
std::string DataEntryEQ::getLotJobSequence() const
{
    return lotJobSequence;
}