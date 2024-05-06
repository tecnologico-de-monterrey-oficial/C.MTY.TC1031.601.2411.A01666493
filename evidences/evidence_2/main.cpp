#include <iostream>
#include <vector>
#include "include/Log.h"

void displayMenu() {
    std::cout << "===================================================" << std::endl;
    std::cout << "Welcome to Log Management System" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "1. Display logs sorted by date and time" << std::endl;
    std::cout << "2. Display logs sorted by IP address" << std::endl;
    std::cout << "3. Search logs by IP range" << std::endl;
    std::cout << "4. Display IP count by year and month" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "===================================================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    DoublyLinkedList logs = LogHandler::readLogsFromFile("data/log601-2.txt");

    if (logs.getHead()) {
        int choice = 0;
        do {
            displayMenu();
            std::cin >> choice;
            switch (choice) {
                case 1:
                    LogHandler::sortByDateTime(logs.getHead(), nullptr);
                    LogHandler::displayLogsInRange(logs);
                    LogHandler::writeLogsToFile(logs, "data/output601-1.out");
                    break;
                case 2:
                    LogHandler::sortByIPDateTime(logs.getHead(), nullptr);
                    LogHandler::writeLogsToFile(logs, "data/output601-2.out");
                    std::cout << "Logs sorted by IP address." << std::endl;
                    break;
                case 3: {
                    std::string startRange, endRange;
                    std::cout << "Enter start IP range: ";
                    std::cin >> startRange;
                    std::cout << "Enter end IP range: ";
                    std::cin >> endRange;
                    DoublyLinkedList resultList = LogHandler::searchByIPRange(logs, startRange, endRange);
                    LogHandler::generateOutputFiles(resultList, "iprange601");
                    break;
                }
                case 4: {
                    std::unordered_map<std::string, int> ipCountMap = LogHandler::countIPsByYearMonth(logs);
                    LogHandler::displayIPCount(ipCountMap);
                    break;
                }
                case 5:
                    std::cout << "Exiting... Thank you!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            }
        } while (choice != 5);
    } else {
        std::cerr << "Error: No logs found or unable to read logs from file." << std::endl;
    }

    return 0;
}
