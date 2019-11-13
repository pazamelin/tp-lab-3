//
// Created by Yakhtin Leonid on 12.11.2019.
//

#ifndef DATETIME_H
#define DATETIME_H

#include <bits/stdc++.h>

using std::string;
using std::vector;

class DateTime {
    tm curtime;

public:
    DateTime(int day, int month, int year);

    DateTime();

    DateTime(DateTime &date);

    string getToday();

    string getYesterday();

    string getTomorrow();

    string getFuture(unsigned int N);

    string getPast(unsigned int N);

    int getDifference(DateTime &);

    string convert(tm ctime);
};


#endif //DATETIME_H
