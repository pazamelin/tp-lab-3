#pragma once
#include <string>
class DateTime {
public:
	DateTime(int, int, int);
	DateTime();
	DateTime(const DateTime&);	
	std::string getToday() const;
	std::string getYesterday() const; 
	std::string getTomorrow() const;
	std::string getFuture(unsigned int) const;
	std::string getPast(unsigned int) const;
	int getDifference(DateTime&) const;
private:
	std::string getData(int) const;
	int day;
	int month;
	int year;
	static std::string months[];
	static std::string days[];
	static int daysInMonth[];
};
