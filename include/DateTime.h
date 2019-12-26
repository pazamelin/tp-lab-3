//
// Created by Илья on 005 05.11.19.
//

#ifndef TP_LAB_3_DATETIME_H
#define TP_LAB_3_DATETIME_H

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


#endif //TP_LAB_3_DATETIME_H
