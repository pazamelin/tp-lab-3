#include "task1.h"
#include "Circle.h"

double calcDelta()
{
	double earthRadius = 6378.1 * 1000;
	Circle earthFerence(earthRadius);
	Circle roap(earthRadius);
	roap.setFerence(roap.getFerence() + 1);
	return roap.getRadius() - earthFerence.getRadius();
}

double calcCost()
{
	Circle pool(3);
	Circle fence (pool.getRadius() + 1);
	return  1000 * (fence.getArea() - pool.getArea()) + 2000 * fence.getFerence();
}
