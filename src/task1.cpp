#include "Circle.h"
#include <cmath>

double calcDelta()
{
	Circle Earth(6378100.0);
	Circle rope(0);
	rope.setFerence((Earth.getFerence() + 1.0));
	return floor((rope.getRadius() - Earth.getRadius())*1000)/1000;
}

double calcCost()
{
	Circle pool(3), road(4);
	return floor((pool.getArea() * 1000 + (road.getArea() - pool.getArea()) * 2000)*100)/100;
}