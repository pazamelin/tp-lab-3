#include "DateTime.h"
#include <iostream>

using namespace std;

int main() {
	DateTime date1{1,11,2018};
	DateTime date2{};

	cout <<"date1.getToday(): " << date1.getToday() << endl;
	cout << "date2.getToday(): " << date2.getToday() << endl;
	cout << "Differense between date1 and date2: " << date1.getDifference(date2)<< endl;
	cout << "date1.getTomorrow():" << date1.getTomorrow() << endl;
	cout <<"date2.getPast(25):" << date2.getPast(25) << endl;
	cout << endl;
	DateTime date3{ date1 };
	cout << "date3 = date1" << endl;
	cout << "date3.getToday(): " << date3.getToday() << endl;;
}