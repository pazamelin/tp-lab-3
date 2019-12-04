#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <math.h>

using namespace std;

class DateTime
{
	private:

		static string days[7];
		static string months[12];
		
		tm *calendarTime;
		time_t now;

		string timeToString(tm *);

	public:
		DateTime(unsigned int day, unsigned int month, unsigned int year);
		DateTime();
		DateTime(const DateTime&);
		~DateTime();

		string getToday();
		string getYesterday();
		string getTomorrow();
		string getFuture(unsigned int N);
		string getPast(unsigned int N);
		unsigned int getDifference(DateTime&);
};
