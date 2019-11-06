//
// Created by fiskirton on 11/5/19.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H

#include <ctime>
#include <cstring>

class DateTime{

private:

     tm * date = new tm;
public:

    DateTime(){
        time_t timer = time(nullptr);
        date = localtime(& timer);
    }

    DateTime(int d, int m, int y){
        time_t tmp = time(nullptr);
        date = new tm;
        memcpy(date, localtime(&tmp), sizeof(tm));
        date->tm_mday = d ;
        date->tm_mon = m - 1;
        date->tm_year = y - 1900;
        mktime(date);
    }

    DateTime(const DateTime & obj){
        date = new tm;
        memcpy(date, obj.date, sizeof(tm));
    }

    ~DateTime() = default;

    tm * getDate(){ return this->date;}

    char * getToday();
    char * getYesterday();
    char * getTomorrow();
    char * getFuture(unsigned int N);
    char * getPast(unsigned int N);
    int getDifference(DateTime&);
};

char * dateToString(DateTime *);
char * toLowerCase(char *);
#endif //TASK1_DATETIME_H

// secs = N*