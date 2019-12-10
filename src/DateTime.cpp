//
// Created by aklen on 10.11.2019.
//
#include "DateTime.h"
#include <time.h>

using namespace std;

string DateTime::weekDays[7]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
string DateTime::months[12]={"january", "february", "march", "april", "may", "june",
                             "july", "august", "september", "october", "november", "december" };

DateTime::DateTime(unsigned int cur_day,unsigned int cur_month,unsigned  int cur_year){
    this->day=cur_day;
    this->month=cur_month-1;
    this->year=cur_year;
}

DateTime::DateTime(){
    time_t t=time(NULL);
    tm* time_now=localtime(&t);//преобразование времени из системного в местное
    this->day=(unsigned int)(time_now->tm_mday);
    this->month=(unsigned int)(time_now->tm_mon);
    this->year=(unsigned int)(time_now->tm_year+1900);
}

DateTime::DateTime(const DateTime &date){
    this->day=date.day;
    this->month=date.month;
    this->year=date.year;
}

tm conversion(int day,int month, int year){
    tm time_in={0,0,0,day,month,year-1900};
    time_t t=mktime(&time_in);
    tm* time_out=localtime(&t);
    return *time_out;
}

string DateTime::getString(int day,int month,int year){
    string date="";
    date +=(day>=10 ? to_string(day): "0" + to_string(day)) + " ";
    date +=DateTime::months[month] + " ";
    date +=to_string(year)+", ";
    date +=weekDays[conversion(day,month,year).tm_wday];
    return date;
}

string DateTime::getToday() {
    return getString(this->day, this->month, this->year);
}

string DateTime::getFuture(unsigned int n) {
    tm future_day = (conversion(this->day + n, this->month, this->year));
    return getString(future_day.tm_mday, future_day.tm_mon, future_day.tm_year+1900);
}


string DateTime::getPast(unsigned int n) {
    tm past_day = conversion(this->day - n, this->month, this->year);
    return getString(past_day.tm_mday, past_day.tm_mon, past_day.tm_year+1900);
}

string DateTime::getTomorrow() {
    return getFuture(1);
}

string DateTime::getYesterday() {
    return getPast(1);
}

int DateTime::getDifference(DateTime &date){
    tm current = conversion(this->day,this->month,this->year);
    tm compare = conversion(date.day,date.month,date.year);
    int difference = abs(mktime(&current)- mktime(&compare));
    return (difference/(24*60*60));
}
