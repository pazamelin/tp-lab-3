#include "Circle.h"
#include <stdio.h>

Circle::Circle(double radius_value) {
    this->setRadius(radius_value);
}

void Circle::setRadius(double radius_value){
    radius = radius_value;
    ference = 2*M_PI*radius_value;
    area = M_PI*radius*radius;
}
void Circle::setFerence(double ference_value){
    ference = ference_value;
    radius = ference/(2*M_PI);
    area = M_PI*radius*radius;
}
void Circle::setArea(double area_value){
    area = area_value;
    radius = sqrt(area/M_PI);
    ference = 2*M_PI*radius;
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
