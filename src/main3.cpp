#include "DateTime.h"
#include <iostream>

using namespace std;

int main() {
	DateTime dt1{ 1,12,2015 };
	std::cout << "date1.getToday(): " << dt1.getToday() << endl;
	std::cout << "date1.getTomorrow():" << dt1.getTomorrow() << endl;
	std::cout << "date1.getYesterday():" << dt1.getYesterday() << endl;
	std::cout << "date1.getPast(5):" << dt1.getPast(5) << endl;
	std::cout << "date1.getFuture(5):" << dt1.getFuture(5) << endl;
	DateTime dt2(dt1);
	std::cout << "difference:" << dt1.getDifference(dt2);
	return 0;
}