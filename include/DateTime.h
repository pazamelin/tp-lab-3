#ifndef INC_2_DATETIME_H
#define INC_2_DATETIME_H

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

class DateTime {
private:
    time_t timer;
    tm* _time;

    std::string _makeStr(tm* _time);
public:
    time_t dayT = 86400;
    std::vector<std::string> months = {
            "january",
            "february",
            "march",
            "april",
            "may",
            "june",
            "july",
            "august",
            "september",
            "october",
            "november",
            "december"
    };
    std::vector<std::string> week = {
            "sunday",
            "monday",
            "tuesday",
            "wednesday",
            "thursday",
            "friday",
            "satturday"
    };

    DateTime();
    DateTime(int d, int m, int y);

    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int N);
    std::string getPast(unsigned int N);
    int getDifference(DateTime&);
};

std::string nameOfMonth(int m);

#endif //INC_2_DATETIME_H
