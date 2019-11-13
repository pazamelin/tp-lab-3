#pragma once
#include <string>
class DateTime {
public:
	DateTime(int, int, int);
	DateTime();
	DateTime(DateTime&);	
	std::string getToday();
	std::string getYesterday(); 
	std::string getTomorrow();
	std::string getFuture(unsigned int);
	std::string getPast(unsigned int);
	int getDifference(DateTime&);
private:
	std::string getData(int);
	int day;
	int month;
	int year;
	static std::string months[12];
	static std::string days[7];
	static int daysInMonth[12];
};
