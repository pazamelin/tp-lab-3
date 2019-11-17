#define _CRT_SECURE_NO_WARNINGS

#include "DateTime.h"
#include <string>


#include <stdio.h>


DateTime::DateTime(unsigned int D, unsigned int M, unsigned int Y)
{
	time(&now);  
	t = localtime(&now);  

	t->tm_year = Y - 1900;
	t->tm_mon = M - 1;
	t->tm_mday = D;
	t->tm_hour = 0;
	t->tm_min = 0;
	t->tm_sec = 0;

	now = mktime(t);  
	t = localtime(&now);
}

DateTime::DateTime()
{
	time(&now);
	t = localtime(&now);
}

DateTime::DateTime(const DateTime& from)
{
	now = from.now;
	t = from.t;
}

DateTime::~DateTime()
{
}

std::string DateTime::getToday()
{
	return tmToStr(t);
}

std::string DateTime::getYesterday()
{
	time_t yesterday_secs = now - 24 * 3600;
	tm* yesterday = localtime(&yesterday_secs);
	return tmToStr(yesterday);
}

std::string DateTime::getTomorrow()
{
	time_t yesterday_secs = now + 24 * 3600;
	tm* yesterday = localtime(&yesterday_secs);
	return tmToStr(yesterday);
}

std::string DateTime::getFuture(unsigned int N)
{
	time_t yesterday_secs = now + N * 24 * 3600;
	tm* yesterday = localtime(&yesterday_secs);
	return tmToStr(yesterday);
}

std::string DateTime::getPast(unsigned int N)
{
	time_t yesterday_secs = now - N * 24 * 3600;
	tm* yesterday = localtime(&yesterday_secs);
	return tmToStr(yesterday);
}

int DateTime::getDifference(DateTime& ref)
{
	unsigned long long diff = abs(ref.now - (this->now));
	return diff / (3600 * 24); // This function should return ULL, but in task there is an int in prototype
}

std::string DateTime::tmToStr(tm* time)
{
	std::string s;
	if (time->tm_mday < 10)
	{
		s += "0";
	}
	s += std::to_string(time->tm_mday) + " " + mNumStr[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + wDayNumStr[time->tm_wday];
	return s;
}
