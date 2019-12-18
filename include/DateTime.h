#ifndef DateTime_h
#define DateTime_h

#include <stdio.h>
#include <string>
#include <vector>
#include <ctime>

// Разработать класс DateTime для работы с датой/временем.

// В качестве основы взять функции и структуры для работы с временем из стандартной библиотеки (struct tm, time, localtime, mktime)

// Добавить в класс DateTime следующие методы:

// конструктор с тремя числовыми параметрами (день, месяц,год);
// конструктор без параметров (объект использует текущую дату);
// конструктор копирования (создаём копию другого объекта);
// getToday() - возвращение текущей даты в виде строки, с указанием дня недели и названия месяца (например 07 november 2018, wedensday);
// getYesterday() - возвращение даты вчерашнего дня в виде строки.
// getTomorrow() - возвращение даты завтрашнего дня в виде строки.
// getFuture(unsigned int N) - возвращение даты через N дней в будущем;
// getPast(unsigned int N) - возвращение даты через N дней в прошлом;
// getDifference(DateTime&) - для расчёта разницы (в днях) между двумя датами
// Для работы со строками используется тип std::string

class DateTime{
private:
    time_t now; //текущее время в секундах
    tm* timeStructure; //время по канону
    static const std::vector<std::string> days = {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
    static const std::vector<std::string> months = { "january","february","march","april","may","june","july","august",
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
