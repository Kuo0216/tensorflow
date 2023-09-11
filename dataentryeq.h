#ifndef DATAENTRYEQ_H
#define DATAENTRYEQ_H
#include <string>
#include <vector>
class DataEntryEQ
{
private:
    std::string keyDE;
    std::vector<std::vector<double>> headRPMvec;       // 3set cuz 3 platen;by4
    std::vector<std::vector<double>> innerTubePresvec; // 3set cuz 3 platen;by4
    std::vector<std::vector<double>> membranePresvec;  // 3set cuz 3 platen;by4
    std::vector<std::vector<double>> retaRingPresvec;  // 3set cuz 3 platen;by4
    std::vector<double> conHeadPresvec;                // 3set cuz 3 platen         // 21
    std::vector<double> conHeadRpmvec;                 // 3set cuz 3 platen
    std::vector<double> epTimevec;
    std::string keyRoute; // 3set cuz 3 platen
public:
    std::string lot;             // 0
    std::string wafer;           // 1
    double lotJobSequence;       // 2
    double chamber;              // 3
    std::string recipeStep;      // 4
    std::string product;         // 5
    std::string process;         // 6
    std::string puType;          // 7
    std::string routeName;       // 8
    std::string stepName;        // 9
    std::string processUnit;     // 10
    std::string puFamily;        // 11
    std::string area;            // 12
    std::string recipe1;         // 13
    std::string recipe2;         // 14
    std::string moveInTime;      // 15
    std::string moveOutTime;     // 16
    double moveInWaferCount;     // 17
    double moveOutWaferCount;    // 18
    double moveInOperator;       // 19
    std::string moveOutOperator; // 20

    double diffMaxMin;  // 24
    double head1Rpm;    // 28
    double head2Rpm;    // 29
    double head3Rpm;    // 30
    double head4Rpm;    // 31
    double patenRpm;    // 40
    double slurry1Flow; // 45

    int headUnit;
    DataEntryEQ() {}
    DataEntryEQ(const std::vector<std::string> &row);
    DataEntryEQ &setPlaten(const std::vector<std::string> &, const int &);
    double getEpTime(const int &platen) const;
    double getConHeadPres(const int &platen) const;
    double getConHeadRpmvec(const int &platen) const;
    std::vector<std::vector<double>> getHeadRPMvec() const;
    std::vector<std::vector<double>> getInnerTubePresvec() const;
    std::vector<std::vector<double>> getMembranePresvec() const;
    std::vector<std::vector<double>> getRetaRingPresvec() const;
    double getCMPeqp(const int &platen, const std::vector<std::vector<double>> &eqvec) const;

    std::string getKeyDE() const;
    friend void writeCMPEQToStream(std::ofstream &os, const DataEntryEQ &a);
    std::string getKeyRoute() const;
};
#endif // DATAENTRYEQ_H
