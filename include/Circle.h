#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include <cmath>

class Circle
{
private:
    double radius, ference, area;
    
public:
    Circle(double radius_arg);
    void setRadius(double radius_arg);
    void setFerence(double ference_arg);
    void setArea(double area_arg);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif
