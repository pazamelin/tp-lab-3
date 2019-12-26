#include "task1.h"

double calcDelta() 
{
	double Earth_radius = 6378100,
		Earth_ference,
		circle_ference,
		circle_radius,
		gap;

	Circle Earth(Earth_radius);
	Circle circle(0);

	Earth_ference = Earth.getFerence();
	circle_ference = Earth_ference + 1;
	circle.setFerence(circle_ference);

	circle_radius = circle.getRadius();
	gap = circle_radius - Earth_radius;

	return gap;
}

double calcCost()
{
	int price_concrete = 1000,
		price_fence = 2000;
	double r = 3,
		width = 1,
		length_fence,
		area_concrete,
		cost_concrete,
		cost_fence;

	Circle pool(r);
	Circle way(r + width);

	length_fence = way.getFerence();
	cost_fence = length_fence * price_fence;

	area_concrete = way.getArea() - pool.getArea();
	cost_concrete = area_concrete * price_concrete;

	return (cost_concrete + cost_fence);
}