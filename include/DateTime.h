//
// Created by Mikhail on 12.11.2019.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <cstring>


template<typename T>
std::string toString(T val){
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

class DateTime{
public:
    DateTime();
    DateTime(int newDay, int newMonth, int newYear);
    DateTime(const DateTime &newData);
    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int N);
    std::string getPast(unsigned int N);
    std::string getString(tm* Day);
    int getDifference(DateTime &d);

private:
    tm* currentDay{nullptr};
};
#endif //TASK1_DATETIME_H
