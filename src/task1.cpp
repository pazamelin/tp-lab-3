#include "Circle.h"
#include "task1.h"
#include <math.h>
#include <iostream>
double calcDelta() {
	const double EarthRad = 6378.1 * 1000;
	const double addFer = 1.0;
	Circle a{ EarthRad };
	a.setFerence(a.getFerence() + addFer);
	return (a.getRadius() - EarthRad);
}
double calcCost() {
	const double poolRad = 3.0;
	Circle pool{ poolRad };
	Circle poolWroad{ poolRad + 1 };
	double ans = (poolWroad.getArea() - pool.getArea()) * 1000;
	ans += poolWroad.getFerence() * 2000;
	return ans;
}