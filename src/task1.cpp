#include "Circle.h"

double calcDelta()
{
	Circle Earth(6378100.0);
	Circle rope(0);
	rope.setFerence((Earth.getFerence() + 1.0));
	return rope.getRadius() - Earth.getRadius();
}

double calcCost()
{
	Circle pool(3), road(4);
	return pool.getArea() * 1000 + road.getArea() * 2000;
}