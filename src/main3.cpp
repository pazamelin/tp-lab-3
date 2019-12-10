#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"
#include "DateTime.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	DateTime dt3(10,12,2019);
	cout << dt3.getToday() << endl;
	cout << dt3.getTomorrow() << endl;
	cout << dt3.getYesterday() << endl;
	DateTime dt1(20, 11, 2018);
	DateTime dt2(21, 11, 2018);
	cout << dt1.getToday() << endl;
	cout << dt2.getToday() << endl;
	cout<<dt1.getDifference(dt2);
}