#include"Circle.h"
#include<math.h>

void Circle::setRadius(double Radius) {
	radius = Radius;
	ference = 2 * 3.14 * Radius;
	area = 3.14 * Radius * Radius;
}

Circle::Circle(double Radius) {
	setRadius(Radius);
}

void Circle::setFerence(double Ference) {
	ference = Ference;
	radius = Ference / (2 * 3.14);
	area = 3.14 * radius * radius;
}

void Circle::setArea(double Area) {
	area = Area;
	radius = sqrt(Area / 3.14);
	ference = 2 * 3.14 * radius;
}

double Circle::getRadius() {
	return radius;
}

double Circle::getFerence() {
	return ference;
}

double Circle::getArea() {
	return area;
}