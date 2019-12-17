#include "Circle.h"
#include <math.h>

void Circle::setRadius(double circle_radius){
    radius=circle_radius;
    ference=2.0*M_PI*radius;
    area=M_PI*radius*radius;
}


double Circle::getRadius() {
    return Circle::radius;
}

void Circle::setFerence(double circle_ference){
    ference=circle_ference;
    radius=ference/(2.0*M_PI);
    area=M_PI*radius*radius;
}

double Circle::getFerence() {
    return round(this->ference*1000)/1000;
}


void Circle::setArea(double circle_area) {
    area=circle_area;
    radius=sqrt(area/M_PI);
    ference=2.0*M_PI*radius;
}


double Circle::getArea() {
    return round(this->area*1000)/1000;
}

