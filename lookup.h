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
        const std::string &keylotroute = pair.second.getKeyRouteName();
        if (bMap.find(key) != bMap.end() && cMap.find(keylotroute) != cMap.end())
        {
            myMergeVec.emplace_back(pair.second, bMap.at(key), cMap.at(keylotroute));
        }
    }
    return myMergeVec;
}
template <typename AType, typename BType, typename CType, typename DType>
std::vector<std::tuple<AType, BType, CType, DType>> lookup(
    const std::unordered_map<std::string, AType> &aMap,
    const std::unordered_map<std::string, BType> &bMap,
    const std::unordered_map<std::string, CType> &cMap,
    const std::unordered_map<std::string, DType> &dMap)
{
    std::vector<std::tuple<AType, BType, CType, DType>> myMergeVec;
    for (const auto &pair : aMap)
    {
        const std::string &key = pair.second.getkey_Wafer_Routename();
        const std::string &keylotbase = pair.second.getkey_Routename();

        if (bMap.find(key) != bMap.end() && cMap.find(key) != cMap.end() && dMap.find(keylotbase) != dMap.end())
        {
            myMergeVec.emplace_back(pair.second, bMap.at(key), cMap.at(key), dMap.at(keylotbase));
        }
    }
    return myMergeVec;
}

template <typename AType, typename BType, typename CType, typename DType, typename EType>
std::vector<std::tuple<AType, BType, CType, DType, EType>> lookup(
    const std::unordered_map<std::string, AType> &aMap,
    const std::unordered_map<std::string, BType> &bMap,
    const std::unordered_map<std::string, CType> &cMap,
    const std::unordered_map<std::string, DType> &dMap,
    const std::unordered_map<std::string, EType> &eMap)
{
    std::vector<std::tuple<AType, BType, CType, DType, EType>> myMergeVec;
    for (const auto &pair : aMap)
    {
        const std::string &key = pair.first;                                                      // key corrlot+wafer
        const std::string &key_lot_wafer_routename = pair.first + pair.second.getwipRounteName(); // corrlot+wafer+route;
        const std::string &key_lot_routename = key.substr(0, 5) + pair.second.getwipRounteName();
        std::cout << "check" << std::endl;
        if (bMap.find(key) != bMap.end() && cMap.find(key_lot_wafer_routename) != cMap.end() && dMap.find(key_lot_wafer_routename) != dMap.end() && eMap.find(key_lot_routename) != eMap.end())
        {
            myMergeVec.emplace_back(pair.second, bMap.at(key), cMap.at(key_lot_wafer_routename), dMap.at(key_lot_wafer_routename), eMap.at(key_lot_routename));
        }
    }
    return myMergeVec;
}