#include "DateTime.h"
#include <cstring>
#include <ctime>

string getYesterday();

string getTomorrow();

string getFuture(unsigned int N);

string getPast(unsigned int N);

string getDifference(DateTime &);


DateTime::DateTime(unsigned int currentDay, unsigned int currentMonth, unsigned int currentYear)
{
    time_t tmp = time(nullptr);
    currentTime = new tm;
    memcpy(currentTime, localtime(&tmp), sizeof(tm));
    currentTime->tm_mday = currentDay;
    currentTime->tm_mon = currentMonth - 1;
    currentTime->tm_year = currentYear - 1900;
    mktime(currentTime);    //weekday
}

DateTime::DateTime()
{
    time_t rawtime = time(nullptr); //текущая дата в секундах
    currentTime = localtime(&rawtime);// преобразовывает текущее значение времени в структуру tm
}

DateTime::DateTime(const DateTime &obj)
{
    currentTime = new tm;
    memcpy(currentTime, obj.currentTime, sizeof(tm));
}

string DateTime::getToday()
{
    string day;
    if (currentTime->tm_mday < 10) {
        day = "0";
    }
    day += to_string(currentTime->tm_mday);
    return (day + string(" ") + months[currentTime->tm_mon] + string(" ") + to_string(currentTime->tm_year + 1900) +
            string(",") + string(" ") + weekday[currentTime->tm_wday]);
}

string DateTime::getYesterday()
{
    return this->getPast(1);
}

string DateTime::getTomorrow()
{
    return this->getFuture(1);
}

string DateTime::getPast(unsigned int n)
{
    DateTime past = DateTime(currentTime->tm_mday - n, currentTime->tm_mon + 1, currentTime->tm_year + 1900);
    return past.getToday();
}

string DateTime::getFuture(unsigned int n)
{
    DateTime past = DateTime(currentTime->tm_mday + n, currentTime->tm_mon + 1, currentTime->tm_year + 1900);
    return past.getToday();
}

int DateTime::getDifference(DateTime & dt)
{
    return abs((mktime(this->currentTime) - mktime(dt.currentTime))) / (60 * 60 * 24);
}