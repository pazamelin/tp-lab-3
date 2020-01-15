#include <iostream>
#include <string>
#include "Circle.h"

double calcDelta()
{
	double earthRadius = 6378100.0;
	double ropeLength = 1.0;

	Circle Earth(earthRadius);
	Earth.setFerence(Earth.getFerence() + ropeLength);
	return Earth.getRadius() - earthRadius;
}
double calcCost()
{
	double coverCost = 1000.0;
	double gardCost = 2000.0;
	Circle swimmingPool(3.0);
	double sp_area = swimmingPool.getArea();
	swimmingPool.setRadius(4.0);
	double roadPrice = (swimmingPool.getArea() - sp_area) * coverCost;
	double wallPrice = swimmingPool.getFerence() * gardCost;
	return roadPrice + wallPrice;
}