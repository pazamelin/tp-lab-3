#pragma once
#include <string>
using std::string;

class DateTime
{
private:

	struct tm* CTime;
	
public:
	DateTime(unsigned int day, unsigned int month, unsigned int year);
	DateTime();
	DateTime(const DateTime&);

	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	int getDifference(DateTime&);

};