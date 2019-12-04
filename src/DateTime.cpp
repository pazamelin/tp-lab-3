#include "DateTime.h"
#include <string>
#include <stdio.h>


DateTime::DateTime(int day, int month, int year)
{
	time(&time_seconds);  
	time_structure = localtime(&time_seconds);  

	time_structure->tm_year = year - 1900;
	time_structure->tm_mon = month - 1;
	time_structure->tm_mday = day;

	time_seconds = mktime(time_structure);
	time_structure = localtime(&time_seconds);
}

DateTime::DateTime()
{
	time(&time_seconds);
	time_structure = localtime(&time_seconds);
}

DateTime::DateTime(DateTime& from)
{
	time_seconds = from.time_seconds;
	time_structure = localtime(&time_seconds);
}

DateTime::~DateTime()
{
}

std::string DateTime::getToday()
{
	return timeToStr(time_structure);
}

std::string DateTime::getYesterday()
{
	time_t temp = time_seconds - 24 * 3600;
	tm* yesterday = localtime(&temp);
	return timeToStr(yesterday);
}

std::string DateTime::getTomorrow()
{
	time_t temp = time_seconds + 24 * 3600;
	tm* tomorrow = localtime(&temp);
	return timeToStr(tomorrow);
}

std::string DateTime::getFuture(unsigned int N)
{
	time_t temp = time_seconds + N * 24 * 3600;
	tm* future = localtime(&temp);
	return timeToStr(future);
}

std::string DateTime::getPast(unsigned int N)
{
	time_t temp = time_seconds - N * 24 * 3600;
	tm* past = localtime(&temp);
	return timeToStr(past);
}

int DateTime::getDifference(DateTime& target)
{
	unsigned long long diff = abs(target.time_seconds - time_seconds);
	return diff / (3600 * 24);
}

std::string DateTime::timeToStr(tm* time)
{
	std::string result;
	if (time->tm_mday < 10)
	{
		result += "0";
	}
	result += std::to_string(time->tm_mday) + " " + months[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + days[time->tm_wday];
	return result;
}
