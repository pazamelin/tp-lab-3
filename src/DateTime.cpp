#include <cstdlib>
#include <ctime>
#include "DateTime.h"

std::string formatString(tm localTime)
{
	std::string result = "";
	result += localTime.tm_mday >= 10 ? std::to_string(localTime.tm_mday) : "0" + std::to_string(localTime.tm_mday);
	result += " ";
	switch (localTime.tm_mon + 1)
	{
		case 1:		result += "january";	break;
		case 2:		result += "february";	break;
		case 3:		result += "march";		break;
		case 4:		result += "april";		break;
		case 5:		result += "may";		break;
		case 6:		result += "june";		break;
		case 7:		result += "jule";		break;
		case 8:		result += "august";		break;
		case 9:		result += "september";	break;
		case 10:	result += "october";	break;
		case 11:	result += "november";	break;
		case 12:	result += "december";	break;
		default:							break;
	}
	result += " ";
	result += std::to_string(localTime.tm_year + 1900);
	result += ", ";
	switch (localTime.tm_wday + 1)
	{
		case 1:	result += "sunday";		break;
		case 2:	result += "monday";		break;
		case 3:	result += "tuesday";	break;
		case 4:	result += "wednesday";	break;
		case 5:	result += "thursday";	break;
		case 6:	result += "friday";		break;
		case 7:	result += "saturday";	break;
	}
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
	return formatString(localTime);
};
std::string DateTime::getYesterday() const
{
	tm localTime = { 0, 0, 0, this->day - 1, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime);
};
std::string DateTime::getTomorrow() const
{
	tm localTime = { 0, 0, 0, this->day + 1, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime);
};
std::string DateTime::getFuture(uint32_t n) const
{
	tm localTime = { 0, 0, 0, this->day + n, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime);
};
std::string DateTime::getPast(uint32_t n) const
{
	tm localTime = { 0, 0, 0, this->day - n, this->month - 1, this->year - 1900, 0, 0, 0 };
	time_t currentTime = mktime(&localTime);
	tm *tmpLocalTime = localtime(&currentTime);
	localTime = *tmpLocalTime;
	return formatString(localTime);
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
