#include "DateTime.h"

std::string DateTime::_makeStr(tm *_time) {
    std::string res="";
    if ((_time->tm_mday) / 10 == 0)
        res += "0" + std::to_string(_time->tm_mday);
    else
        res += std::to_string(_time->tm_mday);
    res+= " " + months[_time->tm_mon] + " " + std::to_string(1900+_time->tm_year) + ", " + week[_time->tm_wday];
    return res;
}

DateTime::DateTime() {
    timer = time(NULL);
    _time = localtime(&timer);
}
DateTime::DateTime(int d, int m, int y) {

    timer = time(NULL);
    _time = localtime(&timer);
    _time->tm_year = y - 1900;
    _time->tm_mon = m - 1;
    _time->tm_mday = d;
    timer =  mktime(_time);

}

std::string DateTime::getToday() {
    _time = localtime(&timer);
    std::string res=_makeStr(_time);
    return res;
}
std::string DateTime::getYesterday() {
    time_t smth = timer - dayT;
    tm *new_time = localtime(&smth);
    std::string res = _makeStr(new_time);
    _time = localtime(&timer);

    return res;
}

std::string DateTime::getTomorrow() {
    time_t smth = timer + dayT;
    tm *new_time=localtime(&smth);
    std::string res=_makeStr(new_time);
    _time = localtime(&timer);
    return res;
}
std::string DateTime::getFuture(unsigned int N) {
    time_t smth = timer + (N * dayT);
    tm *new_time=localtime(&smth);
    std::string res=_makeStr(new_time);
    _time = localtime(&timer);
    return res;
}
std::string DateTime::getPast(unsigned int N) {
    time_t smth = timer - (N * dayT);
    tm *new_time=localtime(&smth);
    std::string res=_makeStr(new_time);
    _time = localtime(&timer);
    return res;
}
int DateTime::getDifference(DateTime& day2) {
    int dayT1 = timer;
    int dayT2 = day2.timer;
    return abs(dayT1 - dayT2) / dayT;
}
