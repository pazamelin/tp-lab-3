#include "Circle.h"
#include <math.h>
#define PI 3.1415

void Circle::setRadius(double R)
{
	radius = round2(R);
	area = round2(PI * R * R);
	ference = round2(2 * PI * R);
}

void Circle::setArea(double A)
{
	double R = sqrt(A / PI);
	area = round2(A);
	radius = round2(R);
	ference = round2(2 * PI * R);
}

void Circle::setFerence(double F)
{
	double R = (F / (2 * PI));
	ference = round2(F);
	radius = round2(R);
	this->area = round2(PI * R * R);
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

double Circle::round2(double R)
{
	return round(R * 1000) / 1000;
}