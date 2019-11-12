//
// Created by Mikhail on 12.11.2019.
//

#ifndef TASK1_CIRCLE_H
#define TASK1_CIRCLE_H

#include <cmath>

class Circle{
public:
    Circle(double newRadius);
    void setRadius(double newRadius);
    void setFerence(double newFerence);
    void setArea(double newArea);
    void recalculation();
    double getRadius();
    double getFerence();
    double getArea();
private:
    double pi = acos(-1);
    double radius{};
    double ference{};
    double area{};
};

#endif //TASK1_CIRCLE_H
