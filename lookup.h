#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>
template <typename AType, typename BType, typename CType>
std::vector<std::tuple<AType, BType, CType>> lookup(
    const std::unordered_map<std::string, AType> &aMap,
    const std::unordered_map<std::string, BType> &bMap,
    const std::unordered_map<std::string, CType> &cMap)
{
    std::vector<std::tuple<AType, BType, CType>> myMergeVec;
    for (const auto &pair : aMap)
    {
        const std::string &key = pair.first;
        // Check if the key exists in bMap and cMap
        if (bMap.find(key) != bMap.end() && cMap.find(key) != cMap.end())
        {
            // Create a tuple (A, B, C) and add it to myMergeVec
            myMergeVec.emplace_back(pair.second, bMap.at(key), cMap.at(key));
        }
    }
    return myMergeVec;
}