#define _CRT_SECURE_NO_WARNINGS

#include "DateTime.h"

DateTime::DateTime() {
	time_t seconds = time(NULL);
	Time = *localtime(&seconds);
}
DateTime::DateTime(time_t Day, time_t Month, time_t Year) {
	time_t seconds = time(NULL);
	Time = *localtime(&seconds);
	Time.tm_mday = Day;
	Time.tm_mon = Month - 1;
	Time.tm_year = Year - 1900;
	mktime(&Time);
}
DateTime::DateTime(const DateTime& Date) {
	Time = Date.Time;
}
std::string DateTime::getToday() const {
	struct tm tmp = Time;
	return ConvertDate(tmp);
}
std::string DateTime::getYesterday() const {
	return getPast(1);
}
std::string DateTime::getTomorrow() const {
	return getFuture(1);
}
std::string DateTime::getFuture(unsigned int N) const {
	struct tm tmp = Time;
	time_t seconds = mktime(&tmp);
	seconds += N * 86400;
	return ConvertDate(*localtime(&seconds));
}
std::string DateTime::getPast(unsigned int N) const {
	struct tm tmp = Time;
	time_t seconds = mktime(&tmp);
	seconds -= N * 86400;
	return ConvertDate(*localtime(&seconds));
}
int DateTime::getDifference(DateTime& Date) const {
	struct tm tmp = Time;
	return abs(mktime(&tmp) - mktime(&Date.Time)) / 86400;
}

std::string DateTime::Days[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
std::string DateTime::Months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

std::string DateTime::ConvertDate(const struct tm& Time)const {
	std::string Date = "";

	if (Time.tm_mday > 9) {
		Date += std::to_string(Time.tm_mday);
	}
	else {
		Date += "0";
		Date += std::to_string(Time.tm_mday);
	}

	Date += " " + Months[Time.tm_mon] + " " + std::to_string(Time.tm_year + 1900) + ", " + Days[Time.tm_wday];
	return Date;
}