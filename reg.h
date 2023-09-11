#ifndef REG_H
#define REG_H
// #include "Eigen/Dense"
#include <iostream>
#include <vector>
double calculateRegressionCoefficient(const std::vector<double> &x, const std::vector<double> &y)
{
    // Calculate means of x and y
    double mean_x = 0.0;
    double mean_y = 0.0;

    for (double value : x)
    {
        mean_x += value;
    }
    mean_x /= x.size();

    for (double value : y)
    {
        mean_y += value;
    }
    mean_y /= y.size();

    // Calculate the numerator and denominator
    double numerator = 0.0;
    double denominator = 0.0;

    for (size_t i = 0; i < x.size(); ++i)
    {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator += (x[i] - mean_x) * (x[i] - mean_x);
    }

    // Calculate the regression coefficient
    double regression_coefficient = numerator / denominator;
    return regression_coefficient;
}
// double calculateRegressionCoefficient(const Eigen::VectorXd &x, const Eigen::VectorXd &y)
// {
//     Eigen::Index size = x.size();

//     // Calculate the mean of x and y
//     double mean_x = x.mean();
//     double mean_y = y.mean();

//     // Calculate the numerator and denominator
//     double numerator = ((x.array() - mean_x) * (y.array() - mean_y)).sum();
//     double denominator = ((x.array() - mean_x) * (x.array() - mean_x)).sum();

//     // Calculate the regression coefficient
//     double regression_coefficient = numerator / denominator;
//     return regression_coefficient;
// }
#endif