#include <string>

using namespace std;

struct Log{
    string month;
    string day;
    string year;
    string time;
    string ip;
    string message;

    Log(string month, string day, string year, string time, string ip, string message) {
        this->month = month;
        this->day = day;
        this->year = year;
        this->time = time;
        this->ip = ip;
        this->message = message;
    }
};


