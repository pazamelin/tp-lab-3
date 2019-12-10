#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <math.h>

using namespace std;

class DateTime {
private:
	tm* Date;
	time_t Time;
public:
	DateTime(unsigned short day, unsigned short month, unsigned int year);
	DateTime();
	DateTime(const DateTime& object);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int n);
	string getPast(unsigned int n);
	unsigned int getDifference(DateTime&);
	string DateToString(tm*);
};
