//
// Created by fiskirton on 11/5/19.
//

#include <cctype>
#include "DateTime.h"

char * DateTime::getToday(){
    return dateToString(this);
}

char * DateTime::getYesterday() {
    return this->getPast(1);
}

char * DateTime::getTomorrow(){
    return this->getFuture(1);
}

char * DateTime::getFuture(unsigned int N) {
    auto * future_date = new DateTime(*this);
    future_date->getDate()->tm_mday += (int)N;
    mktime(future_date->getDate());
    return dateToString(future_date);
}

char * DateTime::getPast(unsigned int N){
    auto * future_date = new DateTime(*this);
    future_date->getDate()->tm_mday -= (int)N;
    mktime(future_date->getDate());
    return dateToString(future_date);
}

int DateTime::getDifference(DateTime & second_date) {
    time_t ld = mktime(this->getDate());
    time_t rd = mktime(second_date.getDate());
    time_t diff = (ld > rd)?ld - rd:rd - ld;
    int diff_days = (int)diff / 86400;
    return diff_days;
}

char * dateToString(DateTime * date){
    auto * buf = new char[40];
    strftime(buf, 40, "%d %B %Y, %A", date->getDate());
    return toLowerCase(buf);
}

char * toLowerCase(char * str){
    int i = 0;
    while (str[i]){
        str[i] = (char)tolower(str[i]);
        i++;
    }
    return str;
}


