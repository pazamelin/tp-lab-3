#include "task1.h"
#include "Circle.h"

double calcDelta()
{
	double earthRadius = 6378.1;
	Circle circle(6378.1);
	circle.setFerence(circle.getFerence() + 1);
	return circle.getRadius() - earthRadius;
};
double calcCost()
{
	Circle innerCircle(3.0);
	Circle outerCircle(3.0 + 1.0);
	return 1000.0 * (outerCircle.getArea() - innerCircle.getArea()) + (2000.0 * outerCircle.getFerence());
};