//
//  DateTime.hpp
//  Third Shtanyuk's lab
//
//  Created by Коля on 16/12/2019.
//  Copyright © 2019 Коля. All rights reserved.
//

#ifndef DateTime_hpp
#define DateTime_hpp

#include <ctime>
#include <string>
#include <vector>

#define DAY 86400

class DateTime {
private:
    tm timeval;
    void getCurrentTime();
    std::string dateToString(tm);
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

    std::vector<std::string> days = {
        "sunday",
        "monday",
        "tuesday",
        "wednesday",
        "thursday",
        "friday",
        "satturday"
    };
public:
    DateTime(short, short, short);
    DateTime();
    DateTime(DateTime const&);
    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int);
    std::string getPast(unsigned int);
    unsigned int getDifference(DateTime&);
};
#endif /* DateTime_hpp */
