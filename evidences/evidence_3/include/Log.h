#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <iostream>

class MonthConverter {
public:
    static std::string convertToNumber(const std::string month) {
        static const std::unordered_map<std::string, std::string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, 
            {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, 
            {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, 
            {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}
        };
        auto it = monthMap.find(month);
        if (it != monthMap.end()) {
            return it->second;
        }
        return "00";
    }
};

class Log {
private:
    std::string month;
    std::string day;
    std::string year;
    std::string time;
    std::string ip;
    std::string message;
    std::string key;

public:
    Log(
        const std::string &month,
        const std::string &day,
        const std::string &year,
        const std::string &time,
        const std::string &ip,
        const std::string &message) : month(month), day(day), year(year), time(time), ip(ip), message(message) {
        this->key = year + MonthConverter::convertToNumber(month) + day + time + ip;
    }

    bool operator<(const Log &log) const {
        return this->key > log.key; 
    }

    const std::string &getMonth() const { return month; }
    const std::string &getDay() const { return day; }
    const std::string &getYear() const { return year; }
    const std::string &getTime() const { return time; }
    const std::string &getIP() const { return ip; }
    const std::string &getMessage() const { return message; }
    const std::string &getKey() const { return key; }
};

class BSTNode {
public:
    std::string ip;
    int count;
    BSTNode* left;
    BSTNode* right;

    BSTNode(const std::string& ip) : ip(ip), count(1), left(nullptr), right(nullptr) {}
};

class BST {
public:
    BSTNode* root;

    BST() : root(nullptr) {}

    void insert(const std::string& ip) {
        root = insert(root, ip);
    }

    int search(const std::string& ip) const {
        return search(root, ip);
    }

private:
    BSTNode* insert(BSTNode* node, const std::string& ip) {
        if (node == nullptr) {
            return new BSTNode(ip);
        }
        if (ip == node->ip) {
            node->count++;
        } else if (ip < node->ip) {
            node->left = insert(node->left, ip);
        } else {
            node->right = insert(node->right, ip);
        }
        return node;
    }

    int search(const BSTNode* node, const std::string& ip) const {
        if (node == nullptr) {
            return 0;
        }
        if (ip == node->ip) {
            return node->count;
        } else if (ip < node->ip) {
            return search(node->left, ip);
        } else {
            return search(node->right, ip);
        }
    }
};


class LogHandler {
public:
    static std::vector<Log> readLogsFromFile(const std::string &filename) {
        std::vector<Log> logs;
        std::ifstream logFile(filename);
        if (!logFile.is_open()) {
            std::cerr << "Error: Could not open file for reading." << std::endl;
            return logs;
        }
        std::string line;
        while (std::getline(logFile, line)) {
            std::stringstream ss(line);
            std::string month, day, year, time, ip, message;
            ss >> month >> day >> year >> time >> ip;
            std::getline(ss, message);
            logs.emplace_back(month, day, year, time, ip, message);
        }
        logFile.close();
        return logs;
    }

    static void writeLogsToFile(const std::vector<Log>& logs, const std::string& filename) {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open file for writing." << std::endl;
            return;
        }

        for (const Log& log : logs) {
            outputFile << log.getMonth() << " " << log.getDay() << " " << log.getYear() << " "
                       << log.getTime() << " " << log.getIP() << " " << log.getMessage() << std::endl;
        }

        outputFile.close();
    }

    static void sortLogsByMaxHeap(const std::vector<Log>& logs, const std::string& outputFilename) {
        std::priority_queue<Log> maxHeap(logs.begin(), logs.end());

        std::vector<Log> sortedLogs;
        while (!maxHeap.empty()) {
            sortedLogs.push_back(maxHeap.top());
            maxHeap.pop();
        }

        writeLogsToFile(sortedLogs, outputFilename);
    }

    static void sortLogsByMinHeap(const std::vector<Log>& logs, const std::string& outputFilename) {
        auto compare = [](const Log& a, const Log& b) { return a.getKey() > b.getKey(); };
        std::priority_queue<Log, std::vector<Log>, decltype(compare)> minHeap(compare, logs);

        std::vector<Log> sortedLogs;
        while (!minHeap.empty()) {
            sortedLogs.push_back(minHeap.top());
            minHeap.pop();
        }

        writeLogsToFile(sortedLogs, outputFilename);
    }

    static void buildIPBST(const std::vector<Log>& logs, BST& bst) {
        for (const auto& log : logs) {
            bst.insert(log.getIP());
        }
    }

    static void searchIPInBST(const BST& bst) {
        std::string ip;
        std::cout << "Enter IP to search: ";
        std::cin >> ip;
        int count = bst.search(ip);
        if (count > 0) {
            std::cout << "IP " << ip << " found " << count << " times in the log file." << std::endl;
        } else {
            std::cout << "IP " << ip << " not found in the log file." << std::endl;
        }
    }
};