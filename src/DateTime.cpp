#define _CRT_SECURE_NO_WARNINGS

#include "DateTime.h"

std::string Days[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
std::string Months[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

static std::string ConvertDate(const struct tm& Time) {
	std::string Date = "";

	if (Time.tm_mday > 9) {
		Date += std::to_string(Time.tm_mday);
	}
	else {
		Date += "0";
		Date += std::to_string(Time.tm_mday);
	}

	Date += " " + Months[Time.tm_mon]+ " " + std::to_string(Time.tm_year+1900) + ", " + Days[Time.tm_wday];
	return Date;
}
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
std::string DateTime::getToday() {
	return ConvertDate(Time);
}
std::string DateTime::getYesterday() {
	return getPast(1);
}
std::string DateTime::getTomorrow() {
	return getFuture(1);
}
std::string DateTime::getFuture(unsigned int N) {
	time_t seconds = mktime(&Time);
	seconds += N * 86400;
	return ConvertDate(*localtime(&seconds));
}
std::string DateTime::getPast(unsigned int N) {
	time_t seconds = mktime(&Time);
	seconds -= N * 86400;
	return ConvertDate(*localtime(&seconds));
}
int DateTime::getDifference(DateTime& Date) {
	return abs(mktime(&Time) - mktime(&Date.Time)) / 86400;
}
