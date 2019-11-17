#include "task1.h"
#include "Circle.h"

double calcDelta()
{
	double radius = 6378.1 * 1000;
	Circle Earth(radius, 3.1415);
	Earth.setFerence(Earth.getFerence() + 1);
	double delta = Earth.getRadius() - radius;
	delta = int(delta * 1000 + 0.5) / 1000.0; // Less acuracy to provide consistant tests output
	return delta;

}

double calcCost()
{
	Circle pool(3, 3.1415);
	Circle pool_fence(4, 3.1415);

	double concrete_area = pool_fence.getArea() - pool.getArea();
	double fence_len = pool_fence.getFerence();

	return concrete_area * 1000 + fence_len * 2000;

}