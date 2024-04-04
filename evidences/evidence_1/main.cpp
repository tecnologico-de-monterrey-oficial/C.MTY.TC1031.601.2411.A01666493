#include <iostream>
#include <vector>
#include "include/Log.h"

void displayHelp() {
    std::cout << R"(
_   _  ____  _   _ ____  _     ____  _____ ____  
| | | |/ ___|| | | | __ )| |   |  _ \| ____|  _ \ 
| |_| | |    | | | |  _ \| |   | | | |  _| | | | |
|  _  | |___ | |_| | |_) | |___| |_| | |___| |_| |
|_| |_|\____| \___/|____/|_____|____/|_____|____/ 

========================================================================
Evidencia 1 - Actividad Integral de Algoritmos Fundamentales - v1.0.0
========================================================================

Welcome to the Log Analyzer!
Usage: g++ -o build/main main.cpp -std=c++11 && ./build/main

Jesus Raul Jimenez Perez - A01666493

Options:
-h, --help         Show help message and exit.
-s, --sort         Sort logs by date and time.
-f, --find         Find logs in a date range.
-d, --display      Display logs in a date range.
-w, --write        Write logs to file.
        )" << std::endl;
}

void sortLogsAndWriteToFile(const std::string& inputFilename, const std::string& outputFilename) {
    std::vector<Log> logs = LogHandler::readLogsFromFile(inputFilename);
    LogHandler::sortByDateTime(logs);
    LogHandler::writeLogsToFile(logs, outputFilename);
    std::cout << "Logs have been sorted and stored in '" << outputFilename << "'." << std::endl;
}

void findAndWriteLogsToFile(const std::string& inputFilename, const std::string& outputFilename, const std::string& startDate, const std::string& endDate) {
    std::vector<Log> logs = LogHandler::readLogsFromFile(inputFilename);
    LogHandler::sortByDateTime(logs);
    std::vector<Log> foundLogs = LogHandler::findLogsInDateRange(logs, startDate, endDate);
    LogHandler::writeLogsToFile(foundLogs, outputFilename);
    std::cout << "Found logs in the specified date range have been stored in '" << outputFilename << "'." << std::endl;
}

void displayLogsInRange(const std::string& inputFilename, const std::string& startDate, const std::string& endDate) {
    std::vector<Log> logs = LogHandler::readLogsFromFile(inputFilename);
    LogHandler::sortByDateTime(logs);
    std::vector<Log> foundLogs = LogHandler::findLogsInDateRange(logs, startDate, endDate);
    LogHandler::displayLogsInRange(foundLogs);
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        displayHelp();
        return 0;
    }

    std::vector<std::string> arguments(argv + 1, argv + argc);

    if (arguments[0] == "-h" || arguments[0] == "--help") {
        displayHelp();
    } else if (arguments[0] == "-s" || arguments[0] == "--sort") {
        sortLogsAndWriteToFile("utils/log601-1.txt", "utils/sorted_logs.txt");
    } else if (arguments[0] == "-f" || arguments[0] == "--find") {
        if (arguments.size() < 3) {
            std::cerr << "Error: Date range not provided." << std::endl;
            return 1;
        }
        findAndWriteLogsToFile("utils/log601-1.txt", "utils/found_logs.txt", arguments[1], arguments[2]);
    } else if (arguments[0] == "-d" || arguments[0] == "--display") {
        if (arguments.size() < 3) {
            std::cerr << "Error: Date range not provided." << std::endl;
            return 1;
        }
        displayLogsInRange("utils/log601-1.txt", arguments[1], arguments[2]);
    } else if (arguments[0] == "-w" || arguments[0] == "--write") {
        sortLogsAndWriteToFile("utils/log601-1.txt", "utils/output601.txt");
    } else {
        std::cerr << "Error: Invalid option. Use -h or --help for usage information." << std::endl;
        return 1;
    }

    return 0;
}
