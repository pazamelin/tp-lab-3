#include "Circle.h"
#include "task1.h"

double calcCost() 
{
	double totalCost;
	double poolRad = 3,
		   totalRad = 4,
		   concreteCost = 1000,
		   fenceCost = 2000;

	Circle pool(poolRad);
	Circle general(totalRad);

	totalCost = concreteCost * (general.getArea()
		- pool.getArea()) + general.getFerence() * fenceCost;

	return totalCost;
}

double calcDelta() 
{
	int earthRad = 6378.1 * 1000;
	Circle earth(earthRad);

	double earthLen = earth.getFerence();
	earth.setFerence(earthLen + 1);

	double desRad =  earth.getRadius() - earthRad;

	return round(desRad * 1000) / 1000;
}