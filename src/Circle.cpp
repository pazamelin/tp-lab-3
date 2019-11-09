#define _CRT_SECURE_NO_WARNINGS
#include "task1.h";

Circle::Circle(double value)
{
	radius = value;
	ference = 2 * pi*radius;
	area = pi * radius*radius;
}

void Circle::setRadius(double value)
{
	radius = value;
	ference = 2 * pi*radius;
	area = pi * radius*radius;
}

void Circle::setFerence(double value)
{
	ference = value;
	radius = ference / (2 * pi);
	area = pi * radius*radius;
}

void Circle::setArea(double value)
{
	area = value;
	radius = sqrt(area / (pi));
	ference = 2 * pi*radius;
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