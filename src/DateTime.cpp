#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>
#include <ctime>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>



using namespace std;

DateTime::DateTime(unsigned int day, unsigned int month, unsigned int year) {
	time_t tmp = time(nullptr);
	CTime = new tm;
	memcpy(CTime, localtime(&tmp), sizeof(tm));
	CTime->tm_mday = day;
	CTime->tm_mon = month - 1;
	CTime->tm_year = year - 1900;
	mktime(CTime);

}

DateTime::DateTime() 
{
	time_t NowT = time(NULL);
	CTime = localtime(&NowT);
}

DateTime::DateTime(const DateTime& value)
{
	
	this->CTime = value.CTime;
}

string DateTime::getToday()
{
	string weekDay[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	string month[12] = { "january", "february", "march", "april", "may", "june","july", "august", "september", "october", "november", "december" };
	string moment;
	string result;
	if (CTime->tm_mday < 10) 
	{
		moment = "0";
	}
	moment +=to_string(CTime->tm_mday);
	result = moment + " " + month[CTime->tm_mon] + " " + to_string(CTime->tm_year + 1900) + "," + " " + weekDay[CTime->tm_wday];
	return result;
}
string DateTime::getPast(unsigned int n)
{
	DateTime past = DateTime(CTime->tm_mday - n, CTime->tm_mon + 1, CTime->tm_year + 1900);
	return past.getToday();
}

string DateTime::getFuture(unsigned int n)
{
	DateTime future = DateTime(CTime->tm_mday + n, CTime->tm_mon + 1, CTime->tm_year + 1900);
	return future.getToday();
}

string DateTime::getYesterday()
{
	return getPast(1);
}

string DateTime::getTomorrow()
{
	return getFuture(1);
}



 int DateTime::getDifference(DateTime& newdate)
{
	
	return abs(mktime(CTime) - mktime(newdate.CTime))/ 86400;
}