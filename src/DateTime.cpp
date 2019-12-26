#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <sstream>
#include <string>
#include "time.h"
#include "DateTime.h"

static std::string mkString(tm* t) {

	std::string weekday[] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	std::string month[] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
	std::string tmpstr_for_num = std::to_string(t->tm_mday); ;
	if (t->tm_mday<10) {
	   tmpstr_for_num = "0"+ tmpstr_for_num;
	}
	std::string strtmp = tmpstr_for_num + " " + month[t->tm_mon] + " " + std::to_string(t->tm_year+1900) + "," + " " + weekday[t->tm_wday];
	return strtmp;
}

DateTime::DateTime(int _day, int _mon, int _year) {
	day = _day;
	mon = _mon-1;
	year = _year;
}

DateTime::DateTime() {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	day = t->tm_mday;
	mon = t->tm_mon;
	year = t->tm_year;
}

DateTime::DateTime(const DateTime& a) {
	day = a.day;
	mon = a.mon;
	year = a.year;
}

std::string DateTime::getToday() {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	t->tm_mday= day;
	t->tm_mon= mon;
	t->tm_year= year-1900;
	mktime(t);
	return mkString(t);
}

std::string DateTime::getYesterday() {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	t->tm_mday = day-1;
	t->tm_mon = mon;
	t->tm_year = year-1900;
	mktime(t);
	return mkString(t);
}

std::string DateTime::getTomorrow() {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	t->tm_mday = day+1;
	t->tm_mon = mon;
	t->tm_year = year - 1900;
	mktime(t);
	return mkString(t);
}

std::string DateTime::getFuture(unsigned int N) {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	t->tm_mday = day+N;
	t->tm_mon = mon;
	t->tm_year = year - 1900;
	mktime(t);
	return mkString(t);
}

std::string DateTime::getPast(unsigned int N) {
	struct tm* t;
	time_t ltime;
	time(&ltime);
	t = localtime(&ltime);
	t->tm_mday = day-N;
	t->tm_mon = mon;
	t->tm_year = year - 1900;
	mktime(t);
	return mkString(t);
}

int DateTime::getDifference(DateTime& anotherday) {

	tm a = { 0,0,0,day,mon,year-1900 };
	tm b = { 0,0,0,anotherday.day,anotherday.mon,anotherday.year-1900}; 
	time_t x = mktime(&a);
	time_t y = mktime(&b);
    int difference = difftime(y, x) / (60 * 60 * 24);	
    return abs(difference);
}

