#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

std::string DateTime::week_days[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
std::string DateTime::months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };;

//DateTime::~DateTime()
//{
//	delete dt;
//}

DateTime::DateTime(int d, int m, int y)
{
	dt.tm_mday = d;
	dt.tm_mon = m - 1;
	dt.tm_year = y - 1900;
	dt.tm_sec = 0;
	dt.tm_min = 0;
	dt.tm_hour = 0;
	mktime(&dt);
}

DateTime::DateTime()
{
	time_t tmp = time(nullptr);
	dt = *(localtime(&tmp));
}

DateTime::DateTime(const DateTime &origin)
{
	memcpy(&dt, &(origin.dt), sizeof(tm));
}

std::string DateTime::getToday() const
{
	std::string day = "";
	if (dt.tm_mday < 10) day += "0";
	day += std::to_string(dt.tm_mday);
	return (day + ' ' + months[dt.tm_mon] + ' ' + std::to_string(dt.tm_year + 1900) + ", " + week_days[dt.tm_wday]);
}

std::string DateTime::getYesterday() const
{
	return this->getPast(1);
}

std::string DateTime::getTomorrow() const
{
	return this->getFuture(1);
}

std::string DateTime::getFuture(unsigned int n) const
{
	return DateTime(dt.tm_mday + n, dt.tm_mon + 1, dt.tm_year + 1900).getToday();
}

std::string DateTime::getPast(unsigned int n) const
{
	return DateTime(dt.tm_mday - n, dt.tm_mon + 1, dt.tm_year + 1900).getToday();
}

int DateTime::getDifference(DateTime& target) 
{
	return abs(mktime(&(this->dt)) - mktime(&(target.dt))) / 86400; // количество секунд в сутках
}