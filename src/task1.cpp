#include "task1.h"
#include "Circle.h"
#include <iomanip>
double calcDelta(){
	const int radius = 6378.1 * 1000.0;//m
	const int delt = 1.0;//m
	Circle first(radius);
	Circle second(radius);
	second.setFerence(first.getFerence() + delt);
	return second.getRadius() - radius;
}

double calcCost() {
	const double FenceCost = 2000.0;
	const double PathCost = 1000.0;
	const double PoolRadius = 3.0;
	const double PoolRadiusWithPath = 4.0;
	Circle pool(PoolRadius);
	Circle poolwp(PoolRadiusWithPath);
	return (poolwp.getArea() - pool.getArea()) * 1000.0 + poolwp.getFerence() * 2000.0;
}