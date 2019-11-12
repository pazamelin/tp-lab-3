#include <cmath>
#include "Circle.h"

Circle::Circle(double radius)
{
	this->radius = radius;
	this->ference = 2 * Pi * radius;
	this->area = Pi * pow(radius, 2);
};

double Circle::getRadius()
{
	return this->radius;
};
void Circle::setRadius(double radius)
{
	this->radius = radius;
	this->ference = 2.0 * Pi * radius;
	this->area = Pi * pow(radius, 2.0);
};
double Circle::getFerence()
{
	return this->ference;
};
void Circle::setFerence(double ference)
{
	this->radius = ference / (2.0 * Pi);
	this->ference = ference;
	this->area = Pi * pow(ference / (2.0 * Pi), 2.0);
};
double Circle::getArea()
{
	return this->area;
};
void Circle::setArea(double area)
{
	this->radius = pow(area / Pi, 1.0 / 2.0);
	this->ference = 2.0 * Pi * pow(area / Pi, 1.0 / 2.0);
	this->area = area;
};
