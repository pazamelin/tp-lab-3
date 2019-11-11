#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <cstring>
#include <string>
#include <ctime>
#include <vector>

DateTime::DateTime(int d, int m, int y)
{
	time_t tmp = time(nullptr);
	dt = new tm;
	memcpy(dt, localtime(&tmp), sizeof(tm));
	dt->tm_mday = d;
	dt->tm_mon = m - 1;
	dt->tm_year = y - 1900;
	mktime(dt);
}

DateTime::DateTime()
{
	time_t tmp = time(nullptr);
	dt = localtime(&tmp);
}

DateTime::DateTime(const DateTime &origin)
{
	dt = new tm;
	memcpy(dt, origin.dt, sizeof(tm));
}

std::string DateTime::getToday()
{
	std::vector<std::string> week_days = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	std::vector<std::string> months= { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	std::string day = "";
	if (dt->tm_mday < 10) day += "0";
	day += std::to_string(dt->tm_mday);
	return (day + ' ' +	months[dt->tm_mon] + ' ' + std::to_string(dt->tm_year + 1900) + ", " + week_days[dt->tm_wday]);
}

std::string DateTime::getYesterday()
{
	return this->getPast(1);
}

std::string DateTime::getTomorrow()
{
	return this->getFuture(1);
}

std::string DateTime::getFuture(unsigned int n)
{
	return DateTime(dt->tm_mday + n, dt->tm_mon + 1, dt->tm_year + 1900).getToday();
}

std::string DateTime::getPast(unsigned int n)
{
	return DateTime(dt->tm_mday - n, dt->tm_mon + 1, dt->tm_year + 1900).getToday();
}

int DateTime::getDifference(DateTime& target)
{
	return abs((mktime(this->dt) - mktime(target.dt))) / 86400; // количество секунд в сутках
}