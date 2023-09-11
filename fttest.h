
#ifndef FTTEST_H
#define FTTEST_H
#include <iostream>
#include "Eigen/Dense"
#include <cmath>
#include <tuple>
#include <vector>
double calculateTTestPValue(const std::vector<double> &groupA, const std::vector<double> &groupB)
{
    // Convert std::vector to Eigen vector
    Eigen::VectorXd eigenGroupA(groupA.size());
    Eigen::VectorXd eigenGroupB(groupB.size());

    for (int i = 0; i < groupA.size(); ++i)
    {
        eigenGroupA(i) = groupA[i];
    }

    for (int i = 0; i < groupB.size(); ++i)
    {
        eigenGroupB(i) = groupB[i];
    }

    // Calculate means and variances using Eigen
    double meanA = eigenGroupA.mean();
    double meanB = eigenGroupB.mean();
    double varianceA = (eigenGroupA.array() - meanA).square().sum() / (eigenGroupA.size() - 1);
    double varianceB = (eigenGroupB.array() - meanB).square().sum() / (eigenGroupB.size() - 1);

    // Calculate the pooled variance for the T-test
    double pooledVariance = ((eigenGroupA.size() - 1) * varianceA + (eigenGroupB.size() - 1) * varianceB) / (eigenGroupA.size() + eigenGroupB.size() - 2);

    // Calculate the T-statistic
    double tStatistic = (meanA - meanB) / (std::sqrt(pooledVariance) * std::sqrt(1.0 / eigenGroupA.size() + 1.0 / eigenGroupB.size()));

    // Calculate degrees of freedom
    int degreesOfFreedom = eigenGroupA.size() + eigenGroupB.size() - 2;

    // Calculate the p-value for the T-test using the CDF of the Student's t-distribution
    double pValue = 2.0 * (1.0 - 0.5 * (1.0 + std::erf(tStatistic / std::sqrt(2.0))));

    return pValue;
}
double calculateFTestPValue(const std::vector<double> &groupA, const std::vector<double> &groupB)
{
    // Convert std::vector to Eigen vector
    Eigen::VectorXd eigenGroupA(groupA.size());
    Eigen::VectorXd eigenGroupB(groupB.size());

    for (int i = 0; i < groupA.size(); ++i)
    {
        eigenGroupA(i) = groupA[i];
    }

    for (int i = 0; i < groupB.size(); ++i)
    {
        eigenGroupB(i) = groupB[i];
    }

    // Calculate variances using Eigen
    double varianceA = (eigenGroupA.array() - eigenGroupA.mean()).square().sum() / (eigenGroupA.size() - 1);
    double varianceB = (eigenGroupB.array() - eigenGroupB.mean()).square().sum() / (eigenGroupB.size() - 1);

    // Calculate the F-statistic
    double fStatistic = varianceA / varianceB;

    // Calculate degrees of freedom
    int degreesOfFreedomA = eigenGroupA.size() - 1;
    int degreesOfFreedomB = eigenGroupB.size() - 1;

    // Calculate the p-value for the F-test
    double pValue = 1.0 - std::fmin(std::abs(degreesOfFreedomA - degreesOfFreedomB), std::abs(degreesOfFreedomB - degreesOfFreedomA));

    return pValue;
}

std::tuple<double, int, double> twoSampleTTest(const Eigen::VectorXd &groupA, const Eigen::VectorXd &groupB)
{
    // Calculate means and variances using Eigen
    double meanA = groupA.mean();
    double meanB = groupB.mean();
    double varianceA = (groupA.array() - meanA).square().sum() / (groupA.size() - 1);
    double varianceB = (groupB.array() - meanB).square().sum() / (groupB.size() - 1);

    // Calculate the pooled variance for the T-test
    double pooledVariance = ((groupA.size() - 1) * varianceA + (groupB.size() - 1) * varianceB) / (groupA.size() + groupB.size() - 2);

    // Calculate the T-statistic
    double tStatistic = (meanA - meanB) / (std::sqrt(pooledVariance) * std::sqrt(1.0 / groupA.size() + 1.0 / groupB.size()));

    // Calculate the degrees of freedom
    int degreesOfFreedom = groupA.size() + groupB.size() - 2;

    // Calculate the p-value for the T-test using the CDF of the Student's t-distribution
    double pValue = 2.0 * (1.0 - 0.5 * (1.0 + std::erf(tStatistic / std::sqrt(2.0))));

    return std::make_tuple(tStatistic, degreesOfFreedom, pValue);
}
double twoSampleFTest(const Eigen::VectorXd &groupA, const Eigen::VectorXd &groupB)
{
    // Calculate variances using Eigen
    double varianceA = (groupA.array() - groupA.mean()).square().sum() / (groupA.size() - 1);
    double varianceB = (groupB.array() - groupB.mean()).square().sum() / (groupB.size() - 1);

    // Calculate the F-statistic
    double fStatistic = varianceA / varianceB;

    // Calculate degrees of freedom
    int degreesOfFreedomA = groupA.size() - 1;
    int degreesOfFreedomB = groupB.size() - 1;

    // Calculate the p-value for the F-test
    double pValue = 1.0 - std::fmin(std::abs(degreesOfFreedomA - degreesOfFreedomB), std::abs(degreesOfFreedomB - degreesOfFreedomA));

    return pValue;
}
void test()
{
    Eigen::VectorXd groupA(3);
    Eigen::VectorXd groupB(3);

    groupA << 1, 3.58, 1.56;
    groupB << 2.76, 2.5, 2;

    // Perform the F-test and get the p-value
    double pValue = twoSampleFTest(groupA, groupB);

    std::cout << "F-test p-Value: " << pValue << std::endl;
}

void testft()
{
    // Sample data for two groups
    Eigen::VectorXd groupA(4);
    Eigen::VectorXd groupB(4);

    groupA << 1.2, 2.3, 3.4, 4.5;
    groupB << 5.6, 6.7, 7.8, 8.9;

    // Perform the T-test and get results as a tuple
    auto result = twoSampleTTest(groupA, groupB);

    std::cout << "T-statistic: " << std::get<0>(result) << std::endl;
    std::cout << "Degrees of Freedom: " << std::get<1>(result) << std::endl;
    std::cout << "p-Value: " << std::get<2>(result) << std::endl;
}
#endif