//
// Created by Илья Соловьёв on 04.11.2019.
//

#include "DateTime.h"

//Because of capitalized strings provided by strftime
string dayWeek[] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

DateTime::DateTime(int day, int mon, int year) {
    time_t seconds = time(0);
    date = *localtime(&seconds);
    date.tm_year = year - 1900;
    date.tm_mon = mon - 1;
    date.tm_mday = day;
}

DateTime::DateTime() {
    time_t seconds = time(0);
    date = *localtime(&seconds);
    //memcpy(&date, localtime(&seconds), sizeof(tm));

}

DateTime::DateTime(DateTime &forCopy) {
    date = forCopy.date;
}

string DateTime::getToday() {
    char str[50];
    strftime(str, 50, "%d %B %Y, ", &date);
    string res = string(str);
    res = res + dayWeek[date.tm_wday];
    return res;
}

string DateTime::getYesterday() {
    char str[50];
    time_t tmp = mktime(&date) - 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, ", yesterday);
    string res = string(str);
    res = res + dayWeek[yesterday->tm_wday];
    return res;
}

string DateTime::getTomorrow() {
    char str[50];
    time_t tmp = mktime(&date) + 24 * 60 * 60;
    tm *tomorrow = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, ", tomorrow);
    string res = string(str);
    res = res + dayWeek[tomorrow->tm_wday];
    return res;
}

string DateTime::getFuture(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) + N * 24 * 60 * 60;
    tm *future = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, ", future);
    string res = string(str);
    res = res + dayWeek[future->tm_wday];
    return res;
}

string DateTime::getPast(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) - N * 24 * 60 * 60;
    tm *past = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, ", past);
    string res = string(str);
    res = res + dayWeek[past->tm_wday];
    return res;
}

int DateTime::getDifference(DateTime &second) {
    long seconds = abs(mktime(&second.date) - mktime(&this->date));
    return seconds / (24 * 60 * 60);
}

/*





std::string DateTime::getToday()
{
    date = StringDate(time_now);
    return date;
}

std::string DateTime::getTomorrow()
{
    time_now += 86400;
    date = StringDate(time_now);
    return date;
}

std::string DateTime::getYesterday()
{
    time_now -= 86400;
    date = StringDate(time_now);
    return date;
}

std::string DateTime::getFuture(unsigned int N)
{
    time_now += 86400 * N;
    date = StringDate(time_now);
    return date;
}

std::string DateTime::getPast(unsigned int N)
{
    time_now -= 86400 * N;
    date = StringDate(time_now);
    return date;
}

unsigned int DateTime::getDifference(DateTime &DateTime)
{
    unsigned int diff = (abs(DateTime.time_now - this->time_now)) / 86400;
    return diff;
}

 */