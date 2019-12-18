#ifndef DateTime_h
#define DateTime_h

#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>

class DateTime{
private:
    time_t now; //текущее время в секундах
    tm* timeStructure; //время по канону
    const std::vector<std::string> days = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
    const std::vector<std::string> months = { "january","february","march","april","may","june","july","august",
        "september","october","november","december" };
    std::string date_to_string(tm* time); //перевод в канонное состояние
public:
    DateTime(int day, int month, int year);
    DateTime();
    DateTime(DateTime&);
    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int N);
    std::string getPast(unsigned int N);
    int getDifference(DateTime&);
};
#endif /* DateTime_h */
