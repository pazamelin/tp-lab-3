#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"
#include <string>
#include <vector>
#include <ctime>

using namespace std;

vector<string> months = { "january", "february", "march", "april", "may", "june", "july", "august", "septeber", "october", "november", "december" };
vector<string> weeks = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
vector<int> daysInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

string DateTime::timetostr(const tm& time)
{
	string result = string();
	if (time.tm_mday < 10)
		result += "0";
	result+=to_string(time.tm_mday);
	result += " " + months[time.tm_mon] + " " + to_string(time.tm_year + 1900) + ", " + weeks[time.tm_wday];
	return result;
}

DateTime::DateTime(int day, int month, int year)
{
	time_t curtime = time(NULL);
	date = *localtime(&curtime);
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);
}

DateTime::DateTime()
{
	time_t curtime = time(NULL);
	date = *localtime(&curtime);	
}


DateTime::DateTime(const DateTime& copy)
{
	this->date = copy.date;
}

string DateTime::getToday()
{
	return timetostr(date);
}

string DateTime::getFuture(unsigned int N)
{
	tm bufDate = date;
	bufDate.tm_mday += N;
	time_t bufDate_seconds = mktime(&bufDate);
    bufDate = *localtime(&bufDate_seconds);
	return timetostr(bufDate);
}

string DateTime::getPast(unsigned int N)
{
	tm bufDate = date;
	bufDate.tm_mday -= N;
	time_t bufDate_seconds = mktime(&bufDate);
	bufDate = *localtime(&bufDate_seconds);
	return timetostr(bufDate);
}

string DateTime::getTomorrow()
{
	return getFuture(1);
}

string DateTime::getYesterday()
{
	return getPast(1);
}

unsigned int DateTime::getDifference(DateTime& newdate)
{
	return abs(mktime(&(this->date)) - mktime(&newdate.date)) / (24*60*60);
}