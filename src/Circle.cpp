#include "Circle.h"
#include <math.h>
#define PI 3.14159265
//F=2piR S=piR**2

double Circle::getRadius() {
	return radius;
}

double Circle::getFerence() {
	return ference;
}

double Circle::getArea() {
	return area;
}

void  Circle::setRadius(double _radius) {
	radius = _radius;
	ference = _radius*2*PI;
	area = _radius* _radius*PI;
}

void  Circle::setFerence(double _ference) {
	ference = _ference;
	radius = _ference/(2*PI);
	area = radius * radius * PI;
}

void  Circle::setArea(double _area){
	area = _area;
	radius = sqrt(_area/PI);
	ference = radius * 2 * PI;
}

Circle::Circle(double _radius) {
	setRadius(_radius);
}
