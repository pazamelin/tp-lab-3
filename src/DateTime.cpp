#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"

string m[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "decemder" };
string d[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

DateTime::DateTime(int day, int month, int year)
{
	time_t now = time(NULL);
	date = *localtime(&now);
	DateTime::date.tm_mday = day;
	DateTime::date.tm_mon = month - 1;
	DateTime::date.tm_year = year - 1900;
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
	
	mktime(&date);
	if (date.tm_mday < 10)
		today += "0";
	today += to_string(date.tm_mday) + " " + m[date.tm_mon] + " " + to_string(date.tm_year + 1900) + ", " + d[date.tm_wday];
	return today;
}

string DateTime::getFuture(unsigned int N)
{
	string future = "";
	tm temp = date;

	temp.tm_mday += N;
	mktime(&temp);

	if (temp.tm_mday < 10)
		future += "0";

	future += to_string(temp.tm_mday) + " " + m[temp.tm_mon] + " " + to_string(temp.tm_year + 1900) + ", " + d[temp.tm_wday];
	return future;
}

string DateTime::getPast(unsigned int N)
{
	string past = "";
	tm temp = date;

	temp.tm_mday -= N;
	mktime(&temp);

	if (temp.tm_mday < 10)
		past += "0";

	past += to_string(temp.tm_mday) + " " + m[temp.tm_mon] + " " + to_string(temp.tm_year + 1900) + ", " + d[temp.tm_wday];
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
