//
//  Circle.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "Circle.h"
//#define M_PI 3.1415

Circle::Circle(double rad) {
    _radius = rad;
    _ference = 2 * M_PI * _radius;
    _area = M_PI * pow(_radius, 2);
}

void Circle::setRadius(double x) {
    _radius = x;
    _ference = 2 * M_PI * _radius;
    _area = M_PI * pow(_radius, 2);
}

void Circle::setFerence(double x) {
    _ference = x;
    _radius = _ference / (2 * M_PI);
    _area = M_PI * pow(_radius, 2);
}

void Circle::setArea(double x) {
    _area = x;
    _radius = sqrt(_area / M_PI);
    _ference = 2 * M_PI * _radius;
}

double Circle::getRadius() {
    return _radius;
}

double Circle::getArea() {
    return _area;
}

double Circle::getFerence() {
    return _ference;
}


