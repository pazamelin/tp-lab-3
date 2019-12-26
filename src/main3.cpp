#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <ctime>
#include "DateTime.h"
using namespace std;

int main() {
	DateTime date1(11, 9, 2019);
	cout << "Today is: " << date1.getToday() << endl;
	cout << "Yesterday was: " << date1.getYesterday() << endl;
	cout << "Tomorrow will be: " << date1.getTomorrow() << endl;
	cout << "In 5 days it will be: " << date1.getFuture(5) << endl;
	cout << "5 days ago it was: " << date1.getPast(5) << endl;

	DateTime date2(20, 9, 2019);
	cout << "The difference between "<< date2.getToday() << " and " << date1.getToday() << " is " << date2.getDifference(date1) << " days" << endl;

	system("pause");

	return 0;
}