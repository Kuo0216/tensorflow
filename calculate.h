#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
template <typename T>
void calculateMeanAndStdDev(std::vector<T> &group, std::vector<T> &excludeValues, double &mean, double &stddev);
template <typename T>
void calculateMeanAndStdDev(std::vector<T> &group, std::vector<T> &excludeValues, double &mean, double &stddev)
{
    // Create a filtered vector that excludes specified values
    std::vector<T> filteredGroup;
    for (T x : group)
    {
        if (std::find(excludeValues.begin(), excludeValues.end(), x) == excludeValues.end())
        {
            filteredGroup.push_back(x);
        }
    }
    // Calculate the mean (average) of the filtered group
    double sum = std::accumulate(filteredGroup.begin(), filteredGroup.end(), 0.0);
    mean = sum / filteredGroup.size();
    // Calculate the variance and standard deviation of the filtered group
    double variance = 0.0;
    for (T x : filteredGroup)
    {
        variance += (x - mean) * (x - mean);
    }
    stddev = std::sqrt(variance / filteredGroup.size());
}
#endif