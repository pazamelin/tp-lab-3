#include "DateTime.h"
#include<string>
#include <ctime>
string day_word[7] = { "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday" };
int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string month_word[12] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };

void DateTime::wday_adjustment(int day, int month, int year){ //подстраивает день недели
	time_t epoch = time(NULL);
	date = *localtime(&epoch);
	date.tm_mday = day;
	date.tm_mon = month;
	date.tm_year = year;
	mktime(&date);
}

DateTime::DateTime(int day, int month, int year){
	/*time_t epoch = time(NULL);
	date = *localtime(&epoch);
	date.tm_mday = day;
	date.tm_mon = month - 1;
	date.tm_year = year - 1900;
	mktime(&date);*/
	month -= 1;
	year -= 1900;
	wday_adjustment(day, month, year);
}

DateTime::DateTime(){
	time_t epoch = time(NULL);
	date = *localtime(&epoch);
}

DateTime::DateTime(DateTime & date2)
{
	this->date = date2.date;
}

string DateTime::string_output(struct tm *output_date) {
	string date_text;
	if (output_date->tm_mday < 10) {
		date_text = "0";
	}
	else {
		date_text = "";
	}
	date_text += to_string(output_date->tm_mday) + " " + month_word[output_date->tm_mon] + " " + to_string(output_date->tm_year + 1900) + ", "+ day_word[output_date->tm_wday];
	return date_text;
}

string DateTime::getToday(){
	return string_output(&date);
}

string DateTime::getFuture(unsigned int N){
	while (date.tm_mday + N > days_in_month[date.tm_mon]){
		N -= days_in_month[date.tm_mon];

		if (date.tm_mon + 1 > 11){
			date.tm_mon = 0;
			date.tm_year++;
		}
		else {
			date.tm_mon++;
		}
	}
	date.tm_mday += N;

	wday_adjustment(date.tm_mday, date.tm_mon, date.tm_year);
	return string_output(&date);
}

string DateTime::getTomorrow(){
	return getFuture(1);
}

string DateTime::getYesterday(){
	return getPast(1);
}

string DateTime::getPast(unsigned int N){
	while (date.tm_mday - N < 1){
		N -= days_in_month[date.tm_mon];
		if (date.tm_mon - 1 < 0){
			date.tm_mon = 11;
			date.tm_year--;
		}
		else {
			date.tm_mon--;
		}
	}
	date.tm_mday -= N;

	wday_adjustment(date.tm_mday, date.tm_mon, date.tm_year);
	return string_output(&date);
}

int DateTime::getDifference(DateTime & day){
	time_t secs1 = mktime(&date);
	time_t secs2 = mktime(&day.date);
	return abs(secs2 - secs1) / (60 * 60 * 24);
}