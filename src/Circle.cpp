#include "Circle.h"
#include <math.h>
#define M_PI 3.1415

Circle::Circle(double radius) {
	setRadius(radius);
}

Circle::Circle() {
	setRadius(0);
}

Circle::~Circle()
{
}

void Circle::setRadius(double radius) {
	if (radius >= 0) {
		this->radius = radius;
		this->area = M_PI * radius * radius;
		this->ference = 2 * M_PI * radius;
	}
}

void Circle::setFerence(double ference) {
	if (ference >= 0) {
		this->ference = ference;
		this->radius = ference / (2 * M_PI);
		this->area = M_PI * radius * radius;
	}
}

void Circle::setArea(double area) {
	if (area >= 0) {
		this->area = area;
		this->radius = sqrt(area / M_PI);
		this->ference = 2 * this->radius * M_PI;
	}
}

double Circle::getArea() {
	return this->area;
}

double Circle::getFerence() {
	return this->ference;
}

double Circle::getRadius() {
	return this->radius;
}