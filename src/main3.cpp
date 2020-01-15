#include <iostream>
#include <string>
#include <ctime>
#include "DateTime.h"
using namespace std;

int main()
{
	DateTime date1(31,10,2018);
	cout << "date1.getToday() = " << date1.getToday() << endl;
	cout << "date1.getTomorrow() = " << date1.getTomorrow() << endl;
	cout << endl;
	DateTime date2(1, 11, 2018);
	cout << "date2.getToday() = " << date2.getToday() << endl;
	cout << "date2.getTomorrow() = " << date2.getTomorrow() << endl;
	cout << endl;
	DateTime date3(20, 11, 2018);
	DateTime date4(20, 11, 2018);
	cout << "date3.getToday() = " << date3.getToday() << endl;
	cout << "date4.getToday() = " << date4.getToday() << endl;
	cout << "date3.getDifference(date4) = " << date3.getDifference(date4);
	cout << endl;
	DateTime date5(20, 11, 2018);
	DateTime date6(21, 11, 2018);
	cout << "date5.getToday() = " << date5.getToday() << endl;
	cout << "date6.getToday() = " << date6.getToday() << endl;
	cout << "date5.getDifference(date6) = " << date5.getDifference(date6);





	return 0;
}

