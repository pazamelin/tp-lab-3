//
// Created by Илья Соловьёв on 04.11.2019.
//

#include "DateTime.h"

DateTime::DateTime(int day, int mon, int year) {
    seconds = time(0);
    date = *localtime(&seconds);
    date.tm_year = year - 1900;
    date.tm_mon = mon - 1;
    date.tm_mday = day;
    seconds = mktime(&date);
}

DateTime::DateTime() {
    seconds = time(0);
    date = *localtime(&seconds);
    //memcpy(&date, localtime(&seconds), sizeof(tm));

}

DateTime::DateTime(DateTime &forCopy) {
    seconds = forCopy.seconds;
    date = forCopy.date;
}

string DateTime::getToday() {
    char str[50];
    strftime(str, 50, "%d %B %Y, %A", &date);
    return str;
}

string DateTime::getYesterday() {
    char str[50];
    time_t tmp = mktime(&date) - 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", yesterday);
    return str;
}

string DateTime::getTomorrow() {
    char str[50];
    time_t tmp = mktime(&date) + 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", yesterday);
    return str;
}

string DateTime::getFuture(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) + N * 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", yesterday);
    return str;
}

string DateTime::getPast(unsigned int N) {
    char str[50];
    time_t tmp = mktime(&date) - N * 24 * 60 * 60;
    tm *yesterday = localtime(&tmp);
    strftime(str, 50, "%d %B %Y, %A", yesterday);
    return str;
}

int DateTime::getDifference(DateTime &second) {
//    days += abs(second.date.tm_year - this->date.tm_year) * 365;
//    days += abs(second.date.tm_yday - this->date.tm_yday);
    long seconds = abs(second.seconds - this->seconds);
    return seconds/(24*60*60);
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