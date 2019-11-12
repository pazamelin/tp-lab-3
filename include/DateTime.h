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
    vector<string> day = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14",
                          "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
                          "30", "31"};
    vector<string> weekday = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    vector<string> month = {"january", "february", "march", "april", "may", "june", "july", "august", "september",
                            "october", "november", "december"};

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
