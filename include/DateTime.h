#ifndef dateTime_h
#define dateTime_h

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class DateTime
{
private:
	string weekday[7] = { "sunday\0", "monday\0", "tuesday\0", "wednesday\0","thursday\0", "friday\0", "saturday\0" };
	string month[12] = { "january\0", "february\0", "march\0", "april\0", "may\0", "june\0", "july\0", "august\0",
						"september\0", "october\0", "november\0", "december\0" };

	time_t now;  //current time in seconds
	tm* t;  //current time structure (seconds, hours, months, e.t.c)

public:
	DateTime(unsigned int, unsigned int, unsigned int);
	
	DateTime();
	
	DateTime(const DateTime&);
	
	string getToday(); 
	
	string getYesterday();
	
	string getTomorrow();
	
	string getFuture(unsigned int N);
	
	string getPast(unsigned int N);
	
	int getDifference(DateTime&);
	
	string getStr(tm* new_t);
};
#endif 