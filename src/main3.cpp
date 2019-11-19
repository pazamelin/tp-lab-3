#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"
using namespace std;

int main() {
	DateTime dt1(31, 10, 2018);
	cout << "Data: " << dt1.getToday() << endl;
	cout << "Tomorrow: " << dt1.getTomorrow() << endl;
	cout << "Yesterday: " << dt1.getYesterday() << endl;
	DateTime dt2(1, 11, 2018);
	cout << "Data: " << dt2.getToday() << endl;
	cout << "Difference btw dt1 and dt2: " << dt1.getDifference(dt2) << " day(s)";
	
	return 0;
}
