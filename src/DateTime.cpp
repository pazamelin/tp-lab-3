//
// Created by Mary on 04.11.2019.
//
#include <cmath>
#include <string>
#include <sstream>
#include "../include/DateTime.h"
using namespace std;
DateTime::DateTime(unsigned int cur_day, unsigned int cur_month, unsigned int cur_year) {
    this->day = cur_day;
    this->month = cur_month-1;//ля массива месяцев
    this->year = cur_year;
}
tm convert(int day, int month, int year){
    tm time_in = {0,0,0,day, month, year - 1900};
    time_t time = mktime(&time_in);
    tm* time_out = localtime(&time);
    return *time_out;
}
DateTime::DateTime() {
    time_t t = time(0); //get time now
    tm* now = localtime(&t); //преобразует системное время в местное
    this->day = (unsigned int)(now->tm_mday);
    this->month = (unsigned int)(now->tm_mon);
    this->year = (unsigned int)(now->tm_year + 1900);
}
DateTime::DateTime(const DateTime &date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}
const unsigned int DateTime::getDay(){
    return this->day;
}
const unsigned int DateTime::getMonth(){
    return this->month;
}
const unsigned int DateTime::getYear(){
    return this->year;
}
string DateTime::getString(int day, int month, int year){
    string date;
    if (day < 10)
        date = "0";
    stringstream ss;
    string buf;
    ss << day;
    ss >> buf;
    date += buf;
    buf.clear();
    ss.clear();
    date += " "+ months[month] + " ";
    ss << year;
    ss >> buf;
    date += buf;
    date += ", " + daysInWeek[convert(day, month, year).tm_wday ];
    return date;
}
string DateTime::getToday() {
    return getString(this->day, this->month, this->year);
}
string DateTime::getFuture(unsigned int n) {
    tm futureDay = (convert(this->day + n, this->month, this->year));
    return getString(futureDay.tm_mday, futureDay.tm_mon, futureDay.tm_year+1900);
}
string DateTime::getTomorrow() {
    return getFuture(1);
}
string DateTime::getPast(unsigned int n) {
    tm futureDay = convert(this->day - n, this->month, this->year);
    return getString(futureDay.tm_mday, futureDay.tm_mon, futureDay.tm_year+1900);
}
string DateTime::getYesterday() {
    return getPast(1);
}
int DateTime::getDifference(DateTime & date) {
    tm current = convert(this->day, this->month, this->year);
    tm different = convert(date.day, date.month, date.year);
    int difference = abs(mktime(&current)- mktime(&different));
    return (difference/(24*60*60));
}