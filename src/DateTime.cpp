#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"

string m[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "decemder" };
string d[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

DateTime::DateTime(int day, int month, int year)
{
	time_t now = time(NULL);
	date = *localtime(&now);
	DateTime::date.tm_mday = day;
	DateTime::date.tm_mon = month;
	DateTime::date.tm_year = year;
}

DateTime::DateTime()
{
	time_t now = time(NULL);
	date = *localtime(&now);
	tm now_time = *localtime(&now);
	DateTime::date.tm_mday = now_time.tm_mday;
	DateTime::date.tm_mon = now_time.tm_mon;
	DateTime::date.tm_year = now_time.tm_year;
}

DateTime::DateTime(const DateTime& datetime)
{
	DateTime::date.tm_mday = datetime.date.tm_mday;
	DateTime::date.tm_mon = datetime.date.tm_mon;
	DateTime::date.tm_year = datetime.date.tm_year;
}


string DateTime::getToday()
{
	string today = "";
	time_t now = time(NULL);
	tm now_time = *localtime(&now);
	if (date.tm_mday < 10)
		today += "0";
	today += to_string(now_time.tm_mday) + " " + m[now_time.tm_mon] + " " + to_string(now_time.tm_year + 1900) + ", " + d[now_time.tm_wday];
	return today;
}

string DateTime::getFuture(unsigned int N)
{
	string future = "";
	time_t now = time(NULL);
	tm now_time = *localtime(&now);

	now_time.tm_mday += N;

	mktime(&now_time);

	if (date.tm_mday < 10)
		future += "0";
	future += to_string(now_time.tm_mday) + " " + m[now_time.tm_mon] + " " + to_string(now_time.tm_year + 1900) + ", " + d[now_time.tm_wday];
	return future;
}

string DateTime::getPast(unsigned int N)
{
	string past = "";
	time_t now = time(NULL);
	tm now_time = *localtime(&now);

	now_time.tm_mday -= N;

	mktime(&now_time);

	if (date.tm_mday < 10)
		past += "0";
	past += to_string(now_time.tm_mday) + " " + m[now_time.tm_mon] + " " + to_string(now_time.tm_year + 1900) + ", " + d[now_time.tm_wday];
	return past;
}

string DateTime::getTomorrow()
{
	return getFuture(1);
}

string DateTime::getYesterday()
{
	return getPast(1);
}

int DateTime::getDifference(DateTime& given_date)
{
	return abs(mktime(&date) - mktime(&given_date.date))/(24 * 60 * 60);
}
