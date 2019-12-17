#include <iostream>
#include <string>
#include <ctime>
#include "DateTime.h"
using namespace std;
int main() {	
	DateTime test_day1(31, 12, 2019);
	DateTime test_day2(21, 12, 2019);
	cout << "difference: " << test_day1.getDifference(test_day2) << endl;
	cout << test_day1.getToday() << endl;
	cout << "tomorrow: " <<  test_day1.getTomorrow() << endl;
	cout << "yesterday: " <<test_day1.getYesterday() << endl;
	cout << test_day1.getFuture(123) << endl;
	cout << test_day1.getPast(123) << endl;

	system("pause");
	return 0;
}