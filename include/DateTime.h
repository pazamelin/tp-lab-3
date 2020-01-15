#pragma once
#include <string>
#include <ctime>
using namespace std;

class DateTime
{
private:
	tm date;

public:
	DateTime(int day, int month, int year);
	DateTime();
	DateTime(const DateTime& date);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	unsigned int getDifference(DateTime&);
	string timetostr(const tm& time);

};