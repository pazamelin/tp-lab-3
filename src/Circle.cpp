//
// Created by Mikhail on 12.11.2019.
//

#include "Circle.h"

Circle::Circle(double newRadius) {
    radius = newRadius;
    this->recalculation();
}

void Circle::setFerence(double newFerence) {
    radius = newFerence / (2.0 * pi);
    this->recalculation();
}

void Circle::setRadius(double newRadius) {
    radius = newRadius;
    this->recalculation();
}

void Circle::setArea(double newArea) {
    radius = sqrt(newArea / pi);
    this->recalculation();
}

void Circle::recalculation() {
    ference = 2.0 * pi * radius;
    area = pi * radius * radius;
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


