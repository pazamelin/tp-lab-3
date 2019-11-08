#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <ctime>
#include <cstdio>
DateTime::DateTime(int _day, int _month, int _year)
{
	day = _day;
	month = _month - 1;
	year = _year - 1900;
}
DateTime::DateTime() {
	time_t  t = time(nullptr);
	tm* l = localtime(&t);
	day = l->tm_mday;
	month = l->tm_mon;
	year = l->tm_year;
}
DateTime::DateTime(DateTime& _datetime) {
	day = _datetime.day;
	month = _datetime.month;
	year = _datetime.year;
}
std::string DateTime::getData(int N)
{
	DateTime tempDate = *this;
	if( 1 <= tempDate.day + N && tempDate.day + N <= daysInMonth[tempDate.month] )
	{
		tempDate.day += N;
	}
	else
	{
		
		if(tempDate.day + N < 1)
		{
			while(!(1 <= tempDate.day + N && tempDate.day + N <= daysInMonth[tempDate.month]))
			{
				--tempDate.month;
				if(tempDate.month == -1)
				{
					tempDate.month = 11;
					--tempDate.year;
				}
				N += tempDate.day;
				tempDate.day = daysInMonth[tempDate.month];
			}
		}
		if (tempDate.day + N > daysInMonth[tempDate.month])
		{
			while (!(1 <= tempDate.day + N && tempDate.day + N <= daysInMonth[tempDate.month]))
			{
				++tempDate.month;
				if (tempDate.month == 12)
				{
					tempDate.month = 0;
					++tempDate.year;
				}
				N -= tempDate.day;
				tempDate.day = daysInMonth[tempDate.month];
			}
		}
		
	}
	tempDate.day += N;
	time_t r;
	time(&r);
	tm t = *localtime(&r);
	t.tm_year = tempDate.year;
	t.tm_mon = tempDate.month;
	t.tm_mday = tempDate.day;
	mktime(&t);
	std::string result;
	if (tempDate.day < 10)
		result += "0";
	result += std::to_string(tempDate.day) + " " + months[tempDate.month] + " " + std::to_string(tempDate.year + 1900) + ", " + days[t.tm_wday];
	return result;
}
std::string DateTime::getToday()
{
	return getData(0);
}
std::string DateTime::getYesterday()
{
	return getData(-1);
}
std::string DateTime::getTomorrow()
{
	return getData(1);
}
std::string DateTime::getFuture(unsigned int N)
{
	return getData(N);
}
std::string DateTime::getPast(unsigned int N)
{
	return getData(-int(N));
}
int DateTime::getDifference(DateTime& _date_time)
{
	DateTime dt1 = year < _date_time.year ? *this : _date_time;
	DateTime dt2 = year >= _date_time.year ? *this : _date_time;
	int days1 = dt1.day;
	int days2 = dt2.day;
	for(int i = 0; i < dt1.month; i++)
	{
		days1 += daysInMonth[i];
	}
	for (int i = 0; i < dt2.month; i++)
	{
		days2 += daysInMonth[i];
	}
	if(dt1.year == dt2.year)
	{
		return abs(days1 - days2);
	}	
	return (dt2.year - dt1.year) * 365 + (365 - dt1.year) + dt2.year;	
}



