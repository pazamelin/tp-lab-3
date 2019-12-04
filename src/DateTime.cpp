#include "DateTime.h"
#include <iostream>
#include <algorithm>

using namespace std;

string DateTime::days[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday" };

string DateTime::months[12] = { "january", "february", "march", "april", "may", "june", "july",
							"august", "september", "october", "november", "december" };

DateTime::DateTime(unsigned int day, unsigned int month, unsigned year) {
	now = time(NULL);
	calendarTime = localtime(&now);

	calendarTime->tm_mday = day;
	calendarTime->tm_mon = month - 1;
	calendarTime->tm_year = year - 1900;

	now = mktime(calendarTime);
	calendarTime = localtime(&now);
}

DateTime::DateTime(){
	now = time(NULL);
	calendarTime = localtime(&now);
}

DateTime::DateTime(const DateTime &from) {
	now = from.now;
	calendarTime = localtime(&now);
}

DateTime::~DateTime() {
	
}

string DateTime::timeToString(tm *calendarTime) {
	//07 november 2018, wedensday
	string ans("");

	if (calendarTime->tm_mday <= 9) {
		ans += "0" + to_string(calendarTime->tm_mday);
	}
	else {
		ans += to_string(calendarTime->tm_mday);
	}

	ans += " " + months[calendarTime->tm_mon] + " " + to_string(calendarTime->tm_year + 1900) + ", " + days[calendarTime->tm_wday];
	return ans;

}

string DateTime::getToday() {
	//cout << calendarTime->tm_mday;
	return timeToString(localtime(&now));
}

string DateTime::getYesterday() {
	return getPast(1);
}

string DateTime::getTomorrow() {
	return getFuture(1);
}

string DateTime::getPast(unsigned int N) {
	tm *pastCal = localtime(&now);
	pastCal->tm_mday -= N;
	
	time_t pastTime = mktime(pastCal);
	pastCal = localtime(&pastTime);
	return timeToString(pastCal);
}

string DateTime::getFuture(unsigned int N) {
	tm *futureCal = localtime(&now);
	futureCal->tm_mday += N;

	time_t futureTime = mktime(futureCal);
	futureCal = localtime(&futureTime);
	return timeToString(futureCal);
}

unsigned int DateTime::getDifference(DateTime& target) {

	time_t targetTime = target.now;
	return abs(targetTime - now)/(24*60*60);
}