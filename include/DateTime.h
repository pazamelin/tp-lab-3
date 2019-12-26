
#ifndef _DATETIME_H
#define _DATETIME_H_
#include <iostream>

class DateTime
{
private:
	int day;
	int mon;
	int year;

public:
	DateTime(int  _day, int _mon,int _year);//конструктор с тремя числовыми параметрами(день, месяц, год);
	DateTime();//конструктор без параметров(объект использует текущую дату);
	DateTime(const DateTime& a);//конструктор копирования(создаём копию другого объекта);
	std::string getToday();// - возвращение текущей даты в виде строки, с указанием дня недели и названия месяца(например 07 november 2018, wedensday);
	std::string getYesterday();// - возвращение даты вчерашнего дня в виде строки.
	std::string getTomorrow(); //- возвращение даты завтрашнего дня в виде строки.
	std::string getFuture(unsigned int N); //- возвращение даты через N дней в будущем;
	std::string getPast(unsigned int N); //- возвращение даты через N дней в прошлом;
	int getDifference(DateTime&);// - для расчёта разницы(в днях) между двумя датами
};
#endif
