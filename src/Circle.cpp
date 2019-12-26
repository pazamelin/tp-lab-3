//
// Created by aklen on 10.11.2019.
//
#include <iostream>
#include "Circle.h"
#include "math.h"
#define math_pi 3.14159
using namespace std;

Circle::Circle(double radius){
    this->radius=radius;
    this->ference=2*math_pi*this->radius;
    this->area=math_pi*this->radius*this->radius;
}
void Circle::setRadius(double current_r){
    this->radius=current_r;
    this->ference=2*math_pi*this->radius;
    this->area=math_pi*this->radius*this->radius;
}


void Circle::setFerence(double current_cf){
    this->ference=current_cf;
    this->radius=this->ference/(2*math_pi);
    this->area=this->radius*this->radius*math_pi;
}


void Circle::setArea(double current_a){
    this->area=current_a;
    this->radius=sqrt(this->area/math_pi);
    this->ference=2*math_pi*this->radius;
}

double Circle::getRadius(){
    return this->radius;
}

double Circle::getFerence(){
    return round(this->ference*1000)/1000;
}

double Circle::getArea(){
    return round(this->area*1000)/1000;
}
