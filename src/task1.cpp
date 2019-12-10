#include "Circle.h"
void calcDelta() {
	double rad = 6378.1;
	Circle planet(rad), newPlanet(0);
	newPlanet.setFerence(planet.getFerence() + 0.1);
	return newPlanet.getRadius() - planet.getRadius();
}
void calcCost() {
	Circle pool(3), road(4);
	double cost = (road.getArea() - pool.getArea()) * 1000;
	cost += road.getFerence() * 2000;
	return cost;
}