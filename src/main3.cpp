#include "DateTime.h"
#include <iostream>


int main()
{
	DateTime d1;
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


	DateTime d2(26, 10, 119); //26 november(10th month from 0) 2019(1900 + 119)
	cout <<"Difference = "<< d1.getDifference(d2) << endl;
	return 0;
}