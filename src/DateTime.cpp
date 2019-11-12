//
// Created by Yakhtin Leonid on 12.11.2019.
//

#include "DateTime.h"
static int DAY = 24*60*60;
DateTime::DateTime(int day,int month, int year){
    time_t t = time(0);
    curtime =*(localtime(&t));
    curtime.tm_mday=day;
    curtime.tm_mon=month-1;
    curtime.tm_year=year-1900;
}

DateTime::DateTime(){
    time_t t = time(0);
    curtime =*(localtime(&t));
}

DateTime::DateTime(DateTime &date) {
    curtime.tm_mday = date.curtime.tm_mday;
    curtime.tm_mon = date.curtime.tm_mon;
    curtime.tm_year = date.curtime.tm_year;
}

string DateTime::getToday(){
    return convert(curtime);
}

string DateTime::getYesterday(){
    return getPast(1);
}

string DateTime::getTomorrow(){
    return getFuture(1);
}

string DateTime::getFuture(unsigned int N){
    time_t t = mktime(&curtime) + N*DAY;
    tm future = *(localtime(&t));
    return convert(future);
}

string DateTime::getPast(unsigned int N){
    time_t t = mktime(&curtime) - N*DAY;
    tm past = *(localtime(&t));
    return convert(past);
}

int DateTime::getDifference(DateTime& date){
    time_t first = mktime(&curtime);
    time_t second =mktime(&(date.curtime));
    if(first>second)std::swap(first,second);
    return (second-first)/DAY;
}

string DateTime::convert(tm ctime){
    return day[ctime.tm_mday]+" "+month[ctime.tm_mon]+" "+std::to_string(ctime.tm_year+1900)+", "+weekday[ctime.tm_wday];
}