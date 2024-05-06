#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

class MonthConverter {
public:
    static std::string convertToNumber(const std::string month) {
        static const std::unordered_map<std::string, std::string> monthMap = {
            {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},
            {"Apr", "04"}, {"May", "05"}, {"Jun", "06"},
            {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},
            {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        auto it = monthMap.find(month);
        if (it != monthMap.end()) {
            return it->second;
        }
        std::cout << "Month not found in map!" << std::endl;
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
    Log(const std::string &month, const std::string &day, const std::string &year,
        const std::string &time, const std::string &ip, const std::string &message)
        : month(month), day(day), year(year), time(time), ip(ip), message(message) {
        this->key = year + MonthConverter::convertToNumber(month) + day + time;
    }

    const std::string &getMonth() const { return month; }
    const std::string &getDay() const { return day; }
    const std::string &getYear() const { return year; }
    const std::string &getTime() const { return time; }
    const std::string &getIP() const { return ip; }
    const std::string &getMessage() const { return message; }
    const std::string &getKey() const { return key; }
};

class Node {
public:
    Log data;
    Node* next;
    Node* prev;

    Node(const Log& log) : data(log), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const Log& log) {
        Node* newNode = new Node(log);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    Node* getHead() const { return head; }
};

class LogHandler {
public:
    static DoublyLinkedList readLogsFromFile(const std::string &filename) {
        DoublyLinkedList logList;
        std::ifstream logFile(filename);
        if (!logFile.is_open()) {
            return logList;
        }
        std::string line;
        while (std::getline(logFile, line)) {
            std::stringstream ss(line);
            std::string month, day, year, time, ip, message;
            ss >> month >> day >> year >> time >> ip;
            std::getline(ss, message);
            Log log(month, day, year, time, ip, message);
            logList.insert(log);
        }
        logFile.close();
        return logList;
    }

    static void displayLogsInRange(const DoublyLinkedList &logList) {
        std::cout << "========================================================================" << std::endl;
        std::cout << "Logs within the specified date range:" << std::endl;
        std::cout << "========================================================================" << std::endl;
        std::cout << "  Date       Time       IP Address     Message" << std::endl;
        std::cout << "------------------------------------------------------------------------" << std::endl;

        Node* current = logList.getHead();
        while (current) {
            const Log& log = current->data;
            std::cout << log.getMonth() << " " << log.getDay() << ", " << log.getYear() << "  ";
            std::cout << log.getTime() << "  " << log.getIP() << "  " << log.getMessage() << std::endl;
            current = current->next;
        }

        std::cout << "========================================================================" << std::endl;
    }

    static void writeLogsToFile(const DoublyLinkedList &logList, const std::string &filename) {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Error: Could not open file for writing." << std::endl;
            return;
        }

        Node* current = logList.getHead();
        while (current) {
            const Log& log = current->data;
            outputFile << log.getMonth() << " " << log.getDay() << " " << log.getYear() << " "
                       << log.getTime() << " " << log.getIP() << " " << log.getMessage() << std::endl;
            current = current->next;
        }

        outputFile.close();
    }

    static void sortByDateTime(Node* head, Node* tail) {
        if (head == nullptr || head == tail || head->next == nullptr) {
            return;
        }

        Node* mid = getMiddle(head, tail);
        Node* nextToMid = mid->next;

        sortByDateTime(head, mid);
        sortByDateTime(nextToMid, tail);

        merge(head, mid, nextToMid, tail);
    }

    static void sortByIPDateTime(Node* head, Node* tail) {
        if (head == nullptr || head == tail || head->next == nullptr) {
            return;
        }

        Node* mid = getMiddle(head, tail);
        Node* nextToMid = mid->next;

        sortByIPDateTime(head, mid);
        sortByIPDateTime(nextToMid, tail);

        mergeByIPDateTime(head, mid, nextToMid, tail);
    }

    static void mergeByIPDateTime(Node* head1, Node* tail1, Node* head2, Node* tail2) {
        DoublyLinkedList mergedList;
        Node* tempHead = nullptr;

        while (head1 != nullptr && head2 != nullptr) {
            if (compareLogs(head1->data, head2->data) <= 0) {
                if (tempHead == nullptr) {
                    tempHead = head1;
                }
                mergedList.insert(head1->data);
                head1 = head1->next;
            } else {
                if (tempHead == nullptr) {
                    tempHead = head2;
                }
                mergedList.insert(head2->data);
                head2 = head2->next;
            }
        }

        while (head1 != nullptr) {
            mergedList.insert(head1->data);
            head1 = head1->next;
        }

        while (head2 != nullptr) {
            mergedList.insert(head2->data);
            head2 = head2->next;
        }

        Node* current = tempHead;
        Node* mergedCurrent = mergedList.getHead();
        while (current != nullptr && mergedCurrent != nullptr) {
            current->data = mergedCurrent->data;
            if (current->prev) {
                current->prev->next = current;
            }
            if (current->next) {
                current->next->prev = current;
            }
            current = current->next;
            mergedCurrent = mergedCurrent->next;
        }
    }

    static int compareLogs(const Log& log1, const Log& log2) {
        int ipComparison = log1.getIP().compare(log2.getIP());
        if (ipComparison != 0) {
            return ipComparison;
        }

        int yearComparison = log1.getYear().compare(log2.getYear());
        if (yearComparison != 0) {
            return yearComparison;
        }

        int monthComparison = MonthConverter::convertToNumber(log1.getMonth()).compare(MonthConverter::convertToNumber(log2.getMonth()));
        if (monthComparison != 0) {
            return monthComparison;
        }

        int dayComparison = log1.getDay().compare(log2.getDay());
        if (dayComparison != 0) {
            return dayComparison;
        }

        return log1.getTime().compare(log2.getTime());
    }

    static bool isInRange(const std::string& ip, const std::string& startRange, const std::string& endRange) {
        return (ip >= startRange && ip <= endRange);
    }

    static DoublyLinkedList searchByIPRange(const DoublyLinkedList& logList, const std::string& startRange, const std::string& endRange) {
        DoublyLinkedList resultList;
        Node* current = logList.getHead();
        while (current) {
            if (isInRange(current->data.getIP(), startRange, endRange)) {
                resultList.insert(current->data);
            }
            current = current->next;
        }
        return resultList;
    }

    static DoublyLinkedList reverseList(const DoublyLinkedList& list) {
        DoublyLinkedList reversedList;
        Node* current = list.getHead();
        while (current) {
            reversedList.insert(current->data);
            current = current->next;
        }
        return reversedList;
    }


    static void generateOutputFiles(const DoublyLinkedList& resultList, const std::string& filenamePrefix) {
        writeLogsToFile(resultList, filenamePrefix + "-a.out");

        DoublyLinkedList reversedList = reverseList(resultList);
        writeLogsToFile(reversedList, filenamePrefix + "-d.out");
    }

    static std::unordered_map<std::string, int> countIPsByYearMonth(const DoublyLinkedList &logList) {
        std::unordered_map<std::string, int> ipCountMap;
        Node* current = logList.getHead();
        while (current) {
            std::string yearMonth = current->data.getYear() + "-" + current->data.getMonth();
            ipCountMap[yearMonth]++;
            current = current->next;
        }
        return ipCountMap;
    }

    static void displayIPCount(const std::unordered_map<std::string, int> &ipCountMap) {
        std::cout << "IP count by year and month:\n";
        for (const auto &entry : ipCountMap) {
            std::cout << entry.first << ": " << entry.second << " IPs\n";
        }
    }

private:
    static Node* getMiddle(Node* head, Node* tail) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    static void merge(Node* head1, Node* tail1, Node* head2, Node* tail2) {
        DoublyLinkedList mergedList;
        Node* tempHead = nullptr;

        while (head1 != nullptr && head2 != nullptr) {
            if (head1->data.getKey() <= head2->data.getKey()) {
                if (tempHead == nullptr) {
                    tempHead = head1;
                }
                mergedList.insert(head1->data);
                head1 = head1->next;
            } else {
                if (tempHead == nullptr) {
                    tempHead = head2;
                }
                mergedList.insert(head2->data);
                head2 = head2->next;
            }
        }

        while (head1 != nullptr) {
            mergedList.insert(head1->data);
            head1 = head1->next;
        }

        while (head2 != nullptr) {
            mergedList.insert(head2->data);
            head2 = head2->next;
        }

        Node* current = tempHead;
        Node* mergedCurrent = mergedList.getHead();
        while (current != nullptr && mergedCurrent != nullptr) {
            current->data = mergedCurrent->data;
            if (current->prev) {
                current->prev->next = current;
            }
            if (current->next) {
                current->next->prev = current;
            }
            current = current->next;
            mergedCurrent = mergedCurrent->next;
        }
    }

    
};