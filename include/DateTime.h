#pragma once 
#include <string>
using namespace std;

class DateTime {
private:
	struct tm date;
	void wday_adjustment(int day, int month, int year);
	string string_output(struct tm *output_date);
public:
	DateTime(int day, int month, int year);
	DateTime();
	DateTime(DateTime & copy);
	string getToday();
	string getFuture(unsigned int N);
	string getTomorrow();
	string getYesterday();
	string getPast(unsigned int N);
	int getDifference(DateTime&);
};