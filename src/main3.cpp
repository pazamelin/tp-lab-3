#include "DateTime.h"
#include <iostream>
using namespace std;
int main() {
	DateTime td1(31, 10, 2018);
	DateTime td2(1, 11, 2018);
	cout << td2.getToday() << endl;
	cout << td1.getYesterday() << endl;
	cout << td1.getTomorrow() << " " << td2.getTomorrow() << endl;
	cout << td1.getFuture(31) << endl;
	cout << td1.getPast(13) << endl;
	cout << td1.getDifference(td2);
	return 0;
}