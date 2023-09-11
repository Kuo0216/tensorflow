#include "dataentry.h"
#include "dataentryeq.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <stdexcept>
int unitmapValue(int i)
{
    if (i == 1)
        return 0;
    else if (i == 2)
        return 1;
    else if (i == 3)
        return 2;
    else if (i == 4)
        return 3;
    else
        return -1;
}
DataEntryEQ::DataEntryEQ(const std::vector<std::string> &row)
    : lotJobSequence(0.0), chamber(0.0), moveInWaferCount(0.0), moveOutWaferCount(0.0), moveInOperator(0.0),
      diffMaxMin(0.0), head1Rpm(0.0), head2Rpm(0.0), head3Rpm(0.0), head4Rpm(0.0),
      patenRpm(0.0), slurry1Flow(0.0),
      headUnit(0), headRPMvec(3, std::vector<double>(4, 0.0)), innerTubePresvec(3, std::vector<double>(4, 0.0)), membranePresvec(3, std::vector<double>(4, 0.0)), retaRingPresvec(3, std::vector<double>(4, 0.0)), conHeadPresvec(3, 0.0), conHeadRpmvec(3, 0.0), epTimevec(3, 0.0)
{
    checkRowSize(row, 46);
    lot = row[0];
    wafer = row[1];
    lotJobSequence = convertAndHandle<double>(row[2]);
    chamber = convertAndHandle<double>(row[3]);
    recipeStep = row[4];
    product = row[5];
    process = row[6];
    puType = row[7];
    routeName = row[8];
    stepName = row[9];
    processUnit = row[10];
    puFamily = row[11];
    area = row[12];
    recipe1 = row[13];
    recipe2 = row[14];
    moveInTime = row[15];
    moveOutTime = row[16];
    moveInWaferCount = convertAndHandle<double>(row[17]);  // 17
    moveOutWaferCount = convertAndHandle<double>(row[18]); // 18
    moveInOperator = convertAndHandle<double>(row[19]);    // 19                                                     // 20
    moveOutOperator = row[20];
    diffMaxMin = convertAndHandle<double>(row[24]);
    head1Rpm = convertAndHandle<double>(row[28]); // 28
    head2Rpm = convertAndHandle<double>(row[29]);
    head3Rpm = convertAndHandle<double>(row[30]);
    head4Rpm = convertAndHandle<double>(row[31]);
    patenRpm = convertAndHandle<double>(row[40]); // 40
    slurry1Flow = convertAndHandle<double>(row[45]);
    keyDE = lot + wafer;
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
    int i = unitmapValue(chamber), j = unitmapValue(headUnit);
    headRPMvec[i][j] = convertAndHandle<double>(row[28 + j]);
    innerTubePresvec[i][j] = convertAndHandle<double>(row[32 + j]); // 3set cuz 3 platen;by4
    membranePresvec[i][j] = convertAndHandle<double>(row[36 + j]);  // 3set cuz 3 platen;by4
    retaRingPresvec[i][j] = convertAndHandle<double>(row[41 + j]);  // 3set cuz 3 platen;by4
    conHeadPresvec[i] = convertAndHandle<double>(row[21]);          // 3set cuz 3 platen         // 21
    conHeadRpmvec[i] = convertAndHandle<double>(row[22]);           // 3set cuz 3 platen
    epTimevec[i] = convertAndHandle<double>(row[25 + i]);
    keyRoute = lot.substr(0, 5) + wafer + routeName; // 3set cuz 3 platen
}
DataEntryEQ &DataEntryEQ::setPlaten(const std::vector<std::string> &row, const int &i)
{
    int k = unitmapValue(chamber), j = unitmapValue(headUnit);
    if (i == 1)
    {
        conHeadPresvec[0] = convertAndHandle<double>(row[21]); // 21
        conHeadRpmvec[0] = convertAndHandle<double>(row[22]);
        epTimevec[0] = convertAndHandle<double>(row[25]);
        headRPMvec[0][j] = convertAndHandle<double>(row[28 + j]);
        innerTubePresvec[0][j] = convertAndHandle<double>(row[32 + j]); // 3set cuz 3 platen;by4
        membranePresvec[0][j] = convertAndHandle<double>(row[36 + j]);  // 3set cuz 3 platen;by4
        retaRingPresvec[0][j] = convertAndHandle<double>(row[41 + j]);  // 3set cuz 3 platen;by4
        conHeadPresvec[0] = convertAndHandle<double>(row[21]);          // 3set cuz 3 platen         // 21
        conHeadRpmvec[0] = convertAndHandle<double>(row[22]);           // 3set cuz 3 platen
        epTimevec[0] = convertAndHandle<double>(row[25]);               // 3set cuz 3 platen
    }
    else if (i == 2)
    { // 22
        conHeadPresvec[1] = convertAndHandle<double>(row[21]);
        conHeadRpmvec[1] = convertAndHandle<double>(row[22]);
        epTimevec[1] = convertAndHandle<double>(row[26]);
        headRPMvec[1][j] = convertAndHandle<double>(row[28 + j]);
        innerTubePresvec[1][j] = convertAndHandle<double>(row[32 + j]); // 3set cuz 3 platen;by4
        membranePresvec[1][j] = convertAndHandle<double>(row[36 + j]);  // 3set cuz 3 platen;by4
        retaRingPresvec[1][j] = convertAndHandle<double>(row[41 + j]);  // 3set cuz 3 platen;by4
        conHeadPresvec[1] = convertAndHandle<double>(row[21]);          // 3set cuz 3 platen         // 21
        conHeadRpmvec[1] = convertAndHandle<double>(row[22]);           // 3set cuz 3 platen
        epTimevec[1] = convertAndHandle<double>(row[26]);               // 3set cuz 3 platen
    }
    else if (i == 3)
    {
        conHeadPresvec[2] = convertAndHandle<double>(row[21]);
        conHeadRpmvec[2] = convertAndHandle<double>(row[22]);
        epTimevec[2] = convertAndHandle<double>(row[27]);
        headRPMvec[2][j] = convertAndHandle<double>(row[28 + j]);
        innerTubePresvec[2][j] = convertAndHandle<double>(row[32 + j]); // 3set cuz 3 platen;by4
        membranePresvec[2][j] = convertAndHandle<double>(row[36 + j]);  // 3set cuz 3 platen;by4
        retaRingPresvec[2][j] = convertAndHandle<double>(row[41 + j]);  // 3set cuz 3 platen;by4
        conHeadPresvec[2] = convertAndHandle<double>(row[21]);          // 3set cuz 3 platen         // 21
        conHeadRpmvec[2] = convertAndHandle<double>(row[22]);           // 3set cuz 3 platen
        epTimevec[2] = convertAndHandle<double>(row[27]);               // 3set cuz 3 platen
    }
    keyRoute = lot.substr(0, 5) + wafer + routeName;
    return *this;
}
size_t DataEntry::size() const
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
    std::string keyD = lot.substr(0, 5) + wafer;
    return keyD;
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
       << c.getConHeadRpmvec(3) << ",";
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