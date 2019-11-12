#pragma once
#include <time.h>
#include <ctime>
#include <string>

class DateTime {
private:
	struct tm Time;
public:
	DateTime();
	DateTime(time_t Day, time_t Month, time_t Year);
	DateTime(const DateTime&);
	std::string getToday();
	std::string getYesterday(); 
	std::string getTomorrow(); 
	std::string getFuture(unsigned int N); 
	std::string getPast(unsigned int N); 
	int getDifference(DateTime&);
};