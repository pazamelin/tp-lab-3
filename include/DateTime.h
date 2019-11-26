#pragma once
#include <string>
#include <ctime>

using namespace std;

#ifndef DATETIME_H
#define DATETIME_H

class DateTime
{
private:
	tm date;
	//string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "septeber", "october", "november", "december" };
	//string week[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
	//int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

public:
	DateTime(int day, int month, int year);
	DateTime();
	DateTime(DateTime & date);
	string answer(struct tm &);
	string getToday();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	string getTomorrow();
	string getYesterday();
	unsigned int getDifference(DateTime &);
};


#endif