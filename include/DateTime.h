#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <string>
#include <math.h>

using namespace std;
typedef unsigned int number;

class DateTime
{
	private:

		static string days[7];
		static string months[12];
		
		time_t now;

		string timeToString(time_t);

	public:
		DateTime(const number , const number , const number );
		DateTime();
		DateTime(const DateTime&);
		~DateTime();

		string getToday();
		string getYesterday();
		string getTomorrow();
		string getFuture(number);
		string getPast(number);
		number getDifference(DateTime&);
};
