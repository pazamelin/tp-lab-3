#ifndef __DATE_TIME_H_
#define __DATE_TIME_H_

#include <ctime>
#include <iostream>

class DateTime
{
public:

	DateTime(unsigned int D, unsigned int M, unsigned int Y);
	DateTime();
	DateTime(const DateTime&);

	~DateTime();

	std::string getToday();

	std::string getYesterday();
	std::string getTomorrow();

	std::string getFuture(unsigned int N);
	std::string getPast(unsigned int N);

	int getDifference(DateTime&);


private:

	std::string tmToStr(tm* time);

	time_t now; 
	tm* t;

	std::string wDayNumStr[7] = { "sunday\0", 
								  "monday\0", 
		                          "tuesday\0", 
								  "wednesday\0",
		                          "thursday\0",  
		                          "friday\0",  
		                          "saturday\0" };

	std::string mNumStr[12]   = { "january\0", 
		                          "february\0", 
		                          "march\0", 
		                          "april\0", 
		                          "may\0", 
		                          "june\0", 
		                          "july\0", 
		                          "august\0",
						          "september\0", 
		                          "october\0", 
		                          "november\0", 
		                          "december\0" };
};

#endif
