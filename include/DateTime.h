#ifndef DateTimeH
#define DateTimeH

#include <string>
#include <ctime>
#include <vector>

using namespace std;

class DateTime 
{
private:
	time_t timeInSec;
	tm* timeStruct;
	vector<string> weekdays = {
		"sunday",
		"monday",
		"tuesday",
		"wednesday",
		"thursday",
		"friday",
		"saturday"
	};
	vector<string> months = {
		"january", 
		"february", 
		"march", 
		"april", 
		"may", 
		"june", 
		"july", 
		"august",
		"september", 
		"october", 
		"november", 
		"december" 
	};
public:

	DateTime(unsigned int day, unsigned int month, unsigned int year);

	DateTime();

	DateTime(const DateTime&);

	string getToday();

	string getYesterday();

	string getTomorrow();

	string getFuture(unsigned int N);

	string getPast(unsigned int N);

	int getDifference(DateTime&);

	string dayStr(tm*);
};

#endif
