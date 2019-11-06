//
// Created by fiskirton on 11/5/19.
//

#include "Circle.h"

Circle::Circle(double radius) {

    this->radius = radius;
    this->calcFerence();
    this->calcArea();

}

void Circle::calcRadiusFromFerence(double val) {
    this->radius = val / (2 * pi);
}

void Circle::calcRadiusFromArea(double val) {
    this->radius = sqrt(val / pi);
}

void Circle::calcFerence() {
    double res = 2 * pi * (this->radius);
    this->ference = res;

}

void Circle::calcArea() {
    double res = pi * pow(this->radius, 2);
    this->area = res;
}

