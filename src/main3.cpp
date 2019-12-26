#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"
using namespace std;
int main() {
	DateTime cur, newdate(21, 11, 2018);
	cout << "Today:   \t" << cur.getToday() << endl;
	cout << "Yesterday: \t" << cur.getYesterday() << endl;
	cout << "Tommorow \t" << cur.getTomorrow() << endl;
	cout << "After 7 days: \t" << cur.getFuture(7) << endl;
	cout << "9 days ago: \t" << cur.getPast(9) << endl;
	cout << "New today:   \t" << newdate.getToday() << endl;
	cout << "Diffrence: \t" << cur.getDifference(newdate) << endl;
	return 0;
}