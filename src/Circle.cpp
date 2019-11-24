#include "Circle.h"
#include <math.h>

Circle::Circle(double radius)
{
	Circle::setRadius(radius);
}

void Circle::setRadius(double radius)
{
	Circle::radius = radius;
	Circle::ference = 2 * pi * radius;
	Circle::area = pi * radius * radius;
}

void Circle::setFerence(double ference)
{
	Circle::ference = ference;
	Circle::radius = ference / (2 * pi);
	Circle::area = (ference * ference) / (4 * pi);
}

void Circle::setArea(double area)
{
	Circle::area = area;
	Circle::radius = sqrt(area / pi);
	Circle::ference = 2 * pi * sqrt(area / pi);
}

double Circle::getRadius()
{
	return Circle::radius;
}

double Circle::getFerence()
{
	return Circle::ference;
}

double Circle::getArea()
{
	return Circle::area;
}