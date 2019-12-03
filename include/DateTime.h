#pragma once
#include <time.h>
#include <ctime>
#include <string>

class DateTime {
private:
	struct tm Time;
	static std::string Days[];
	static std::string Months[];
	std::string ConvertDate(const struct tm&) const;
public:
	DateTime();
	DateTime(time_t, time_t, time_t);
	DateTime(const DateTime&);
	std::string getToday() const;
	std::string getYesterday() const;
	std::string getTomorrow() const;
	std::string getFuture(unsigned int N) const;
	std::string getPast(unsigned int N) const;
	int getDifference(DateTime&) const;
};