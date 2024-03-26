#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

class MonthConverter{
public:
    static std::string convertToNumber(const std::string month){
        static const std::unordered_map<std::string, std::string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, 
            {"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, 
            {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, 
            {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        auto it = monthMap.find(month);
        if (it != monthMap.end()){
            return it->second;
        }
        return "00";
    }
};

class Log{
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
        const std::string &message) : month(month), day(day), year(year), time(time), ip(ip), message(message){
        this->key = year + MonthConverter::convertToNumber(month) + day + time;
    }

    bool operator<(const Log &log) const{
        return this->key < log.key;
    }
    const std::string &getMonth() const { return month; }
    const std::string &getDay() const { return day; }
    const std::string &getYear() const { return year; }
    const std::string &getTime() const { return time; }
    const std::string &getIP() const { return ip; }
    const std::string &getMessage() const { return message; }
    const std::string &getKey() const { return key; }
};

class LogHandler{
public:
    static std::vector<Log> readLogsFromFile(const std::string &filename){
        std::vector<Log> logs;
        std::ifstream logFile(filename);
        if (!logFile.is_open()){
            return logs;
        }
        std::string line;
        while (std::getline(logFile, line)){
            std::stringstream ss(line);
            std::string month, day, year, time, ip, message;
            ss >> month >> day >> year >> time >> ip;
            std::getline(ss, message);
            logs.emplace_back(month, day, year, time, ip, message);
        }
        logFile.close();
        return logs;
    }
    static void sortByDateTime(std::vector<Log>& logs) {
        for (size_t i = 1; i < logs.size(); ++i) {
            Log key = logs[i];
            int j = i - 1;
            while (j >= 0 && logs[j].getKey() > key.getKey()) {
                logs[j + 1] = logs[j];
                j = j - 1;
            }
            logs[j + 1] = key;
        }
    }
    static std::vector<Log> searchByDateTimeRange(
        const std::vector<Log>& logs, 
        const std::string& startDateTime, 
        const std::string& endDateTime) {
        std::vector<Log> result;

        int low = 0, high = logs.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (logs[mid].getKey() < startDateTime)
                low = mid + 1;
            else
                high = mid - 1;
        }
        int startIndex = low;

        low = 0, high = logs.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (logs[mid].getKey() <= endDateTime)
                low = mid + 1;
            else
                high = mid - 1;
        }
        int endIndex = high;

        for (int i = startIndex; i <= endIndex; ++i) {
            result.push_back(logs[i]);
        }

        return result;
    }
};
