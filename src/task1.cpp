#include "task1.h"

double calcDelta() {
	double oldRad = 6378100.0;
	Circle Earth(oldRad);
	Earth.setFerence(Earth.getFerence() + 1);
	return Earth.getRadius() - oldRad;
}
double calcCost() {
	double poolRad = 3.0;
	Circle Pool(poolRad);
	Circle Fence(poolRad + 1);
	return (Fence.getArea() - Pool.getArea()) * 1000 + Fence.getFerence() * 2000;
}
