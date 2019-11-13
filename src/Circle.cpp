#include <math.h>
#include "Circle.h"

const double pi = 3.14;

Circle::Circle(double r) {
	radius = r;
	ference = 2 * pi * r;
	area = pi * r * r;
}
void Circle::setRadius(double r) {
	radius = r;
	ference = 2 * pi * r;
	area = pi * r * r;
}
void Circle::setFerence(double f) {
	ference = f;
	radius = f / (2 * pi);
	area = radius * radius * pi;
}
void Circle::setArea(double a) {
	area = a;
	radius = sqrt(a / pi);
	ference = 2 * pi * radius;
}
double Circle::getRadius() const {
	return radius;
}
double Circle::getFerence() const {
	return ference;
}
double Circle::getArea() const {
	return area;
}

	