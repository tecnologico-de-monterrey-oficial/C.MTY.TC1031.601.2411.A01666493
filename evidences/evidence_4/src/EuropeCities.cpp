// src/EuropeCities.cpp
#include "EuropeCities.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <limits>

CityInfo::CityInfo(const std::string& origin, const std::string& destination, const std::string& trainTime,
                   int trainDistance, const std::string& carTime, int carDistance)
    : origin(origin), destination(destination), trainTime(trainTime),
      trainDistance(trainDistance), carTime(carTime), carDistance(carDistance) {}

void EuropeCities::readCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the header

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string origin, destination, trainTime, carTime, trainDistance, carDistance;

        std::getline(ss, origin, ',');
        std::getline(ss, destination, ',');
        std::getline(ss, trainTime, ',');
        std::getline(ss, trainDistance, ',');
        std::getline(ss, carTime, ',');
        std::getline(ss, carDistance, ',');

        int trainDist = std::stoi(trainDistance);
        int carDist = std::stoi(carDistance);

        cityData.emplace_back(origin, destination, trainTime, trainDist, carTime, carDist);
        citySet.insert(origin);
        citySet.insert(destination);
    }

    file.close();
    identifyCities();
    createGraph();
}

void EuropeCities::identifyCities() {
    cityList.assign(citySet.begin(), citySet.end());
    std::sort(cityList.begin(), cityList.end());
}

void EuropeCities::createGraph() {
    for (const auto& info : cityData) {
        adjListTrain[info.origin].emplace_back(info.destination, info.trainDistance);
        adjListCar[info.origin].emplace_back(info.destination, info.carDistance);
    }
}

void EuropeCities::printCities() const {
    for (const auto& city : cityList) {
        std::cout << city << std::endl;
    }
}

void EuropeCities::saveCitiesToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    for (const auto& city : cityList) {
        outFile << city << std::endl;
    }

    outFile.close();
}

void EuropeCities::printAdjList() const {
    std::cout << "Train Adjacency List:" << std::endl;
    for (const auto& pair : adjListTrain) {
        std::cout << pair.first << ": ";
        for (const auto& dest : pair.second) {
            std::cout << "(" << dest.first << ", " << dest.second << " km) ";
        }
        std::cout << std::endl;
    }
    std::cout << "Car Adjacency List:" << std::endl;
    for (const auto& pair : adjListCar) {
        std::cout << pair.first << ": ";
        for (const auto& dest : pair.second) {
            std::cout << "(" << dest.first << ", " << dest.second << " km) ";
        }
        std::cout << std::endl;
    }
}

void EuropeCities::saveAdjListToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outFile << "Train Adjacency List:" << std::endl;
    for (const auto& pair : adjListTrain) {
        outFile << pair.first << ": ";
        for (const auto& dest : pair.second) {
            outFile << "(" << dest.first << ", " << dest.second << " km) ";
        }
        outFile << std::endl;
    }
    outFile << "Car Adjacency List:" << std::endl;
    for (const auto& pair : adjListCar) {
        outFile << pair.first << ": ";
        for (const auto& dest : pair.second) {
            outFile << "(" << dest.first << ", " << dest.second << " km) ";
        }
        outFile << std::endl;
    }

    outFile.close();
}

const std::vector<CityInfo>& EuropeCities::getCityData() const {
    return cityData;
}

const std::unordered_set<std::string>& EuropeCities::getCitySet() const {
    return citySet;
}

const std::vector<std::string>& EuropeCities::getCityList() const {
    return cityList;
}


void EuropeCities::bfs(const std::string& startCity, const std::string& filename) const {
    if (citySet.find(startCity) == citySet.end()) {
        std::cerr << "City not found in the graph." << std::endl;
        return;
    }

    std::unordered_set<std::string> visited;
    std::queue<std::string> q;
    std::ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    q.push(startCity);
    visited.insert(startCity);
    outFile << "BFS Traversal from " << startCity << ":\n";

    while (!q.empty()) {
        std::string city = q.front();
        q.pop();
        outFile << city << " ";

        for (const auto& neighbor : adjListTrain.at(city)) {
            if (visited.find(neighbor.first) == visited.end()) {
                q.push(neighbor.first);
                visited.insert(neighbor.first);
            }
        }
    }

    outFile << std::endl;
    outFile.close();
}

void EuropeCities::dfs(const std::string& startCity, const std::string& filename) const {
    if (citySet.find(startCity) == citySet.end()) {
        std::cerr << "City not found in the graph." << std::endl;
        return;
    }

    std::unordered_set<std::string> visited;
    std::ofstream outFile(filename);
    
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
        return;
    }

    outFile << "DFS Traversal from " << startCity << ":\n";
    dfsUtil(startCity, visited, outFile);
    outFile << std::endl;
    outFile.close();
}

void EuropeCities::dfsUtil(const std::string& city, std::unordered_set<std::string>& visited, std::ofstream& outFile) const {
    visited.insert(city);
    outFile << city << " ";

    for (const auto& neighbor : adjListTrain.at(city)) {
        if (visited.find(neighbor.first) == visited.end()) {
            dfsUtil(neighbor.first, visited, outFile);
        }
    }
}

#include <queue>
#include <unordered_map>
#include <limits>

std::vector<std::string> EuropeCities::dijkstra(const std::string& startCity, const std::string& endCity, const std::unordered_map<std::string, std::vector<std::pair<std::string, int>>>& adjList) const {
    std::unordered_map<std::string, int> distances;
    std::unordered_map<std::string, std::string> previous;
    typedef std::pair<int, std::string> Pair;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;

    for (const auto& city : citySet) {
        distances[city] = std::numeric_limits<int>::max();
    }
    distances[startCity] = 0;
    pq.push(std::make_pair(0, startCity));

    while (!pq.empty()) {
        Pair top = pq.top();
        pq.pop();
        int currentDistance = top.first;
        std::string currentCity = top.second;

        if (currentCity == endCity) {
            break;
        }

        for (const auto& neighborPair : adjList.at(currentCity)) {
            std::string neighbor = neighborPair.first;
            int weight = neighborPair.second;
            int newDistance = currentDistance + weight;
            if (newDistance < distances[neighbor]) {
                distances[neighbor] = newDistance;
                previous[neighbor] = currentCity;
                pq.push(std::make_pair(newDistance, neighbor));
            }
        }
    }

    std::vector<std::string> path;
    for (std::string at = endCity; at != startCity; at = previous[at]) {
        path.push_back(at);
    }
    path.push_back(startCity);
    std::reverse(path.begin(), path.end());
    return path;
}

void EuropeCities::findShortestPath(const std::string& startCity, const std::string& endCity) const {
    if (citySet.find(startCity) == citySet.end() || citySet.find(endCity) == citySet.end()) {
        std::cerr << "One or both cities not found in the graph." << std::endl;
        return;
    }

    std::vector<std::string> trainPath = dijkstra(startCity, endCity, adjListTrain);
    std::vector<std::string> carPath = dijkstra(startCity, endCity, adjListCar);

    std::cout << "Shortest path by train from " << startCity << " to " << endCity << ":\n";
    for (const auto& city : trainPath) {
        std::cout << city << " ";
    }
    std::cout << "\n";

    std::cout << "Shortest path by car from " << startCity << " to " << endCity << ":\n";
    for (const auto& city : carPath) {
        std::cout << city << " ";
    }
    std::cout << "\n";
}
