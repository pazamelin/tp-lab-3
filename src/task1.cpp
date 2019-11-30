#include "task1.h"
#include "Circle.h"

double calcDelta() {
	Circle* earth = new Circle();
	earth->setRadius(6378100.0);
	Circle* tipe = new Circle();
	tipe->setFerence(earth->getFerence() + 1);
	double diff = tipe->getRadius() - earth->getRadius();
	diff = diff - (int)(diff * 1000);
	return diff;
}

double calcCost() {
	Circle* pool = new Circle();
	Circle* track = new Circle();
	pool->setRadius(3);
	track->setRadius(4);
	double cost = ((track->getArea() - pool->getArea()) * 1000) + (pool->getFerence() * 2000);
	return cost;
}