#include"Circle.h"
#include <cmath>
#include <iostream>

const double PI = 3.1415926535;

void Circle::setRadius(double rad){
	radius = rad;
	ference = 2 * PI * rad;
	area = PI * pow(rad, 2);
}

void Circle::setFerence(double fer) {
	ference = fer;
	radius = fer / (2 * PI);
	area = PI * pow(radius, 2);

}

void Circle::setArea(double are) {
	area = are;
	radius = sqrt(area / PI);
	ference = 2 * PI * radius;
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