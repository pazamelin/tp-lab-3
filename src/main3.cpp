#include <iostream>
#include <ctime>
#include "DateTime.h"
#include <string>
using namespace std;
int main()
{
	DateTime bd(05, 02, 2000);
	DateTime td;
	cout << "today " << td.getToday() << endl;
	cout << "yesterday " << td.getYesterday() << endl;
	cout << "tomorrow " << td.getTomorrow() << endl;
	cout << "9 days before my birthday " << bd.getPast(9) << endl;
	cout << "9 days after my birthday " << bd.getFuture(9) << endl;
	cout << "days from birthday lost " << bd.getDifference(td) << endl;
	return 0;
}
