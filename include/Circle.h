#ifndef TPLAB3TASK1_CIRCLE_H
#define TPLAB3TASK1_CIRCLE_H
#include <string>
#include <math.h>
#pragma once

class Circle{
public:
    Circle(double inputRadius){
        radius= inputRadius;
        ference=2.0*M_PI*radius;
        area=M_PI*radius*radius;
    }
    void setRadius(double circle_radius);
    double getRadius();
    void setFerence(double circle_frence);
    double getFerence();
    void setArea(double circle_area);
    double getArea();


private:
    double radius;
    double ference;
    double area;

};

#endif //TPLAB3TASK1_CIRCLE_H
