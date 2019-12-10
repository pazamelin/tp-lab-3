#include "DateTime.h"
#include <time.h>
#include <string>
#include <math.h>

using namespace std;
string DateTime::ttos(tm* th){
    string str;
    if(th->tm_mday < 10){
        str = "0";
    }
    str.append(to_string(th->tm_mday) + " " + monNames[th->tm_mon] + " " + to_string(th->tm_year + 1900) + ", " + weekDNames[th ->tm_wday]);
    return str;
}

string DateTime::getToday(){
    time_t timer = time(0);
    tm* temp = localtime(&timer);
    temp->tm_mday = this->day;
    temp->tm_mon = this->month;
    temp->tm_year = this->year;
    timer = mktime(temp);
    temp = localtime(&timer);
    return ttos(temp);
}

string DateTime::getYesterday(){
    return getPast(1);
}

string DateTime::getTomorrow(){
    return getFuture(1);
}

string DateTime::getFuture(unsigned int N){
    time_t timer = time(0);
    tm* temp = localtime(&timer);
    temp->tm_mday = this->day + N;
    temp->tm_mon = this->month;
    temp->tm_year = this->year;
    timer = mktime(temp);
    temp = localtime(&timer);
    return ttos(temp);
}

string DateTime::getPast(unsigned int N){
    time_t timer = time(0);
    tm* temp = localtime(&timer);
    temp->tm_mday = this->day - N;
    temp->tm_mon = this->month;
    temp->tm_year = this->year;
    timer = mktime(temp);
    temp = localtime(&timer);
    return ttos(temp);
}

int DateTime::getDifference(DateTime& U){
    return(((this->year + 1900) * 365) + ((this->month + 1) * 30) + this->day) - (((U.year + 1900) * 365) + ((U.month + 1) * 30) + U.day);
}

DateTime::DateTime(int day, int month, int year){
    this->day = day;
    this->month = month - 1;
    this->year = year - 1900;
}

DateTime::DateTime(){
    time_t temp = time(0);
    tm* t = localtime(&temp);
    this->day = t->tm_mday;
    this->month = t->tm_mon;
    this->year = t->tm_year;
}

DateTime::DateTime(const DateTime& dt){
    this->day = dt.day;
    this->month = dt.month;
    this->year = dt.year;
}

