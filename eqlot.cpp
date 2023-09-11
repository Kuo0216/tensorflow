#include "dataentry.h"
#include "dataentryeq.h"
#include "datacheck.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include "eqlot.h"

Eqlot::Eqlot(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest) : moveInWaferCount(0.0), moveOutWaferCount(0.0),
                                                                                                                                      diffMaxMin(0.0), head1Usage(0.0), head2Usage(0.0), head3Usage(0.0), head4Usage(0.0),
                                                                                                                                      pat1UsingTime(0.0), polishTime1(0.0),
                                                                                                                                      headUnit(0), headUsageAndTimevec(2, std::vector<double>(4, 0.0)), polishTimevec(3, 0.0), platvec(2, std::vector<double>(3, 0.0))
{
    lot = row[findValue(titleTest, "LOT")];
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
    moveInTime = row[findValue(titleTest, "MOVE_IN_TIME")];
    moveOutTime = row[findValue(titleTest, "MOVE_OUT_TIME")];
    run = row[findValue(titleTest, "RUN")];
    moveInWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_IN_WAFER_COUNT")]);   // 17
    moveOutWaferCount = convertAndHandle<double>(row[findValue(titleTest, "MOVE_OUT_WAFER_COUNT")]); // 18
    diffMaxMin = convertAndHandle<double>(row[findValue(titleTest, "Diff_MaxMin")]);
    head1Usage = convertAndHandle<double>(row[findValue(titleTest, "HEAD1USAGE")]); // 28
    head1usintime = convertAndHandle<double>(row[findValue(titleTest, "HEAD1USINTIME")]);
    head2Usage = convertAndHandle<double>(row[findValue(titleTest, "HEAD2USAGE")]);
    head2usintime = convertAndHandle<double>(row[findValue(titleTest, "HEAD2USINTIME")]);
    head3Usage = convertAndHandle<double>(row[findValue(titleTest, "HEAD3USAGE")]);
    head3usintime = convertAndHandle<double>(row[findValue(titleTest, "HEAD3USINTIME")]);
    head4Usage = convertAndHandle<double>(row[findValue(titleTest, "HEAD4USAGE")]);
    head4usintime = convertAndHandle<double>(row[findValue(titleTest, "HEAD4USINTIME")]);
    headUsageAndTimevec[0][0] = convertAndHandle<double>(row[findValue(titleTest, "HEAD1USINTIME")]);
    headUsageAndTimevec[1][0] = head1Usage;
    headUsageAndTimevec[0][1] = convertAndHandle<double>(row[findValue(titleTest, "HEAD2USINTIME")]);
    headUsageAndTimevec[1][1] = head2Usage;
    headUsageAndTimevec[0][2] = convertAndHandle<double>(row[findValue(titleTest, "HEAD3USINTIME")]);
    headUsageAndTimevec[1][2] = head3Usage;
    headUsageAndTimevec[0][3] = convertAndHandle<double>(row[findValue(titleTest, "HEAD4USINTIME")]);
    headUsageAndTimevec[1][3] = head4Usage;
    pat1UsingTime = convertAndHandle<double>(row[findValue(titleTest, "PLAT1USINTIME")]); // 40
    plat1usage = convertAndHandle<double>(row[findValue(titleTest, "PLAT1USAGE")]);
    pat2UsingTime = convertAndHandle<double>(row[findValue(titleTest, "PLAT2USINTIME")]); // 40
    plat2usage = convertAndHandle<double>(row[findValue(titleTest, "PLAT2USAGE")]);
    pat3UsingTime = convertAndHandle<double>(row[findValue(titleTest, "PLAT3USINTIME")]); // 40
    plat3usage = convertAndHandle<double>(row[findValue(titleTest, "PLAT3USAGE")]);
    condition1usingtime = convertAndHandle<double>(row[findValue(titleTest, "PADCOND1USAGE")]);
    condition2usingtime = convertAndHandle<double>(row[findValue(titleTest, "PADCOND2USAGE")]);
    condition3usingtime = convertAndHandle<double>(row[findValue(titleTest, "PADCOND3USAGE")]);
    platvec[0][0] = plat1usage;
    platvec[0][1] = plat2usage;
    platvec[0][2] = plat3usage;
    platvec[1][0] = pat1UsingTime;
    platvec[1][1] = pat2UsingTime;
    platvec[1][2] = pat3UsingTime;
    polishTime1 = convertAndHandle<double>(row[findValue(titleTest, "POLISH_TIME1")]);
    polishTime2 = convertAndHandle<double>(row[findValue(titleTest, "POLISH_TIME2")]);
    polishTime3 = convertAndHandle<double>(row[findValue(titleTest, "POLISH_TIME3")]);
    polishTimevec[0] = polishTime1;
    polishTimevec[1] = polishTime2;
    polishTimevec[2] = polishTime3;
    maxtime = convertAndHandle<double>(row[findValue(titleTest, "maxtime")]);
    mintime = convertAndHandle<double>(row[findValue(titleTest, "mintime")]);
    keyde = lot + routeName;
}
void Eqlot::setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest)
{
    std::string ch{focusitem};
    std::string chNostring = row[findValue(titleTest, focusitem)];
    if (chNostring == "0")
    {
        headstatus = row[findValue(titleTest, "HEADSTATUS")];
        polishTime1 = convertAndHandle<double>(row[findValue(titleTest, "POLISH_TIME1")]);
        polishTime2 = convertAndHandle<double>(row[findValue(titleTest, "POLISH_TIME2")]);
    }
}

