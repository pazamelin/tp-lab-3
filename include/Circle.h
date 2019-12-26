//
// Created by aklen on 10.11.2019.
//
#include <iostream>

class Circle{
private:
    double radius;
    double ference;
    double area;
public:
    Circle(double radius);
    void setRadius(double radius);
    void setFerence(double ference);
    void setArea(double area);
    double getRadius();
    double getFerence();
    double getArea();
};