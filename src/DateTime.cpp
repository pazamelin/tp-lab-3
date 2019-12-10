#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>
#include <string>

using namespace std;


DateTime::DateTime()
{
	timer1 = time(NULL);
	u = localtime(&timer1);
}


DateTime::DateTime(DateTime& date)
{
	timer1 = date.timer1;
	u = localtime(&timer1);
}


DateTime::DateTime(int day, int month, int year)
{
	struct tm* u;
	u = localtime(&timer1);
	u->tm_mday = day;
	u->tm_mon = month - 1;
	u->tm_year = year - 1900;
	this->u = u;
	timer1 = mktime(u);
}


string DateTime::getToday()
{
	return getFuture(0);
}


string DateTime::getYesterday()
{
	return getPast(1);
}


string DateTime::getTomorrow()
{
	return getFuture(1);
}


string DateTime::getFuture(unsigned int N)
{
	time_t timer2 = timer1;
	struct tm* u = localtime(&timer2);
	char s[40];
	for (int i = 0; i < 40; i++) s[i] = 0;
	u->tm_mday += N;
	time_t timer3 = mktime(u);
	u = localtime(&timer3);
	strftime(s, 40, "%d.%m.%Y, %A", u);
	return string(s);
}


string DateTime::getPast(unsigned int N)
{
	time_t timer2 = timer1;
	struct tm* u = localtime(&timer2);
	char s[40];
	for (int i = 0; i < 40; i++) s[i] = 0;
	u->tm_mday -= N;
	time_t timer3 = mktime(u);
	u = localtime(&timer3);
	strftime(s, 40, "%d.%m.%Y, %A", u);
	return string(s);
}


int DateTime::getDifference(DateTime& date)
{
	double sec = difftime(this->timer1, date.timer1);
	int diff = sec / 86400;
	return abs(diff);
}

