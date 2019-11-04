//
// Created by Mary on 04.11.2019.
//

#include "../include/Circle.h"
#include <math.h>
using namespace std;
Circle::Circle(double radius){
    this->radius = radius;
    this->area = M_PI*this->radius*this->radius;
    this->ference = 2*M_PI*this->radius;
}
Circle::Circle(const Circle& circle): Circle(circle.radius) {
    this->ference = circle.ference;
    this->area = circle.area;
}

void Circle::setRadius(double cur_radius){
    this->radius = cur_radius;
    this->area = M_PI*this->radius*this->radius;
    this->ference = 2*M_PI*this->radius;
}

void Circle::setFerence(double cur_ference){
    this->ference = cur_ference;
    this->radius = this->ference/(2*M_PI);
    this->area = M_PI*this->radius*this->radius;
}

void Circle::setArea(double cur_area){
    this->area = cur_area;
    this->radius = sqrt(this->area/M_PI);
    this->ference = this->ference = 2*M_PI*this->radius;
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