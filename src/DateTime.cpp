#define _CRT_SECURE_NO_WARNINGS

#include "DateTime.h"

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year)
{
	time(&now);  //the current calendar time of the system in number of seconds elapsed since January 1, 1970.
	t = localtime(&now);  //a pointer to the tm structure representing local time
	t->tm_year = year - 1900;
	t->tm_mon = month - 1;
	t->tm_mday = day;
	t->tm_hour = 0;
	t->tm_min = 0;
	t->tm_sec = 0;
	now = mktime(t);  //the calendar-time equivalent of the time found in the structure pointed to by time
	t = localtime(&now);
}

DateTime::DateTime()
{
	time(&now);  //current time
	t = localtime(&now);
}


DateTime::DateTime(const DateTime &time)
{
	now = time.now;
	t = time.t;
}

string DateTime::getToday()
{
	return getStr(t);
}

string DateTime::getYesterday()
{
	time_t yesterday_sec = now - 24 * 3600;
	tm* yesterday = localtime(&yesterday_sec);
	return getStr(yesterday);
}

string DateTime::getTomorrow()
{
	time_t tommorow_sec = now + 24 * 3600;
	tm* tomorrow = localtime(&tommorow_sec);
	return getStr(tomorrow);
}

string DateTime::getFuture(unsigned int N)
{
	time_t future_sec = now + N * 3600 * 24;
	tm* future = localtime(&future_sec);
	return getStr(future);
}

string DateTime::getPast(unsigned int N)
{
	time_t past_sec = now - N * 3600 * 24;
	tm* past = localtime(&past_sec);
	return getStr(past);
}

int DateTime::getDifference(DateTime &time)
{
	int diff = abs(time.now - (this->now));
	return diff / (3600 * 24);
}

string DateTime::getStr(tm* time)
{
	string s;
	if (time->tm_mday < 10)
	{
		s += "0";
	}
	s += to_string(time->tm_mday) + " " + month[time->tm_mon] + " " + to_string(time->tm_year + 1900) + ", " + weekday[time->tm_wday];
	return s;
}