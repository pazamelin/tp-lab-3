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
#include <algorithm>
#include <cctype>

#define DAY 86400

class DateTime {
private:
    tm timeval;
    void getCurrentTime();
    std::string dateToString(tm);
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
