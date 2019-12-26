#include "Circle.h"
#include <cmath>

const double pi = 3.1415;

Circle::Circle(double in_Rad){
	setRadius(in_Rad);
}

void Circle::setRadius(double in_Rad){
	radius = in_Rad;
	ference = 2 * pi * radius;
	area = pi * pow(radius, 2);
}

void Circle::setFerence(double in_Fer){
	ference = in_Fer;
	radius = ference / (2 * pi);
	area = pi * pow(radius, 2);
}

void Circle::setArea(double in_Ar){
	area = in_Ar;
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