#ifndef DATETIME_H
#define DATETIME_H
#include <string>
using namespace std;
class DateTime
{
    private:
        unsigned int day, month, year;
        static string weekdays[7];
        static string months[12];
    public:
        DateTime();
        DateTime(int data_day, int data_month, int data_year);
        DateTime(DateTime &data);

        string shiftFromTodayAt(int power);
        string getToday();
        string getTomorrow();
        string getYesterday();
        string getFuture(int val);
        string getPast(int val);
        int calcInDays(int y, int m, int d);
        int getDifference(DateTime &data);
};

#endif
