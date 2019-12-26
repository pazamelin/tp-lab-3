#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year) 
{
	time(&timeInSec);
	timeStruct = localtime(&timeInSec);

	timeStruct->tm_year = year - 1900;
	timeStruct->tm_mon = month - 1;
	timeStruct->tm_mday = day;
	timeStruct->tm_sec = 0;
	timeStruct->tm_min = 0;
	timeStruct->tm_hour = 0;

	timeInSec = mktime(timeStruct);
	timeStruct = localtime(&timeInSec);
}

DateTime::DateTime() 
{
	time(&timeInSec);
	timeStruct = localtime(&timeInSec);
}

DateTime::DateTime(const DateTime &_time) 
{
	timeInSec = _time.timeInSec;
	timeStruct = localtime(&timeInSec);
}

string DateTime::getToday()
{
	return dayStr(timeStruct);
}

string DateTime::getYesterday() 
{
	time_t yestSec = timeInSec - 24 * 60 * 60;
	tm* yesterday = localtime(&yestSec);
	return dayStr(yesterday);
}

string DateTime::getTomorrow()
{
	time_t tomSec = timeInSec + 24 * 60 * 60;
	tm* tomorrow = localtime(&tomSec);
	return dayStr(tomorrow);
}

string DateTime::getFuture(unsigned int N)
{
	time_t futSec = timeInSec + N * 24 * 60 * 60;
	tm* futureDay = localtime(&futSec);
	return dayStr(futureDay);
}

string DateTime::getPast(unsigned int N)
{
	time_t pastSec = timeInSec - N * 24 * 60 * 60;
	tm* pastDay = localtime(&pastSec);
	return dayStr(pastDay);
}

int DateTime::getDifference(DateTime &_time) 
{
	unsigned int diff = abs(this->timeInSec - _time.timeInSec);
	return (diff / (60 * 60 * 24));
}

string DateTime::dayStr(tm* _time) 
{
	string result;

	if (_time->tm_mday < 10)
		result += "0";

	result += to_string(_time->tm_mday) + " " + months[_time->tm_mon] + " " + to_string(_time->tm_year + 1900) + ", " + weekdays[_time->tm_wday];
	return result;
}