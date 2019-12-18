#include "DateTime.h"
#include <ctime>

DateTime::DateTime(int day, int month, int year){ // конструктор с тремя числовыми параметрами (день, месяц,год);
    time(&now);
    timeStructure = localtime(&now);
    timeStructure->tm_year = year - 1900;
    timeStructure->tm_mon = month - 1;
    timeStructure->tm_mday = day;
    timeStructure->tm_hour = 0;
    timeStructure->tm_min = 0;
    timeStructure->tm_sec = 0;
    now = mktime(timeStructure);
    timeStructure = localtime(&now);
}
DateTime::DateTime(){ // конструктор без параметров (объект использует текущую дату);
    time(&now);
    timeStructure = localtime(&now);
}
DateTime::DateTime(DateTime &data){// конструктор копирования (создаём копию другого объекта);
    now = data.now;
    timeStructure = data.timeStructure;
}
std::string DateTime::getFuture(unsigned int N){ // getFuture(unsigned int N) - возвращение даты через N дней в будущем;
    time_t temp = now + N * 24 * 3600; //к текущему времени в секундах + количество будущих секунд
    tm* future = localtime(&temp);
    return date_to_string(future);
}
std::string DateTime::getToday(){ // getToday() - возвращение текущей даты в виде строки, с указанием дня недели и названия месяца (например 07 november 2018, wedensday);
    return date_to_string(timeStructure);
}
std::string DateTime::getYesterday(){ // getYesterday() - возвращение даты вчерашнего дня в виде строки.
    time_t temp = now - 24 * 3600;
    tm* future = localtime(&temp);
    return date_to_string(future);
}
std::string DateTime::getTomorrow(){  // getTomorrow() - возвращение даты завтрашнего дня в виде строки.
    time_t temp = now + 24 * 3600;
    tm* future = localtime(&temp);
    return date_to_string(future);
}
std::string DateTime::getPast(unsigned int N){ // getPast(unsigned int N) - возвращение даты через N дней в прошлом;
    time_t temp = now - N * 24 * 3600; 
    tm* future = localtime(&temp);
    return date_to_string(future);
}

int DateTime::getDifference(DateTime&data ){ // getDifference(DateTime&) - для расчёта разницы (в днях) между двумя дата
    return (int)(abs(data.now - (this->now))/ (3600 * 24));
}

std::string DateTime::date_to_string(tm* time){
    std::string s = "";
    if (time->tm_mday < 10) // если день от 1 до 9
        s += "0";
    s += std::to_string(time->tm_mday) + " " + months[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + days[time->tm_wday];
    return s;
}
