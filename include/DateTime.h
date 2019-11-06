//
//  DateTime.h
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef DateTime_h
#define DateTime_h

#include <ctime>
#include <string>

class DateTime {
private:
    time_t _time_value;
    tm *_time;
    tm* _copyDate(tm*);
    std::string _printDate(tm*);
public:
    DateTime(int, int, int);
    DateTime();
    DateTime(DateTime const&);
    ~DateTime();
    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int);
    std::string getPast(unsigned int);
    unsigned int getDifference(DateTime&);
};

#endif /* DateTime_h */
