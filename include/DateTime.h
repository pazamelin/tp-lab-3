//
// Created by Илья Соловьёв on 04.11.2019.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H

#include <ctime>
#include <string>
#include <cmath>
#include <string.h>
#include <iostream>

using namespace std;

class DateTime {
private:
    time_t seconds;
    tm date;

public:

    DateTime(int day, int mon, int year);

    DateTime();

    DateTime(DateTime &forCopy);

    string getToday();

    string getYesterday();

    string getTomorrow();

    string getFuture(unsigned int N);

    string getPast(unsigned int N);

    int getDifference(DateTime &second);

};

#endif //TASK1_DATETIME_H
