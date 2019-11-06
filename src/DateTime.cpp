//
//  DateTime.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "DateTime.h"
#include <vector>
#include <cstring>

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

tm* DateTime::_copyDate(tm* src) {
    tm *dest = new tm;
    dest->tm_sec = src->tm_sec;
    dest->tm_min = src->tm_min;
    dest->tm_hour = src->tm_hour;
    dest->tm_mday = src->tm_mday;
    dest->tm_mon = src->tm_mon;
    dest->tm_year = src->tm_year;
    dest->tm_wday = src->tm_wday;
    dest->tm_yday = src->tm_yday;
    dest->tm_isdst = src->tm_isdst;
    dest->tm_gmtoff = src->tm_gmtoff;
    dest->tm_zone = new char[strlen(src->tm_zone)];
    const char* src_str = src->tm_zone;
    strcpy(dest->tm_zone, src_str);
    return dest;
}

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
    tm *yest = _copyDate(_time);
    yest->tm_mday -= 1;
    mktime(yest);
    return _printDate(yest);
}

std::string DateTime::getTomorrow() {
    tm *tom = _copyDate(_time);
    tom->tm_mday += 1;
    mktime(tom);
    return _printDate(tom);
}

std::string DateTime::getFuture(unsigned int diff) {
    tm *fut = _copyDate(_time);
    fut->tm_mday += diff;
    mktime(fut);
    return _printDate(fut);
}

std::string DateTime::getPast(unsigned int diff) {
    tm *past = _copyDate(_time);
    past->tm_mday += diff;
    mktime(past);
    return _printDate(past);
}

unsigned int DateTime::getDifference(DateTime &date) {
    time_t diff = difftime(date._time_value, _time_value);
    diff = abs(diff);
    tm *temp = localtime(&diff);
    unsigned int res = temp->tm_yday - 1;
    localtime(&_time_value);
    return res;
}






