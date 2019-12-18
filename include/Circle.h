#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include <cmath>

class Circle{
private:
    double radius;
    double ference;
    double area;
public:
    Circle(double radius_value);
    void setRadius(double radius_value);
    void setFerence(double ference_value);
    void setArea(double area_value);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif /* Circle_h */
