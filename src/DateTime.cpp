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
	time_t currentTime = time(nullptr);
	tm *localTime = localtime(&currentTime);
	this->day = (int8_t)localTime->tm_mday;
	this->month = 1 + (int8_t)localTime->tm_mon;
	this->year = 1900 + localTime->tm_year;
};

std::string DateTime::getToday() const
{
	tm localTime = { 0, 0, 0, this->day, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getYesterday() const
{
	tm localTime = { 0, 0, 0, this->day - 1, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getTomorrow() const
{
	tm localTime = { 0, 0, 0, this->day + 1, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getFuture(uint32_t n) const
{
	tm localTime = { 0, 0, 0, this->day + n, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
std::string DateTime::getPast(uint32_t n) const
{
	tm localTime = { 0, 0, 0, this->day - n, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime.tm_mday, localTime.tm_mon + 1, localTime.tm_year + 1900, localTime.tm_wday + 1);
};
int32_t DateTime::getDifference(DateTime &dateTime) const
{
	tm localTime = { 0, 0, 0, this->day, this->month - 1, this->year - 1900, 0, 0, 0 };
	tm localTimeToSubtract = { 0, 0, 0, dateTime.day, dateTime.month - 1, dateTime.year - 1900, 0, 0, 0 };
	int days = 0;
	if (mktime(&localTime) > mktime(&localTimeToSubtract))
	{
		time_t difference = mktime(&localTime) - mktime(&localTimeToSubtract);
		tm *difference2 = localtime(&difference);
		days = difference2->tm_yday;
	}
	else
	{
		time_t difference = mktime(&localTimeToSubtract) - mktime(&localTime);
		tm *difference2 = localtime(&difference);
		days = difference2->tm_yday;
	}
	return days;
};
