#include "Circle.h"
#include <math.h>
Circle::Circle(double rad = 0.0) {
	Circle::setRadius(rad);
}
void Circle::setRadius(double rad) {
	Circle::radius = rad;
	Circle::area = 3.14 * rad * rad;
	Circle::ference = 6.28 * rad;
}
void Circle::setFerence(double fer) {
	Circle::radius = fer / 6.28;
	Circle::area = fer * fer / 19.7192;
	Circle::ference = fer;
}
void Circle::setArea(double area) {
	double rad = sqrt(area / 3.14);
	Circle::radius = rad;
	Circle::area = area;
	Circle::ference = 6, 28 * rad;
}
double Circle::getRadius() {
	return Circle::radius;
}
double Circle::getFerence() {
	return Circle::ference;
}
double Circle::getArea() {
	return Circle::area;
}