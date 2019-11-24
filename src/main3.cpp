#include "DateTime.h"
#include <iostream>


int main()
{
	DateTime d1(31, 12, 2019);
	string s = d1.getToday();
	cout <<  "Today: " << s << endl;
	s = d1.getFuture(10);
	cout << "10 days after:" << s << endl;
	s = d1.getPast(10);
	cout << "10 days before:" << s << endl;
	s = d1.getTomorrow();
	cout << "Tomorrow: " << s << endl;
	s = d1.getYesterday();
	cout << "Yesterday: " << s << endl; 


	DateTime d2(26, 11, 2019);
	cout <<"Difference = "<< d1.getDifference(d2) << endl;
	
	return 0;
}
