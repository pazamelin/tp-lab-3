#include "task1.h"
#include "Circle.h"

double calcDelta() {
	Circle earth = Circle();
	earth.setRadius(6378.1);
	Circle tipe = Circle();
	tipe.setFerence(earth.getFerence() + 0.001);
	double diff = (tipe.getRadius() - earth.getRadius())*1000;
	return int(diff*1000.0)/1000.0;
}

double calcCost() {
	Circle pool = Circle(3);
	Circle fence = Circle(4);
	return ((fence.getArea() - pool.getArea()) * 1000 + (fence.getFerence() * 2000));
}