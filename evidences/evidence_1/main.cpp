#include <iostream>
#include <vector>
#include "include/Log.h"

int main() {
    const std::string filename = "utils/log601-1.txt";
    std::vector<Log> logs = LogHandler::readLogsFromFile(filename);
    LogHandler::sortByDateTime(logs);

    for (const auto& log : logs) {
        std::cout << log.getMonth() << " | " << log.getDay() << " | " << log.getYear() << " | " << log.getTime() << " | " << log.getIP() << " | " << log.getMessage() << std::endl;
    }

    return 0;
}
