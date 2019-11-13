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
	std::string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	std::string days[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30 ,31 };
};
