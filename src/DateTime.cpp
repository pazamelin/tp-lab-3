#define _CRT_SECURE_NO_WARNINGS
#include "DateTime.h"
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
using namespace std;
const int DAY = 86400;
const vector <string> w_days = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
const vector <string> months = { "January", "February", "March", "April", "May", "June" ,"July", "August", "September", "October" ,"November" ,"December" };

DateTime::DateTime(int day, int month, int year){
	tm date = { 0, 0, 0, day, month - 1, year - 1900, 0, 0, 0 };
	sec_time = mktime(&date);
}

DateTime::DateTime() {
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);	
	tm date = { 0, 0, 0, timeinfo->tm_mday, timeinfo->tm_mon, timeinfo->tm_year, 0, 0, 0 };
	sec_time = mktime(&date);
}



DateTime::DateTime(const DateTime &obj)
{
	sec_time = obj.sec_time;
}

std::string DateTime::getToday() {
	tm* date = localtime(&sec_time);
	int day, year;
	int month, w_day;
	day = date->tm_mday;
	month = date->tm_mon;
	year = date->tm_year + 1900;
	w_day = date->tm_wday;
	std::string str_date = "";	
	str_date.append(std::to_string(day));
	str_date.append(" ");
	str_date.append(months[month]);
	str_date.append(" ");
	str_date.append(std::to_string(year));
	str_date.append(", ");
	str_date.append(w_days[w_day]);
	return str_date;
}

std::string DateTime::getYesterday() {
	sec_time -= DAY;
	std::string yesterday = getToday();
	sec_time += DAY;
	return yesterday;
}

std::string DateTime::getTomorrow() {
	sec_time += DAY;
	std::string tomorrow = getToday();
	sec_time -= DAY;
	return tomorrow;
}


std::string DateTime::getFuture(unsigned int N) {
	sec_time += DAY * N;
	std::string tomorrow = getToday();
	sec_time -= DAY * N;
	return tomorrow;
}

std::string DateTime::getPast(unsigned int N) {
	sec_time -= DAY * N;
	std::string tomorrow = getToday();
	sec_time += DAY * N;
	return tomorrow;
}

int DateTime::getDifference(DateTime& date) {
	return (date.sec_time > sec_time) ? (date.sec_time - sec_time) / DAY : (sec_time - date.sec_time) / DAY;
}