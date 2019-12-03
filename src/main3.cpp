#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "DateTime.h"
#include <string>

int main()
{
	DateTime bd(13, 03, 2001);
	DateTime cd(bd);
	DateTime td;
	std::cout << "my birthday " << bd.getToday() << '\n';
	std::cout << "today " << td.getToday() << '\n';
	std::cout << "yesterday " << td.getYesterday() << '\n';
	std::cout << "tomorrow " << td.getTomorrow() << '\n';
	std::cout << "9 days before me " << bd.getPast(9) << '\n';
	std::cout << "9 days after me " << bd.getFuture(9) << '\n';
	std::cout << "difference " << bd.getDifference(td) << '\n';
	return 0;
}