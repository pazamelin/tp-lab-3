//
// Created by aklen on 10.11.2019.
//
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class DateTime{

public:
    DateTime(unsigned int ,unsigned int, unsigned int);//конструктор(день, месяц, год)
    DateTime();//конструктор, использует текущую дату
    DateTime(const DateTime&);//создает копию другого объекта

    string getToday();//дата текущего дня в виде строки
    string getYesterday();//дата предидущего дня
    string getTomorrow();//дата завтрашнего дня
    string getFuture(unsigned int N);//дата N дней в будущем
    string getPast(unsigned int N);//дата N дней назад
    string getString(int day, int month, int year);//преобразование даты в строку
    int getDifference(DateTime&);//расчитывает разницу в днях между 2мя датами

private:
    unsigned int day,month,year;
    static string weekDays[7];
    static string months[12];
};