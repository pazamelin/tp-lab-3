#include "task1.h"
#include "Circle.h"

double calcDelta()
{
	double earthRadius = 6378.1 * 1000; //meters
	Circle roap1(earthRadius);
	Circle roap2(earthRadius);
	roap2.setFerence(roap2.getFerence() + 1);
	return roap2.getRadius() - roap1.getRadius();
}

double calcCost()
{
	Circle pull(3);
	Circle pullWithRoad(3 + 1);
	return 2000 * pullWithRoad.getFerence() + (pullWithRoad.getArea() - pull.getArea()) * 1000;
}