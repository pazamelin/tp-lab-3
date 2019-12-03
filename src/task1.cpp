#include "task1.h"
#include "Circle.h"
#include <iostream>
using namespace std;

double calcDelta()
{
	Circle earth(6378.1 * 1000);
	Circle c2(1);
	c2.setFerence(earth.getFerence() + 1);
	double dif = c2.getRadius() - earth.getRadius();
	return round(dif * 1000)/1000;
}

double calcCost()
{
	Circle swimp(3000);
	Circle swimparea(4000);
	double costfloor = 0.001 * (swimparea.getArea() - swimp.getArea());
	double costfence = 2.0 * swimparea.getFerence();
	return costfloor + costfence ;
}