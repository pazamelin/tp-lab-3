#include <cstdint>
#include <string>

#ifndef _DATETIME_H_
#define _DATETIME_H_

class DateTime
{
public:
	DateTime(int day, int month, int year);
	DateTime(const DateTime &dateTime);
	DateTime();

	std::string getToday() const;
	std::string getYesterday() const;
	std::string getTomorrow() const;
	std::string getFuture(uint32_t n) const;
	std::string getPast(uint32_t n) const;
	int32_t getDifference(DateTime &dateTime) const;

private:
	int8_t day;
	int8_t month;
	int32_t year;
};

#endif _DATETIME_H_
