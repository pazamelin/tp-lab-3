#include "task1.h"
#include "Circle.h"
#include <iostream>
using namespace std;

double calcDelta()
{
	Circle earth(6378.1 * 1000);
	cout << "task 1:" << endl;
	Circle c2(1);
	c2.setFerence(earth.getFerence() + 1);
	double dif = c2.getRadius() - earth.getRadius();
	return round(dif * 1000)/1000;
}

double calcCost()
{
	Circle swimp(3);
	Circle swimparea(swimp.getRadius() + 1);
	double costfloor = 1000 * (swimparea.getArea() - swimp.getArea());
	double costfence = 2000 * swimparea.getFerence();
	return costfence + costfloor;
}