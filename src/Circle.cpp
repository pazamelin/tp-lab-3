#include "Circle.h"
#include <iostream>
#include <math.h>
#define pi 3.1415

Circle::Circle(double radius){
    this->radius = radius;
    this->ference = 2 * pi * radius;
    this->area = pi * radius * radius;
}

void Circle::setArea(double area) {
    this->area = area;
    this->radius = sqrt(area/pi);
    this->ference = 2 * pi * radius;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
    this->area = pi * radius * radius;
    this->ference = pi * 2 * radius;
}

void Circle::setFerence(double ference) {
    this->ference = ference;
    this->radius = ference/(2 * pi);
    this->area = pi * radius * radius;
}

double Circle::getRadius(){
    return this->radius;
}

double Circle::getFerence(){
    return this->ference;
}

double Circle::getArea(){
    return this->area;
}
