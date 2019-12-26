#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime> 
#include <string>
using namespace std;
class DateTime
{
private:
	time_t secTime;
	tm * structTime;
	
	

public:
	DateTime(unsigned int newDay, unsigned int newMonth, unsigned int newYear);
	DateTime();
	DateTime(const DateTime&);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	unsigned int getDifference(DateTime&);
	
};