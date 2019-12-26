#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"
#include <string>
#include <ctime>

using namespace std;

string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "septeber", "october", "november", "december" };
string week[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

DateTime::DateTime()
{
	time_t seconds = time(NULL);
	date = *localtime(&seconds);
}

DateTime::DateTime(int day, int month, int year)
{
	time_t seconds = time(NULL);
	date = *localtime(&seconds);
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);
}


DateTime::DateTime(DateTime & copy)
{
	this->date = copy.date;
}

string DateTime::answer(struct tm & newdate) {
	string ans = "";
	if (newdate.tm_mday < 10) {
		ans += "0";
	}
	ans += to_string(newdate.tm_mday) + " " 
		+ months[newdate.tm_mon] + " " 
		+ to_string(newdate.tm_year + 1900) + ", " 
		+ week[newdate.tm_wday];
	return ans;
}

string DateTime::getToday()
{
	return answer(date);
}

string DateTime::getFuture(unsigned int N)
{
	string future;
	int days = date.tm_mday + N;
	int mon = date.tm_mon;
	int year = date.tm_year;
	while (days > daysInMonth[mon])
	{
		days -= daysInMonth[mon];
		mon++;
		if (mon == 12)
		{
			mon = 0;
			year++;
		}
	}
	time_t seconds = time(NULL);
	tm newdate = *localtime(&seconds);
	newdate.tm_mday = days;
	newdate.tm_mon = mon;
	newdate.tm_year = year;
	mktime(&newdate);
	return answer(newdate);
}

string DateTime::getPast(unsigned int N)
{
	string past;
	int days = date.tm_mday - N;
	int mon = date.tm_mon;
	int year = date.tm_year;
	while (days <= 0)
	{
		days += daysInMonth[mon - 1];
		mon--;
		if (mon == -1)
		{
			mon = 11;
			year--;
		}
	}
	time_t seconds = time(NULL);	
	tm newdate = *localtime(&seconds);
	newdate.tm_mday = days;
	newdate.tm_mon = mon;
	newdate.tm_year = year;
	mktime(&newdate);
	return answer(newdate);
}

string DateTime::getTomorrow()
{
	return getFuture(1);
}

string DateTime::getYesterday() 
{
	return getPast(1);
}

unsigned int DateTime::getDifference(DateTime & newdate)
{
	return abs(mktime(&(this->date)) - mktime(&newdate.date)) / 86400;
}
