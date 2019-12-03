#include "Circle.h"
#include <math.h>
#define pi 3.1415

Circle::Circle(double _radius)
{
	Circle::setRadius(_radius);
}

void Circle::setRadius(double _radius)
{
	radius = _radius;
	ference = 2 * pi * _radius;
	area = pi * _radius * _radius;
}

void Circle::setFerence(double _ference)
{
	ference = _ference;
	radius = _ference / (2 * pi);
	area = pi * radius * radius;
}

void Circle::setArea(double _area)
{
	area = _area;
	radius = sqrt(_area / pi);
	ference = 2 * pi * radius;
}

double Circle::getRadius()
{
	return radius;
}

double Circle::getFerence()
{
	return ference;
}

double Circle::getArea()
{
	return area;
}
