// include/EuropeCities.h
#ifndef EUROPECITIES_H
#define EUROPECITIES_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

class CityInfo {
public:
    std::string origin;
    std::string destination;
    std::string trainTime;
    int trainDistance;
    std::string carTime;
    int carDistance;

    CityInfo(const std::string& origin, const std::string& destination, const std::string& trainTime,
             int trainDistance, const std::string& carTime, int carDistance);
};

class EuropeCities {
private:
    std::vector<CityInfo> cityData;
    std::unordered_set<std::string> citySet;
    std::vector<std::string> cityList;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjListTrain;
    std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> adjListCar;
    void dfsUtil(const std::string& city, std::unordered_set<std::string>& visited, std::ofstream& outFile) const;
    std::vector<std::string> dijkstra(const std::string& startCity, const std::string& endCity, const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& adjList) const;
public:
    void readCSV(const std::string& filename);
    void identifyCities();
    void createGraph();
    void printCities() const;
    void saveCitiesToFile(const std::string& filename) const;
    void printAdjList() const;
    void saveAdjListToFile(const std::string& filename) const;
    const std::vector<CityInfo>& getCityData() const;
    const std::unordered_set<std::string>& getCitySet() const;
    const std::vector<std::string>& getCityList() const;
    void bfs(const std::string& startCity, const std::string& filename) const;
    void dfs(const std::string& startCity, const std::string& filename) const;
    void findShortestPath(const std::string& startCity, const std::string& endCity) const;
};

#endif