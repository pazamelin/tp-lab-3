#include <ctime>
#include <string>
#include <vector>

#ifndef DATETIME_H
#define DATETIME_H
class DateTime {
	struct tm dt;
	static std::string week_days[];
	static std::string months[12];
public:
	//~DateTime();
	DateTime(int day, int month, int year);
	DateTime();
	DateTime(const DateTime &origin);
	std::string getToday()const; // возвращение текущей даты в виде строки, с указанием дня недели и названия месяца(например 07 november 2018, wednesday)
	std::string getYesterday()const; // -возвращение даты вчерашнего дня в виде строк.
	std::string getTomorrow()const; // -возвращение даты завтрашнего дня в виде строки
	std::string getFuture(unsigned int n)const; // -возвращение даты через N дней в будущем
	std::string getPast(unsigned int n)const; // - возвращение даты через N дней в прошлом
	int getDifference(DateTime& target); // - для расчёта разницы(в днях) между двумя датами
};
#endif