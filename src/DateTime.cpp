#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <iostream>
#include <math.h>

using namespace std;

string months[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "septeber", "october", "november", "december" };
string days[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

DateTime::DateTime(unsigned short day, unsigned short month, unsigned int year) {
	Time = time(NULL);
	Date = localtime(&Time);
	Date->tm_mday = day;
	Date->tm_mon = month - 1;
	Date->tm_year = year - 1900;
	Time = mktime(Date);
	mktime(Date);
}

DateTime::DateTime() {
	Time = time(NULL);
	Date = localtime(&Time);
}

DateTime::DateTime(const DateTime& object) {
	Time = object.Time;
	Date = localtime(&Time);
}

string DateTime::DateToString(tm* date) {
	string ans = "";
	if (date->tm_mday < 10) {
		ans += "0" + to_string(date->tm_mday);
	}
	else {
		ans += to_string(date->tm_mday);
	}
	ans += " " + months[date->tm_mon] + " " + to_string(date->tm_year + 1900) + ", " + days[date->tm_wday - 1];
	return ans;
}

string DateTime::getToday() {
	string ans = DateToString(Date);
	return ans;
}

string DateTime::getYesterday() {
	string ans = getPast(1);
	return ans;
}

string DateTime::getTomorrow() {
	string ans = getFuture(1);
	return ans;
}

string DateTime::getFuture(unsigned int n) {
	string ans = "";
	tm* futureDate = Date;
	futureDate->tm_mday += n;
	time_t futureTime = mktime(futureDate);
	futureDate = localtime(&futureTime);
	ans = DateToString(futureDate);
	return ans;
}

string DateTime::getPast(unsigned int n) {
	string ans = "";
	tm* pastDate = Date;
	pastDate->tm_mday -= n;
	time_t pastTime = mktime(pastDate);
	pastDate = localtime(&pastTime);
	ans = DateToString(pastDate);
	return ans;
}

unsigned int DateTime::getDifference(DateTime& date) {
	time_t ans = date.Time;
	ans = abs(ans - Time) / (24 * 60 * 60);
	return ans;
}