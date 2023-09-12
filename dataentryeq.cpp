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
                                                                                                                                                  headUnit(0), headRPMvec(3, std::vector<double>(4, 0.0)), innerTubePresvec(3, std::vector<double>(4, 0.0)), membranePresvec(3, std::vector<double>(4, 0.0)), retaRingPresvec(3, std::vector<double>(4, 0.0)), conHeadPresvec(3, 0.0), conHeadRpmvec(3, 0.0), epTimevec(3, 0.0)
{
    lot = row[findValue(titleTest, "LOT")];
    wafer = row[findValue(titleTest, "WAFER")];
    lotJobSequence = row[findValue(titleTest, "LOTJOBSEQUENCE")];
    chamber = row[findValue(titleTest, "CHAMBER")];
    recipeStep = row[findValue(titleTest, "RECIPE_STEP")];
    product = row[findValue(titleTest, "PRODUCT")];
    process = row[findValue(titleTest, "PROCESS")];
    puType = row[findValue(titleTest, "PUTYPE")];
    routeName = row[findValue(titleTest, "ROUTENAME")];
    stepName = row[findValue(titleTest, "STEPNAME")];
    processUnit = row[findValue(titleTest, "PROCESSINGUNIT")];
    puFamily = row[findValue(titleTest, "PUFAMILY")];
    area = row[findValue(titleTest, "AREA")];
    recipe1 = row[findValue(titleTest, "RECIPE1")];
    recipe2 = row[findValue(titleTest, "RECIPE2")];
    moveInTime = row[findValue(titleTest, "MOVE_IN_TIME")];
    moveOutTime = row[findValue(titleTest, "MOVE_OUT_TIME")];
    moveInWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_IN_WAFER_COUNT")], row); // 17
    moveOutWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_OUT_WAFER_COUNT")]);    // 18
    moveInOperator = convertAndHandle<double>(row[findValue(titleTest, "MOVE_IN_OPERATOR")]);           // 19                                                     // 20
    moveOutOperator = row[findValue(titleTest, "MOVE_OUT_OPERATOR")];
    diffMaxMin = convertAndHandle<double>(row[findValue(titleTest, "Diff_MaxMin")]);
    head1Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM")]); // 28
    head2Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD2_RPM")]);
    head3Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD3_RPM")]);
    head4Rpm = convertAndHandle<double>(row[findValue(titleTest, "HEAD4_RPM")]);
    patenRpm = convertAndHandle<double>(row[findValue(titleTest, "PLATEN_RPM")]); // 40
    slurry1Flow = convertAndHandle<double>(row[findValue(titleTest, "SLURRY1_FLOW")]);
    keyDE = lot + wafer + routeName + recipe1;
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
    setFileDataInit(row, focusitem, titleTest); // INIT
}
int DataEntryEQ::getHeadUnit() const
{
    return headUnit;
}
void DataEntryEQ::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    std::string ch{focusitem};
    std::string chNostring = row[findValue(titleTest, focusitem)];
    int chNO, unitNo;
    chNO = convertAndHandle<int>(chNostring);
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
        unitNo = 0;
    }
    int i = unitmapValue(chNO), j = unitmapValue(unitNo);
    headRPMvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM") + j]);
    innerTubePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "INNERTUBE1_PRES") + j]); // 3set cuz 3 platen;by4
    membranePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "MEMBRANE1_PRES") + j]);   // 3set cuz 3 platen;by4
    retaRingPresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "RETA_RING1_PRES") + j]);  // 3set cuz 3 platen;by4
    conHeadPresvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);            // 3set cuz 3 platen         // 21
    conHeadRpmvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);             // 3set cuz 3 platen
    epTimevec[i] = convertAndHandle<double>(row[findValue(titleTest, "EP_TIME_1") + i]);
    keyRoute = processUnit + routeName;
}
void DataEntryEQ::setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    std::string ch{focusitem};
    std::unordered_map<std::string, int> chMap{
        {"1", 0}, {"2", 1}, {"3", 2}};
    int i = chMap[chamber], j = unitmapValue(headUnit);
    headRPMvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "HEAD1_RPM") + j]);
    innerTubePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "INNERTUBE1_PRES") + j]); // 3set cuz 3 platen;by4
    membranePresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "MEMBRANE1_PRES") + j]);   // 3set cuz 3 platen;by4
    retaRingPresvec[i][j] = convertAndHandle<double>(row[findValue(titleTest, "RETA_RING1_PRES") + j]);  // 3set cuz 3 platen;by4
    conHeadPresvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);            // 3set cuz 3 platen         // 21
    conHeadRpmvec[i] = convertAndHandle<double>(row[findValue(titleTest, "CON_HEAD_PRES")]);             // 3set cuz 3 platen
    epTimevec[i] = convertAndHandle<double>(row[findValue(titleTest, "EP_TIME_1") + i]);
    keyRoute = processUnit + routeName;
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
    return keyDE;
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
std::string DataEntryEQ::getKeyRoute() const
{
    return keyRoute;
}
double DataEntryEQ::getSlurryFlow() const
{
    return slurry1Flow;
}
std::string DataEntryEQ::getMoveOutTime() const
{
    return moveOutTime;
}
std::string DataEntryEQ::getKeyEQ_Route_PU_MoveOut() const
{
    return lot.substr(0, 5) + processUnit + routeName + moveOutTime;
}