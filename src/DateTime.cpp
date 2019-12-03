#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <string>
#include <iostream>
std::string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "septeber", "october", "november", "december" };
std::string week[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
DateTime::DateTime(int day, int month, int year) {
	time_t seconds = time(NULL);
	date = *localtime(&seconds);
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);
	
}
DateTime::DateTime() {
	time_t s_time = time(NULL);
	date = *(localtime(&s_time));
}
DateTime::DateTime(DateTime &buf) {
	this->date = buf.date;
}
std::string DateToString(tm date) {
	std::string str = std::to_string(date.tm_mday) + " " + months[date.tm_mon] + " " + std::to_string(date.tm_year + 1900) + ", " + week[date.tm_wday];
	return str;
	//(07 november 2018, wedensday);
}
std::string DateTime::getToday() {
	return DateToString(this->date);
}
std::string DateTime::getYesterday() {
	tm yesterday;
	time_t s_time = time(NULL);
	s_time -= 3600 * 24;
	yesterday = *(localtime(&s_time));
	return DateToString(yesterday);
}
std::string DateTime::getTomorrow() {
	tm yesterday;
	time_t s_time = time(NULL);
	s_time += 3600 * 24;
	yesterday = *(localtime(&s_time));
	return DateToString(yesterday);
}
std::string DateTime::getFuture(unsigned int N) {
	tm yesterday;
	time_t s_time = time(NULL);
	s_time += 3600 * 24 * N;
	yesterday = *(localtime(&s_time));
	return DateToString(yesterday);
}
std::string DateTime::getPast(unsigned int N) {
	tm yesterday;
	time_t s_time = time(NULL);
	s_time -= 3600 * 24 * N;
	yesterday = *(localtime(&s_time));
	return DateToString(yesterday);
}
int DateTime::getDifference(DateTime &buf) {
	return abs(mktime(&date) - mktime(&buf.date)) / 86400;
}