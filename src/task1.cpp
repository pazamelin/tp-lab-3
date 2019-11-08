#include "task1.h"
#include "Circle.h"
double calcDelta() {
	double radiusEarth = 6378100.0;
	Circle a(radiusEarth);
	Circle b = a;
	a.setFerence(a.getFerence() + 1);
	return a.getRadius() - b.getRadius();
}
double calcCost() {
	Circle a(3.0);
	Circle b(4.0);
	double sum = 0;
	sum += (b.getArea() - a.getArea()) * 1000.0;
	sum += b.getFerence() * 2000.0;
	return sum;
}
