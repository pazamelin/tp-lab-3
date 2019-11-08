#include "task1.h"
#include "Circle.h"
#include <iomanip>
double calcDelta(){
	const int radius = 6378.1 * 1000;//m
	const int delt = 1;//m
	Circle first(radius);
	Circle second(radius);
	second.setFerence(first.getFerence() + delt);
	return second.getRadius() - radius;
}

double calcCost() {
	const int FenceCost = 2000;
	const int PathCost = 1000;
	const int PoolRadius = 3;
	const int PoolRadiusWithPath = 4;
	Circle pool(PoolRadius);
	Circle poolwp(PoolRadiusWithPath);
	return (poolwp.getArea() - pool.getArea()) * 1000 + poolwp.getFerence() * 2000;
}