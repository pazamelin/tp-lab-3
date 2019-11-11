#include <math.h>
#define pi 3.14159265359
#include "Ñircle.h"

Circle::Circle(double r)
{
	radius = r;
	ference = 2 * pi * r;
	area = pi * r * r;
}
void Circle::setRadius(double r)
{
	radius = r;
	ference = 2 * pi * r;
	area = pi * r*r;
}
void Circle::setFerence(double f)
{
	ference = f;
	radius = f / (2 * pi);
	area = pi * radius * radius;
}
void Circle::setArea(double a)
{
	area = a;
	radius = sqrt(a / pi);
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