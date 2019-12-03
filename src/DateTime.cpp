#include "DateTime.h"

string DateTime::months[]={ "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
string DateTime::days[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };

DateTime::DateTime(int day, int month, int year)
{
	time_t sec = time(NULL);
	data_time = *localtime(&sec);
	data_time.tm_mday = day;
	data_time.tm_mon = month - 1;
	data_time.tm_year = year - 1900;
	mktime(&data_time);
}

DateTime::DateTime()
{
	time_t sec = time(NULL);
	data_time = *localtime(&sec);
	cout << data_time.tm_wday;
}

DateTime::DateTime(const DateTime& _copy)
{
	data_time = _copy.data_time;
}

string DateTime::getToday()
{
	return getData(data_time);
}

string DateTime::getYesterday()
{
	return getPast(1);
}

string DateTime::getTomorrow()
{
	return getFuture(1);
}

string DateTime::getPast(unsigned int N)
{
	time_t sec = mktime(&data_time);
	sec -= N*86400;
	return getData(*localtime(&sec));
}

string DateTime::getFuture(unsigned int N)
{
	time_t sec = mktime(&data_time);
	sec += N*86400; 
	return getData(*localtime(&sec));
}

int DateTime::getDifference(DateTime& data)
{
	return abs(mktime(&data_time) - mktime(&data.data_time)) / 86400;
}

string DateTime::getData(tm& data_time)
{
	string Data = "";
	if (data_time.tm_mday > 9)
		Data += to_string(data_time.tm_mday);
	else
		Data += "0" + to_string(data_time.tm_mday);

	Data += " " + months[data_time.tm_mon] + " " + to_string(data_time.tm_year + 1900) + ", " + days[data_time.tm_wday];
	return Data;
}
