//
//  DateTime.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "DateTime.h"
#include <vector>
#include <string.h>

//CHECK FOR SPELLING
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

std::vector<std::string> weekDays = {
    "sunday",
    "monday",
    "tuesday",
    "wednesday",
    "thursday",
    "friday",
    "satturday"
};

std::string DateTime::_printDate(tm *date) {
    std::string res;
    if (date->tm_mday < 10)
        res = "0" + std::to_string(date->tm_mday);
    else
        res = std::to_string(date->tm_mday);
    res += " " + months[date->tm_mon] + " " + std::to_string(1900 + date->tm_year) + ", " + weekDays[date->tm_wday];
    return res;
}

DateTime::DateTime(int day, int month, int year) {
    _time = new tm;
    _time->tm_mday = day;
    _time->tm_mon = month - 1;
    _time->tm_year = year - 1900;
    _time_value = mktime(_time);
    _time->tm_mday = day;
    _time->tm_mon = month - 1;
    _time->tm_year = year - 1900;
}

DateTime::DateTime() {
    time(&_time_value);
    _time = localtime(&_time_value);
}

DateTime::DateTime(DateTime const &src) {
    _time_value = mktime(src._time);
    _time = localtime(&_time_value);
}

DateTime::~DateTime() {
    delete _time;
}

std::string DateTime::getToday() {
    return _printDate(_time);
}

std::string DateTime::getYesterday() {
    time_t yest_time = _time_value;
    tm *yest = localtime(&yest_time);
    yest->tm_mday -= 1;
    mktime(yest);
    localtime(&_time_value);
    return _printDate(yest);
}

std::string DateTime::getTomorrow() {
    time_t tom_time = _time_value;
    tm *tom = localtime(&tom_time);
    tom->tm_mday += 1;
    mktime(tom);
    std::string res = _printDate(tom);
    localtime(&_time_value);
    return res;
}

std::string DateTime::getFuture(unsigned int diff) {
    time_t fut_time = _time_value;
    tm *fut = localtime(&fut_time);
    fut->tm_mday += diff;
    mktime(fut);
    std::string res = _printDate(fut);
    localtime(&_time_value);
    return res;
}

std::string DateTime::getPast(unsigned int diff) {
    time_t past_time = _time_value;
    tm *past = localtime(&past_time);
    past->tm_mday += diff;
    mktime(past);
    std::string res = _printDate(past);
    localtime(&_time_value);
    return res;
}

unsigned int DateTime::getDifference(DateTime &date) {
    time_t diff = difftime(date._time_value, _time_value);
    diff = abs(diff);
    tm *temp = localtime(&diff);
    unsigned int res = temp->tm_yday - 1;
    localtime(&_time_value);
    return res;
}






