#include "Circle.h"
#include <iostream>
void calcDelta() {
	double rad = 6378.1;
	Circle planet(rad), newPlanet(0);
	newPlanet.setFerence(planet.getFerence() + 0.1);
	std::cout << newPlanet.getRadius() - planet.getRadius() << std::endl;
}
void calcCost() {
	Circle pool(3), road(4);
	double cost = (road.getArea() - pool.getArea()) * 1000;
	cost += road.getFerence() * 2000;
	std::cout << cost << std::endl;
}