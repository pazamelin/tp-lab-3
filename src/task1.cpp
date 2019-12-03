#include "Circle.h"

double calcDelta()
{
	double earth_radius = 6378100.0;
	Circle rope(earth_radius);
	rope.setFerence(rope.getFerence() + 1.0);

	return rope.getRadius() - earth_radius;
}
double calcCost()
{
	double pool_radius = 3.0;
	Circle pool(pool_radius);
	Circle pool_with_fence(pool_radius + 1.0);

	return (pool_with_fence.getArea() - pool.getArea()) * 1000 + pool_with_fence.getFerence() * 2000;
}
