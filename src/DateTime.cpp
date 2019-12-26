//
// Created by Mikhail on 12.11.2019.
//

#include "DateTime.h"

DateTime::DateTime() {
    currentDay = new tm;
    time_t rawtime = time(nullptr);
    currentDay = localtime(&rawtime);
}

DateTime::DateTime(int newDay, int newMonth, int newYear) {
    currentDay = new tm;
    time_t w = 1;
    memcpy(currentDay, localtime(&w), sizeof(tm));
    currentDay->tm_mday = newDay;
    currentDay->tm_mon = newMonth - 1;
    currentDay->tm_year = newYear - 1900;
    mktime(currentDay);
}

std::string DateTime::getFuture(unsigned int N) {
    time_t seconds = mktime(currentDay);
    seconds += N * 60 * 60 * 24;
    tm* newDay = localtime(&seconds);
    return getString(newDay);
}

std::string DateTime::getPast(unsigned int N) {
    time_t seconds = mktime(currentDay);
    seconds -= N * 60 * 60 * 24;
    tm* newDay = localtime(&seconds);
    return getString(newDay);
}

std::string DateTime::getToday() {
    return this->getString(currentDay);
}

std::string DateTime::getString(tm* Day) {
    std::vector<std::string> days = {
            "sunday",
            "monday",
            "tuesday",
            "wednesday",
            "thursday",
            "friday",
            "saturday"
    };
    std::vector<std::string> months = {
            "january", "february", "march",
            "april", "may", "june",
            "july", "august", "september",
            "october", "november", "december"
    };
    std::string date;
    if(Day->tm_mday < 10) date += "0";
    date += toString(Day->tm_mday) + " "
            + months[Day->tm_mon] + " "
            + toString(Day->tm_year + 1900) + ", "
            + days[Day->tm_wday];
    return date;
}

std::string DateTime::getYesterday() {
    return getPast(1);
}

std::string DateTime::getTomorrow() {
    return getFuture(1);
}

int DateTime::getDifference(DateTime &d) {
    return abs(mktime(currentDay) - mktime(d.currentDay)) / (60 * 60 * 24);
}

DateTime::DateTime(const DateTime &newData) {
    memcpy(this->currentDay, newData.currentDay, sizeof(tm));
}


