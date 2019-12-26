#ifndef DateTime_h
#define DateTime_h

#include <string>
#include <ctime>

using namespace std;

class DateTime
{
private:
	time_t timer1;
	struct tm* u;

public:
	DateTime();
	DateTime(DateTime& date);
	DateTime(int day, int month, int year);
	string getToday();
	string getYesterday();
	string getTomorrow();
	string getFuture(unsigned int N);
	string getPast(unsigned int N);
	int getDifference(DateTime& date);
};


#endif