size_t DataEntry::size() const
{
    return 45;
}

std::string Eqlot::getKeyDE() const
{
    return keyde;
}
double Eqlot::getEpTime(const int &platen) const
{
    double result = 0.0;
    int k = unitmapValue(platen);
    return polishTimevec[0];
}
std::string Eqlot::getKeyRoute() const
{
    return keyRoute;
}
double Eqlot::getSlurryFlow() const
{
    return polishTime1;
}
std::string Eqlot::getMoveOutTime() const
{
    return moveOutTime;
}
std::string Eqlot::getKeyEQ_Route_PU_MoveOut() const
{
    return lot.substr(0, 5) + routeName + processUnit + moveOutTime;
}
double Eqlot::getHeadUsage(const int &unit) const
{
    switch (unit)
    {
    case 1:
        return head1Usage;
        break;
    case 2:
        return head2Usage;
        break;
    case 3:
        return head3Usage;
        break;
    case 4:
        return head4Usage;
        break;
    default:
        break;
    }
    return -1;
}
double Eqlot::getCondUsingTime(const int &platen) const
{
    switch (platen)
    {
    case 1:
        return condition1usingtime;
        break;
    case 2:
        return condition2usingtime;
        break;
    case 3:
        return condition3usingtime;
        break;
    default:
        break;
    }
    return -1;
}
double Eqlot::getEPTime1(const int &platen) const
{
    switch (platen)
    {
    case 1:
        return polishTime1;
        break;
    case 2:
        return polishTime2;
        break;
    case 3:
        return polishTime3;
        break;
    default:
        break;
    }
    return -1;
}
double Eqlot::getPlaten1Usage(const int &platen) const
{
    switch (platen)
    {
    case 1:
        return plat1usage;
        break;
    case 2:
        return plat2usage;
        break;
    case 3:
        return plat3usage;
        break;
    default:
        break;
    }
    return -1;
}
double Eqlot::getPlaten1UsingTime(const int &platen) const
{
    switch (platen)
    {
    case 1:
        return pat1UsingTime;
        break;
    case 2:
        return pat2UsingTime;
        break;
    case 3:
        return pat3UsingTime;
        break;
    default:
        break;
    }
    return -1;
}
void writeEqlotToStream(std::ofstream &os, const Eqlot &e, const int &unit)
{
    os << e.getHeadUsage(unit) << ","
       << e.getPlaten1UsingTime(1) << ","
       << e.getPlaten1UsingTime(2) << ","
       << e.getPlaten1UsingTime(3) << ","
       << e.getCondUsingTime(1) << ","
       << e.getCondUsingTime(2) << ","
       << e.getCondUsingTime(3) << ",";
}