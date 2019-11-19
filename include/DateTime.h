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

    static unsigned int DAY;
    static vector<string> day;
    static vector<string> weekday;
    static vector<string> month;

public:

    DateTime(int day, int month, int year);

    DateTime();

    DateTime(DateTime &date);

    string getToday() const;

    string getYesterday();

    string getTomorrow();

    string getFuture(unsigned int N);

    string getPast(unsigned int N);

    int getDifference(DateTime &date);

    string convert(tm ctime) const;
};


#endif //DATETIME_H
