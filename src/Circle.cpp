#include "Circle.h"
#include <math.h>

Circle::Circle() : radius(0), ference(0), area(0), PI(3.14)
{

}

Circle::Circle(double r, double pi) : radius(r), ference(0), area(0), PI(pi)
{
	computeFerence();
	computeArea();
}


Circle::~Circle()
{
}

void Circle::setRadius(double r)
{
	radius = r;

	computeFerence();
	computeArea();
}
void Circle::setFerence(double f)
{
	ference = f;

	computeRadiusFromFerence();
	computeArea();
}
void Circle::setArea(double a)
{
	area = a;

	computeRadiusFromArea();
	computeArea();
}


void Circle::computeRadiusFromFerence()
{
	radius = ference / (PI * 2);
}
void Circle::computeRadiusFromArea()
{
	radius = sqrt(area / PI);
}
void Circle::computeFerence()
{
	ference = PI * radius * 2;
}
void Circle::computeArea()
{
	area = PI * radius * radius;
}
