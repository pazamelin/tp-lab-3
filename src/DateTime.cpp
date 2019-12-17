#include "DateTime.h"

DateTime::DateTime()
{
    timer = time(NULL);
    _time = localtime(&timer);
}
DateTime::DateTime(int d, int m, int y)
{
    timer = time(NULL);
    _time = localtime(&timer);
    _time->tm_year = y - 1900;
    _time->tm_mon = m - 1;
    _time->tm_mday = d;
    timer = mktime(_time);

}
DateTime::DateTime (const DateTime &newval)
{
    timer = newval.timer;
    _time = newval._time;
}

std::string DateTime::date_to_string(tm *_time)
{
    std::string result_string ="";
    if ((_time->tm_mday) < 10)
        result_string += "0" + std::to_string(_time->tm_mday);
    else
        result_string += std::to_string(_time->tm_mday);
    result_string += " " + months[_time->tm_mon] + " " + std::to_string(1900+_time->tm_year) + ", " + week[_time->tm_wday];
    return result_string;
}

std::string DateTime::getToday()
{
    _time = localtime(&timer);
    std::string today_date = date_to_string(_time);
    return today_date;
}

std::string DateTime::getFuture(unsigned int N)
{
    time_t delta_time = timer + (dayT * N);
    tm *future_day = localtime(&delta_time);
    std::string future_date = date_to_string(future_day);
    _time = localtime(&timer);
    return future_date;
}
std::string DateTime::getPast(unsigned int N)
{
    time_t delta_time = timer - (dayT * N);
    tm *past_day = localtime(&delta_time);
    std::string past_date = date_to_string(past_day);
    _time = localtime(&timer);
    return past_date;
}

std::string DateTime::getYesterday()
{
    return getPast(1);
}
std::string DateTime::getTomorrow()
{
    return getFuture(1);
}

int DateTime::getDifference(DateTime& comparising_day)
{
    long dayT1 = timer;
    long dayT2 = comparising_day.timer;
    return int(abs(dayT1 - dayT2) / dayT);
}
