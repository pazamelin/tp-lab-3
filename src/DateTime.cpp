#include "DateTime.h"
#include <time.h>

using namespace std;

string DateTime::weekdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
string DateTime::months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

DateTime::DateTime()
{
    time_t timer = time(NULL);
    tm *u = localtime(&timer);
    this->day = u->tm_mday;
    this->month = u->tm_mon;
    this->year = u->tm_year;
}

DateTime::DateTime(int day, int month, int year)
{
    this->day = day;
    this->month = month - 1;
    this->year = year - 1900;
}

DateTime::DateTime(DateTime &data) {
    this->day = data.day;
    this->month = data.month;
    this->year = data.year;
}

string DateTime::shiftFromTodayAt(int shift_by)
{
    time_t timer = time(NULL);
    tm *custom_time = localtime(&timer);

    custom_time->tm_mday = this -> day + shift_by;
    custom_time->tm_mon = this -> month;
    custom_time->tm_year = this -> year;

    timer = mktime(custom_time);
    custom_time= localtime(&timer);

    string buf;

    if (custom_time->tm_mday < 10){
        buf.append("0");
        buf.append(to_string(custom_time->tm_mday));
    }
    else buf.append(to_string(custom_time->tm_mday));

    buf.append(" ");
    buf.append(months[custom_time->tm_mon]);
    buf.append(" ");
    buf.append(to_string(custom_time->tm_year + 1900));
    buf.append(", ");
    buf.append(weekdays[custom_time->tm_wday]);

    return buf;
}
string DateTime::getToday() {return shiftFromTodayAt(0);}
string DateTime::getTomorrow() {return shiftFromTodayAt(1);}
string DateTime::getYesterday() {return shiftFromTodayAt(-1);}
string DateTime::getFuture(int val) {return shiftFromTodayAt(val);}
string DateTime::getPast(int val) {return shiftFromTodayAt(-val);}

int DateTime::calcInDays(int y,int m,int d){
    if(m<3){
        --y;
        m+=12;
    }
    return 365*y+ y/4 - y/100 + y/400 + (153*m- 457)/5 + d - 306;
}

int DateTime::getDifference(DateTime &data){
    int val = calcInDays(this->year,this->month,this->day) - calcInDays(data.year,data.month,data.day);
    return abs(val);
}
