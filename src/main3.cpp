#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "DateTime.h"

int main()
{
	DateTime dt(1, 11, 2018);
	std::cout << dt.getToday() << std::endl;
	std::cout << dt.getYesterday() << std::endl;
	std::cout << dt.getTomorrow() << std::endl;
	std::cout << dt.getFuture(5) << std::endl;
	std::cout << dt.getPast(6) << std::endl;
	DateTime dt1(20, 11, 2018);
	DateTime dt2(20, 11, 2018);
	std::cout << dt1.getDifference(dt2) << std::endl;
	return 0;
}
