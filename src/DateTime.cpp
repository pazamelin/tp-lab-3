//
// Created by Yakhtin Leonid on 12.11.2019.
//

#include "DateTime.h"
static unsigned int DAY = 24*60*60;
static vector<string> day = {"00", "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13", "14",
                      "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29",
                      "30", "31"};
static vector<string> weekday = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
static vector<string> month = {"january", "february", "march", "april", "may", "june", "july", "august", "september",
                        "october", "november", "december"};

DateTime::DateTime(int day,int month, int year){
    curtime.tm_mday=day;
    curtime.tm_mon=month-1;
    curtime.tm_year=year-1900;
    curtime.tm_sec = 0;
    curtime.tm_min = 0;
    curtime.tm_hour = 0;
    time_t t = mktime(&curtime);
    curtime = *(localtime(&t));
}

DateTime::DateTime(){
    time_t t = time(0);
    curtime =*(localtime(&t));
}

DateTime::DateTime(DateTime &date) {
    curtime = date.curtime;
}

string DateTime::getToday(){
    return convert(curtime);
    //return getFuture(0);
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