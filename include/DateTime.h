#include <cstdint>
#include <string>

#ifndef _DATETIME_H_
#define _DATETIME_H_

class DateTime
{
public:
	DateTime(int day, int month, int year);
	DateTime(DateTime &dateTime);
	DateTime();

	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(uint32_t n);
	std::string getPast(uint32_t n);
	int32_t getDifference(DateTime &dateTime);
private:
	int8_t day;
	int8_t month;
	int32_t year;
};

#endif _DATETIME_H_
