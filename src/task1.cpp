#include "Circle.h"
#include <iostream>
using namespace std;


double calcDelta() {
	const double earthRadius = 6378.1;
	const double deltaRadius = 0.001;
	Circle c{ earthRadius };
	c.setFerence(c.getFerence() + deltaRadius);
	return (c.getRadius() - earthRadius)*1000;
}

double calcCost() {
	const double poolRadius = 3.0;
	const double width = 1.0;
	Circle poolCircle{ poolRadius };
	Circle externalCircle{ poolRadius + width };
	const double roadCost = (externalCircle.getArea() - poolCircle.getArea())* 1000;
	const double fenceCost = externalCircle.getFerence() * 2000;
	return roadCost + fenceCost;
}