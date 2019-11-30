#include "DateTime.h"
#include <string>
#include <stdio.h>


DateTime::DateTime(int D, int M, int Y)
{
	time(&now);  
	t = localtime(&now);  

	t->tm_year = Y - 1900;
	t->tm_mon = M - 1;
	t->tm_mday = D;

	//now = mktime(t);  
	//t = localtime(&now);
}

DateTime::DateTime()
{
	time(&now);
	t = localtime(&now);
}

DateTime::DateTime(DateTime& from)
{
	now = from.now;
	t = localtime(&now);
}

DateTime::~DateTime()
{
}

std::string DateTime::getToday()
{
	return timeToStr(t);
}

std::string DateTime::getYesterday()
{
	time_t temp = now - 24 * 3600;
	tm* yesterday = localtime(&temp);
	return timeToStr(yesterday);
}

std::string DateTime::getTomorrow()
{
	time_t temp = now + 24 * 3600;
	tm* tomorrow = localtime(&temp);
	return timeToStr(tomorrow);
}

std::string DateTime::getFuture(unsigned int N)
{
	time_t tmp = now + N * 24 * 3600;
	tm* future = localtime(&tmp);
	return timeToStr(future);
}

std::string DateTime::getPast(unsigned int N)
{
	time_t tmp = now - N * 24 * 3600;
	tm* past = localtime(&tmp);
	return timeToStr(past);
}

int DateTime::getDifference(DateTime& ref)
{
	unsigned long long diff = abs(ref.now - now);
	return diff / (3600 * 24);
}

std::string DateTime::timeToStr(tm* time)
{
	std::string s;
	if (time->tm_mday < 10)
	{
		s += "0";
	}
	s += std::to_string(time->tm_mday) + " " + months[time->tm_mon] + " " + std::to_string(time->tm_year + 1900) + ", " + days[time->tm_wday];
	return s;
}
