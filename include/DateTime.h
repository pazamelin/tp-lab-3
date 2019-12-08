//
// Created by Оксана on 18.11.2019.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H

#include <string>

using std::string;

class DateTime {
private:
    struct tm* current_time;
public:
    DateTime(int, int, int);
    DateTime();
    DateTime(const DateTime &);
    string getToday();
    string getYesterday();
    string getTomorrow();
    string getFuture(unsigned int);
    string getPast(unsigned int);
    int getDifference(DateTime&);
};

#endif //TASK1_DATETIME_H
