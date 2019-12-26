#include <cstdlib>
#include <ctime>
#include "DateTime.h"

std::string DateTime::months[12] =
{
	"january",
	"february",
	"march",
	"april",
	"may",
	"june",
	"jule",
	"august",
	"september",
	"october",
	"november",
	"december"
};
std::string DateTime::daysOfWeek[7] =
{
	"sunday",
	"monday",
	"tuesday",
	"wednesday",
	"thursday",
	"friday",
	"saturday"
};

std::string DateTime::formatString(int8_t day, int8_t month, int32_t year, int8_t dayOfWeek) const
{
	std::string result = "";
	result += (day >= 10 ? std::to_string(day) : "0" + std::to_string(day)) + " ";
	result += DateTime::months[month - 1] + " ";
	result += std::to_string(year) + ", ";
	result += DateTime::daysOfWeek[dayOfWeek - 1];
	return result;
};
tm DateTime::getLocalTime(int8_t day, int8_t month, int32_t year) const
{
	tm time = { 0, 0, 0, day, month - 1, year - 1900, 0, 0, 0 };
	time_t seconds = mktime(&time);
	return *localtime(&seconds);
};

DateTime::DateTime(int day, int month, int year)
{
	this->day = (int8_t)day;
	this->month = (int8_t)month;
	this->year = year;
};
DateTime::DateTime(const DateTime &dateTime)
{
	this->day = dateTime.day;
	this->month = dateTime.month;
	this->year = dateTime.year;
};
DateTime::DateTime()
{
	time_t seconds = time(nullptr);
	tm *localTime = localtime(&seconds);
	this->day = (int8_t)localTime->tm_mday;
	this->month = 1 + (int8_t)localTime->tm_mon;
	this->year = 1900 + localTime->tm_year;
};

std::string DateTime::getToday() const
{
	tm localTime = getLocalTime(this->day, this->month, this->year);
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getYesterday() const
{
	tm localTime = getLocalTime(this->day - 1, this->month, this->year);
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getTomorrow() const
{
	tm localTime = getLocalTime(this->day + 1, this->month, this->year);
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getFuture(uint32_t n) const
{
	tm localTime = getLocalTime(this->day + (int32_t)n, this->month, this->year);
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getPast(uint32_t n) const
{
	tm localTime = getLocalTime(this->day - (int32_t)n, this->month, this->year);
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
int32_t DateTime::getDifference(DateTime &dateTime) const
{
	tm localTime = { 0, 0, 0, this->day, this->month - 1, this->year - 1900, 0, 0, 0 };
	tm localTimeToSubtract = { 0, 0, 0, dateTime.day, dateTime.month - 1, dateTime.year - 1900, 0, 0, 0 };
	time_t seconds = mktime(&localTime) - mktime(&localTimeToSubtract);
	if (seconds >= 0)
	{
		tm *difference = localtime(&seconds);
		return difference->tm_yday;
	}
	else
	{
		seconds *= -1;
		tm *difference = localtime(&seconds);
		return -difference->tm_yday;
	}
};
