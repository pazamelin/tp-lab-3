#include "Circle.h"

#define PI 3.1415

Circle::Circle(double ray) 
{
	radius = ray;
	ference = 2 * PI * radius;
	area = PI * pow(radius, 2);
}

void Circle::setRadius(double ray) 
{
	radius = ray;
	ference = 2 * PI * radius;
	area = PI * pow(radius, 2);
}

void Circle::setFerence(double circuit)
{
	ference = circuit;
	radius = ference / (2 * PI);
	area = PI * pow(radius, 2);
}

void Circle::setArea(double square)
{
	area = square;
	radius = sqrt(area / PI);
	ference = 2 * PI * radius;
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