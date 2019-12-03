#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"

DateTime::DateTime(int day, int month, int year) {
	this->day = day;
	this->month = month;
	this->year = year;
}
DateTime::DateTime() {
	time_t td = time(nullptr);
	tm* today = localtime(&td);
	day = today->tm_mday;
	month = today->tm_mon;
	year = today->tm_year;
}
DateTime::DateTime(DateTime& cpyobject) {
	day = cpyobject.day;
	month = cpyobject.month;
	year = cpyobject.year;
}

string DateTime::getToday() {
	string buffer;
	time_t tt;
	time(&tt);
	tm* t = localtime(&tt);
	t->tm_mday = day;
	t->tm_mon = month - 1;
	t->tm_year = year - 1900;
	mktime(t);
	if (day < 10) {
		buffer += "0" + to_string(day) + " ";
	}
	else buffer += to_string(day) + " ";

	buffer += months[month-1] + " " + to_string(year) + ", " + days[t->tm_wday];

	return buffer;
}

string DateTime::getYesterday() {
	return getPast(1);
};
string DateTime::getTomorrow() {
	return getFuture(1);
};
string DateTime::getFuture(unsigned int N) {
	string buffer;
	time_t tt;
	time(&tt);
	tm* t = localtime(&tt);
	t->tm_mon = month - 1;
	t->tm_mday = day;
	t->tm_year = year - 1900;
	t->tm_mday += N; // next N

	mktime(t);


	if (t->tm_mday < 10) {
		buffer += "0" + to_string(t->tm_mday) + " ";
	}
	else buffer += to_string(t->tm_mday) + " ";

	buffer += months[t->tm_mon] + " " + to_string(t->tm_year + 1900) + ", " + days[t->tm_wday];

	return buffer;
};
string DateTime::getPast(unsigned int N) {
	string buffer;
	time_t tt;
	time(&tt);
	tm* t = localtime(&tt);
	t->tm_mon = month - 1;
	t->tm_mday = day;
	t->tm_year = year - 1900;
	t->tm_mday -= N; // prev N

	mktime(t);


	if (t->tm_mday < 10) {
		buffer += "0" + to_string(t->tm_mday) + " ";
	}
	else buffer += to_string(t->tm_mday) + " ";

	buffer += months[t->tm_mon] + " " + to_string(t->tm_year + 1900) + ", " + days[t->tm_wday];

	return buffer;
};
int DateTime::getDifference(DateTime& object) {
	if (year - object.year == 0)
		if (month - object.month == 0)
			if (day - object.day == 0)
				return 0;
			else return abs(day - object.day);
		else {
			int difference = 0;
			difference += (daysInMonth[month - 1] - day);
			int i = 1;
			while (i < abs(month - object.month)) {
				difference += daysInMonth[month - 1 + i];
				i++;
			}
			difference += object.day;
			return difference;
		}
	else {
		int difference = 0;
		difference += abs(year - object.year) * 365;
		difference += (daysInMonth[month - 1] - day);
		int i = 1;
		while (i < abs(month - object.month)) {
			difference += daysInMonth[month - 1 + i];
			i++;
		}
		difference += object.day;
		return difference;
	}
};
