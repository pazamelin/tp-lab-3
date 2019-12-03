#pragma once
#include <ctime>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
class DateTime {
private:
	struct tm date;
public:
	DateTime(int day, int mounth, int year);
	DateTime();
	DateTime(DateTime &buf);
	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);
	int getDifference(DateTime &buf);

};