//
// Created by Илья Соловьёв on 04.11.2019.
//

#include "DateTime.h"

string convert(char str[50]) {
    string res = string(str);
    for (int i = 0; i < res.length(); i++) {
        if ('A' < res[i] && res[i] < 'Z') {
            res[i] = res[i] - ('A' - 'a');
        }
    }
    return res;
}

DateTime::DateTime(int day, int mon, int year) {
    time_t seconds = time(0);
    date = *localtime(&seconds);
    date.tm_year = year - 1900;
    date.tm_mon = mon - 1;
    date.tm_mday = day;
    mktime(&date);
}

DateTime::DateTime() {
    time_t seconds = time(0);
    date = *localtime(&seconds);
    //memcpy(&date, localtime(&seconds), sizeof(tm));

}

DateTime::DateTime(DateTime &forCopy) {
    date = forCopy.date;
}

string const DateTime::getToday() {
    char str[50];
    strftime(str, 50, "%d %B %Y, %A", &date);
    return convert(str);
}

string const DateTime::getYesterday() {
    char str[50];
    time_t tmp = mktime(&date) - 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", yesterday);
    return convert(str);
}

string const DateTime::getTomorrow() {
    char str[50];
    time_t tmp = mktime(&date) + 24 * 60 * 60;
    tm *tomorrow = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", tomorrow);
    return convert(str);
}

string const DateTime::getFuture(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) + N * 24 * 60 * 60;
    tm *future = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", future);
    return convert(str);
}

string const DateTime::getPast(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) - N * 24 * 60 * 60;
    tm *past = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", past);
    return convert(str);
}

int const DateTime::getDifference(DateTime &second) {
    long seconds = abs(mktime(&second.date) - mktime(&this->date));
    return seconds / (24 * 60 * 60);
}