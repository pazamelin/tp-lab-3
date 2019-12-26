#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>

class DateTime 
{
public:
	DateTime(int, int, int);
	DateTime();
	DateTime(const DateTime&);
	std::string getToday();
	std::string getYesterday();
	std::string getTomorrow();
	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);
	int getDifference(DateTime&);
	void prTime() {
		tm* date = localtime(&sec_time);
		std::cout << date->tm_mday << " " << date->tm_mon + 1 << " " << date->tm_year + 1900 << std::endl;
	}
private:
	time_t sec_time;
};