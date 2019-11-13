#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"
using namespace std;

int main() {
	DateTime dt(31, 10, 2019);
	cout << "Date: " << dt.getToday() << endl;
	cout << "Tomorrow: " << dt.getTomorrow() << endl;
	cout << "Yesterday: " << dt.getYesterday() << endl;
	cout << "In 10 days: " << dt.getFuture(10) << endl << endl;
	
	DateTime dt2(10, 11, 2019);
	cout << "Another date: " << dt2.getToday() << endl;
	cout << "Difference between " << dt.getToday() << " and " << dt2.getToday() << " is " << dt.getDifference(dt2) << " days" << endl;
	cout << "Difference between " << dt2.getToday() << " and " << dt.getToday() << " is " << dt2.getDifference(dt) << " days" << endl;

	return 0;
}