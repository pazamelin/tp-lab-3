#pragma once
#include <string>
#include <ctime>
#include <iostream>
using namespace std;
class DateTime {
private:
	int day;
	int month;
	int year;
	string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	string days[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 , 31 };
public:
	DateTime(int, int, int);
	DateTime();
	DateTime(DateTime& copydate);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	int getDifference(DateTime&);
};