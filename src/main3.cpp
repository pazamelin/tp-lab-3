#include "DateTime.h"
#include <iostream>
#include <string>

int main() {
	DateTime date_cur(20, 11, 2018), date_user(21, 11, 2018);
	date_cur.prTime();
	date_user.prTime();
	DateTime copy_date = date_user;
	copy_date.prTime();
	std::cout << "users data: " << date_user.getToday() << "\n";
	std::cout << "current data: " << date_cur.getToday() << "\n";
	std::cout << "users yesterday data: " << date_user.getYesterday() << "\n";
	std::cout << "users tomorrow data: " << date_user.getTomorrow() << "\n";
	std::cout << "difference: " << date_user.getDifference(date_cur) << "\n";
	return 0;
}