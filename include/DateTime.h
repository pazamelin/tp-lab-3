#include <ctime>
#include <string>

#ifndef DATETIME_H
#define DATETIME_H
class DateTime {
	struct tm* dt;
public:
	DateTime(int day, int month, int year);
	DateTime();
	DateTime(const DateTime &origin);
	std::string getToday(); // возвращение текущей даты в виде строки, с указанием дня недели и названия месяца(например 07 november 2018, wednesday)
	std::string getYesterday(); // -возвращение даты вчерашнего дня в виде строк.
	std::string getTomorrow(); // -возвращение даты завтрашнего дня в виде строки
	std::string getFuture(unsigned int n); // -возвращение даты через N дней в будущем
	std::string getPast(unsigned int n); // - возвращение даты через N дней в прошлом
	int getDifference(DateTime& target); // - для расчёта разницы(в днях) между двумя датами
};
#endif