#define _CRT_SECURE_NO_WARNINGS
#include "task1.h"
#include <math.h>
#include <iostream>
#include "time.h"
#include "DateTime.h"


int main()
{
	DateTime tbl(6, 11, 2018);
	DateTime tb2(3, 11, 2018);
	std::cout << tbl.getToday();
	std::cout << "\n" << tbl.getYesterday();
	std::cout << "\n" << tbl.getTomorrow();
	std::cout << "\n" << tbl.getFuture(3);
	std::cout << "\n" << tbl.getPast(3);
	std::cout << "\n" << tbl.getDifference(tb2);
	return 0;
}