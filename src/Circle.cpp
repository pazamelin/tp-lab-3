#define _USE_MATH_DEFINES 
#include "Circle.h"
#include <cmath>

Circle::Circle(double radius)
{
	setRadius(radius);
}

Circle::~Circle() {}


void Circle::setRadius(double radius)
{
	this->radius = radius;
	this->area = M_PI * radius * radius;
	this->ference = 2 * M_PI * radius;
}


void Circle::setFerence(double ference)
{
	this->ference = ference;
	this->radius = ference / (M_PI * 2);
	this->area = M_PI * this->radius * this->radius;
}


void Circle::setArea(double area)
{
	this->area = area;
	this->radius = sqrt(area / M_PI);
	this->ference = 2 * M_PI * this->radius;
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

