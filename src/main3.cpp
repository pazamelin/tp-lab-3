#include "DateTime.h"
#include <iostream>

using namespace std;

int main() {
	DateTime date1{ 5,2,2001 };
	DateTime date2{};

	cout << "Сегодня " << date1.getToday() << endl;
	cout << "Сегодня: " << date2.getToday() << endl;
	cout << "Разница" << date1.getDifference(date2) << endl;
	cout << "Завтра:" << date1.getTomorrow() << endl;
	cout << "Предыдущий 25:" << date2.getPast(25) << endl;
	cout << endl;
	
}