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
Evidence 3 - Integral Activity of Hierarchical Data Structures
========================================================================

Welcome to the Log Analyzer!
Usage: g++ -o build/main main.cpp -std=c++11 && ./build/main

Jesus Raul Jimenez Perez - A01666493

Options:
-h, --help         Show help message and exit.
-s-max, --sort-maxheap        Sort data by IP, date, and time in descending order. (Uses HeapSort, MaxHeap).
-s-min, --sort-minheap        Sort data by IP, date, and time in ascending order. (Uses HeapSort, MinHeap).
-d,     --display             Display the top 10 IPs with the most records in descending order.
-s,     --search              Search for an IP in a binary search tree.
    )" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        displayHelp();
        return 0;
    }

    std::string filename = "data/log601-3.txt";
    std::vector<Log> logs = LogHandler::readLogsFromFile(filename);

    if (argc == 2) {
        std::string option = std::string(argv[1]);
        
        if (option == "-h" || option == "--help") {
            displayHelp();
        } else if (option == "-s-max" || option == "--sort-maxheap") {
            LogHandler::sortLogsByMaxHeap(logs, "data/output601-1.out");
        } else if (option == "-s-min" || option == "--sort-minheap") {
            LogHandler::sortLogsByMinHeap(logs, "data/output601-2.out");
        } else if (option == "-d" || option == "--display") {
            for (const Log &log : logs) {
                std::cout << log.getMonth() << " " << log.getDay() << " " << log.getYear() << " " << log.getTime() << " " << log.getIP() << " " << log.getMessage() << std::endl;
            }
        } else if (option == "-s" || option == "--search") {
            BST ipBST;
            LogHandler::buildIPBST(logs, ipBST);
            LogHandler::searchIPInBST(ipBST);
        } else {
            std::cerr << "Unknown option: " << option << std::endl;
            displayHelp();
        }
    } else {
        std::cerr << "Invalid number of arguments." << std::endl;
        displayHelp();
    }

    return 0;
}
