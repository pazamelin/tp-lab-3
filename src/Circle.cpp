#include "Circle.h"

Circle::Circle(double rad) {
    this->setRadius(rad);
}

void Circle::setRadius(double rad) {
    radius = rad;
    ference = round (2 * M_PI * radius*10000)/10000;
    area = round (M_PI * (radius * radius)*1000)/1000;
}
void Circle::setFerence(double fer) {
    ference = fer;
    radius = ference / (2 * M_PI);
    area = M_PI * (radius * radius);
}
void Circle::setArea(double ar) {
    area = ar;
    radius = sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
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
