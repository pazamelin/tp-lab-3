#include "Circle.h"
#include "task1.h"
#include <math.h>

using namespace std;

const double pi = 3.1415;

Circle::Circle(double NewRadius)
{
	setRadius(NewRadius);

}

void Circle::setRadius(double NewRadius) 
{
	radius = NewRadius;
	ference = 2 * pi * radius;
	area = pi * radius * radius;
}
void Circle::setFerence(double NewFerence) 
{
	ference = NewFerence;
	radius = ference / (2 * pi);
	area = pi * radius * radius;
}
void Circle::setArea(double NewArea) 
{
	area = NewArea;
	radius = sqrt(area / pi);
	ference = 2 * pi * radius;
}
double Circle::getRadius()
{
	return radius;
}
double Circle::getFerence() {
	return ference;
}
double Circle::getArea() {
	return area;
}