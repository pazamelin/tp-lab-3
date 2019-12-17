#ifndef DateTime_h
#define DateTime_h

#include <string>
#include <ctime>
#include <iostream>
#include <vector>

class DateTime
{
private:
    time_t timer;
    tm* _time;

    std::string date_to_string(tm* _time);
public:
    time_t dayT = 86400;
    std::vector<std::string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    std::vector<std::string> week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    DateTime(int d, int m, int y);
    DateTime();
    DateTime(DateTime const&);
    
    std::string getToday();
    std::string getYesterday();
    std::string getTomorrow();
    std::string getFuture(unsigned int N);
    std::string getPast(unsigned int N);
    int getDifference(DateTime&);
};

std::string nameOfMonth(int m);

#endif 
