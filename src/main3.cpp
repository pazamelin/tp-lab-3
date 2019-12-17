#include "DateTime.h"
#include <iostream>

int main() 
{
	DateTime date1(18, 11, 2019);
	DateTime date2(24, 11, 2019);

	//1. Difference
	cout << "Difference: " << date1.getDifference(date2) << endl;
	//2. getToday
	cout << date2.getToday() << endl;
	//3. getYesterday
	cout << date1.getYesterday() << endl;
	//4. getTomorrow
	cout << date1.getTomorrow() << endl;
	//5. getFuture
	cout << date1.getFuture(2) << endl;
	//6. getPast
	cout << date1.getPast(3) << endl;

	return 0;
}