#include "Circle.h"
#include <cmath>
#define pi 3.1415
Circle::Circle(double _radius)
{
	radius = _radius;
	area = pi * radius * radius;
	ference = 2.0 * pi * radius;
}

void Circle::setRadius(double _radius)
{
	radius = _radius;
	area = pi * radius * radius;
	ference = 2.0 * pi * radius;
}

void Circle::setFerence(double _ference)
{
	ference = _ference;
	radius = ference / (2.0 * pi);
	area = pi * radius * radius;
}

void Circle::setArea(double _area)
{
	area = _area;
	radius = sqrt(area / pi);
	ference = 2.0 * pi * radius;
}

double Circle::getRadius() const
{
	return radius;
}

double Circle::getFerence() const
{
	return ference;
}

double Circle::getArea() const
{
	return area;
}



