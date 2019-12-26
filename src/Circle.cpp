//
// Created by Оксана on 18.11.2019.
//
#include <cmath>
#include "Circle.h"
#define pi acos(-1)

Circle::Circle(double new_radius) {
    this->setRadius(new_radius);
}

void Circle::setRadius(double new_radius) {
    radius = new_radius;
    ference = 2 * pi * radius;
    area = pi * radius * radius;
}

void Circle::setFerence(double new_ference) {
    ference = new_ference;
    radius = ference / (2 * pi);
    area = pi * radius * radius;
}

void Circle::setArea(double new_area) {
    area = new_area;
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





