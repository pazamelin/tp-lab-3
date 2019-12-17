#ifndef TPLAB3TASK1_DATETIME_H
#define TPLAB3TASK1_DATETIME_H

#include <string>
#include <ctime>

using namespace std;

class DateTime {
public:
    DateTime(unsigned int day, unsigned int month,
             unsigned int year);  //конструктор с тремя числовыми параметрами (день, месяц,год);
    DateTime(); //конструктор без параметров (объект использует текущую дату);
    DateTime(const DateTime &);  //конструктор копирования (создаём копию другого объекта);

    string getToday();

    string getYesterday();

    string getTomorrow();

    string getFuture(unsigned int N);   //возвращение даты через N дней в будущем
    string getPast(unsigned int N); //возвращение даты через N дней в прошлом
    int getDifference(DateTime &);   //для расчёта разницы (в днях) между двумя датами

private:
    struct tm* currentTime;
    string weekday[7] = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    string months[12]={"january", "february", "march", "april", "may", "june","july", "august", "september", "october", "november", "december" };

};

#endif //TPLAB3TASK1_DATETIME_H
