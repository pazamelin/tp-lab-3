#include "Circle.h"
#include <math.h>
#include <iostream>

using namespace std;


const double pi = 3.1415;

Circle::Circle(double newRad) {
	radius = newRad;
	ference = 2 * pi * newRad;
	area = pi * newRad * newRad;
}

void Circle::setRadius(double newRad) {
	radius = newRad;
	ference = 2 * pi * newRad;
	area = pi * newRad * newRad;
}

void Circle::setFerence(double newFer) {
	ference = newFer;
	radius = newFer / (2 * pi);
	area = (newFer * newFer) / (4 * pi);
}


void Circle::setArea(double newArea) {
	area = newArea;
	radius = sqrt(newArea / pi);
	ference = 2 * ference / radius;
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