#ifndef EQLOT_H
#define EQLOT_H
#include <string>
#include <vector>
class Eqlot
{
private:
    // std::string keyde;
    std::vector<std::vector<double>> headUsageAndTimevec; // 3set cuz 3 platen;by4
    std::vector<double> polishTimevec;                    // 3set cuz 3 platen;by4
    std::vector<std::vector<double>> platvec;             // 3set cuz 3 platen;by4
    std::string keyRoute;                                 // 3set cuz 3 platen
    std::string lot;                                      // 0
    std::string lotJobSequence;                           // 2
    std::string chamber;                                  // 3
    std::string recipeStep;                               // 4
    std::string product;                                  // 5
    std::string process;                                  // 6
    std::string puType;                                   // 7
    std::string route;
    std::string routeName; // 8
    std::string step;
    std::string stepName;    // 9
    std::string processUnit; // 10
    std::string puFamily;    // 11
    std::string boatposition;
    std::string area;        // 12
    std::string recipe1;     // 13
    std::string moveInTime;  // 15
    std::string moveOutTime; // 16
    std::string run;

    double moveInWaferCount;  // 17
    double moveOutWaferCount; // 18
    std::string isrework;
    std::string iscustomized;
    double diffMaxMin; // 24
    double head1Usage; // 28
    double head1usintime;
    double head2Usage; // 29
    double head2usintime;
    double head3Usage; // 30
    double head3usintime;
    double head4Usage; // 31
    double head4usintime;
    std::string headstatus;
    double plat1usage;
    double pat1UsingTime; // 40
    double plat2usage;
    double pat2UsingTime; // 40
    double plat3usage;
    double pat3UsingTime; // 40Odouble pat1UsingTime; // 40O
    double condition1usingtime;
    double condition2usingtime;
    double condition3usingtime;
    double polishTime1; // 45
    double polishTime2; // 45
    double polishTime3; // 45
    double maxtime;
    double mintime;
    int headUnit = 0;

public:
    Eqlot() {}
    Eqlot(const std::vector<std::string> &row);
    Eqlot(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileData(const std::vector<std::string> &, const int &);
    void setFileData(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    void setFileDataInit(const std::vector<std::string> &row, const std::string &focusitem, std::vector<std::pair<std::string, int>> titleTest);
    double getEpTime(const int &platen) const;
    double getConHeadPres(const int &platen) const;
    double getConHeadRpmvec(const int &platen) const;
    double getHeadUsage(const int &unit) const;
    double getCondUsingTime(const int &platen) const;
    double getEPTime1(const int &platen) const;
    double getPlaten1Usage(const int &platen) const;
    double getPlaten1UsingTime(const int &platen) const;
    // double getCMPeqp(const int &platen, const std::vector<std::vector<double>> &eqvec) const;
    double getSlurryFlow() const;
    // std::string getKeyEQ_Route_PU_MoveOut() const;
    std::string getKeyDE() const;
    std::string getKeyDE(const int &i) const;
    // std::string getKeyRoute() const;
    std::string getMoveOutTime() const;
    friend void writeCMPEQToStream(std::ofstream &os, const Eqlot &a);
    friend void writeEqlotToStream(std::ofstream &os, const Eqlot &e, const int &unit);
};
#endif // DATAENTRYEQ_H