#include "task1.h"
#include "circle.h"

double calcDelta()
{
	int earthRadius = 6378.1*1000;
	double ferrance, newRadius;
	Circle earth(earthRadius);

	ferrance = earth.getFerence();

	ferrance = ferrance + 1;  //1m of rope was added
	earth.setFerence(ferrance);
	newRadius = earth.getRadius();

	return round((newRadius - earthRadius) * 1000) / 1000;
}

double calcCost()
{
	Circle pool(3);
	Circle track(4);

	double trackCost = (track.getArea() - pool.getArea())*1000;
	double fenceCost = track.getFerence() * 2000;

	return trackCost+fenceCost;
}