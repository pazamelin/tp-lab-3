//
// Created by Mary on 04.11.2019.
//

#ifndef TASK1_DATETIME_H
#define TASK1_DATETIME_H
#include <string>
#include <ctime>
#include <vector>
using namespace std;
class DateTime {
private:
    unsigned int day;
    unsigned int month;
    unsigned int year;
    const vector<std::string> daysInWeek{"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    const vector<std::string> months{"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
public:
    DateTime(unsigned int, unsigned int, unsigned int);  //конструктор с тремя числовыми параметрами (день, месяц,год);
    DateTime();  // конструктор без параметров (объект использует текущую дату);
    DateTime(const DateTime &);  //конструктор копирования (создаём копию другого объекта);
    string getToday();  //  возвращение текущей даты в виде строки, с указанием дня недели и названия месяца (например 07 november 2018, wedensday);
    string getYesterday();  // возвращение даты вчерашнего дня в виде строки
    string getTomorrow();  // возвращение даты завтрашнего дня в виде строки.
    string getFuture(unsigned int n);  // возвращение даты через N дней в будущем;
    string getPast(unsigned int n);  // возвращение даты через N дней в прошлом;
    int calcDifference(DateTime&);  // для расчёта разницы (в днях) между двумя датами
    int getDifference(DateTime&);  // для расчёта разницы (в днях) между двумя датами
    string getString(int, int, int); //преобразование даты в строку

    const unsigned int getDay();
    const unsigned int getMonth();
    const unsigned int getYear();


};



#endif //TASK1_DATETIME_H
