#include "Circle.h"
#include <math.h>

const double pi = 3.14159265;

Circle::Circle(double newrad) {
	setRadius(newrad);
}

void Circle::setRadius(double newrad) {
	radius = newrad;
	ference = 2 * pi * newrad;
	area = pi * newrad * newrad;
}

void Circle::setFerence(double newfer) {
	ference = newfer;
	radius = ference / 2 / pi;
	area = pi * radius * radius;
}

void Circle::setArea(double newarea) {
	area = newarea;
	radius = sqrt(area / pi);
	ference = 2 * pi * radius;
}

double Circle::getRadius(){
	return radius;
}

double Circle::getFerence(){
	return ference;
}

double Circle::getArea(){
	return area;
}