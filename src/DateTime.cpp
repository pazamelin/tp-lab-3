#include "DateTime.h"
#include <ctime> 
#include <string>
using namespace std;

// конструкторы

DateTime::DateTime() {
	secTime = time(NULL);
	structTime = localtime(&secTime);
}
DateTime::DateTime(unsigned int newDay, unsigned int newMonth, unsigned int newYear) {
	secTime = time(NULL);
	structTime = localtime(&secTime);
	structTime->tm_year = newYear - 1900;
	structTime->tm_mon = newMonth - 1;
	structTime->tm_mday = newDay;
	secTime = mktime(structTime);
}
DateTime::DateTime(const DateTime & DTobject) {
	secTime = DTobject.secTime;
	structTime = localtime(&secTime);
}


// методы
string DateTime::getToday() {
	string weekdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	string months[12] = { "january", "february", "march", "april", "may", "june",
					   "july", "august", "september", "october", "november", "december" };
	structTime = localtime(&secTime);
	string ans("");
	if (this->structTime->tm_mday < 10) {
		ans+= "0";
	}
	ans += to_string(this->structTime->tm_mday) + ' ' + months[this->structTime->tm_mon] + " " + to_string((this->structTime->tm_year)+1900) + ", " + weekdays[this->structTime->tm_wday];
	return ans;
}
string DateTime::getYesterday() {
	return getPast(1);
}

string DateTime::getTomorrow() {
	return getFuture(1);
}
string DateTime::getPast(unsigned int N) {

	string weekdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	string months[12] = { "january", "february", "march", "april", "may", "june",
					   "july", "august", "september", "october", "november", "december" };

	tm* pastTime = localtime(&secTime);
	pastTime->tm_mday -= N;

	time_t secpastTime = mktime(pastTime);
	string ans("");
	
	if (structTime->tm_mday < 10) {
		ans += "0";
	}
	ans += to_string(structTime->tm_mday) + ' ' + months[structTime->tm_mon] + " " + to_string((structTime->tm_year) + 1900) + ", " + weekdays[structTime->tm_wday];
	return ans;
}
string DateTime::getFuture(unsigned int N) {

	string weekdays[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
	string months[12] = { "january", "february", "march", "april", "may", "june",
					   "july", "august", "september", "october", "november", "december" };

	tm* pastTime = localtime(&secTime);
	pastTime->tm_mday += N;

	time_t secpastTime = mktime(pastTime);
	string ans("");
	if (structTime->tm_mday < 10) {
		ans += "0";
	}
	ans += to_string(structTime->tm_mday) + ' ' + months[structTime->tm_mon] + " " + to_string((structTime->tm_year) + 1900) + ", " + weekdays[structTime->tm_wday];
	return ans;
}

unsigned int DateTime::getDifference(DateTime& DTobject) {

	return abs(DTobject.secTime - secTime) / (24 * 60 * 60);
}



