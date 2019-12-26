#include <iostream>
#include "DateTime.h"

using namespace std;

int main() {
	int d = 26, m = 11, y = 2018;
	DateTime date;
	DateTime two(d, m, y);
	//DateTime date(d, m, y);
	cout << date.getToday() << "\n" << date.getFuture(10) << "\n" << date.getPast(20) << "\n";
	cout << date.getDifference(two);
	int c;
	cin >> c;
	
	return 0;
}