//
// Created by Yakhtin Leonid on 12.11.2019.
//

#ifndef CIRCLE_H
#define CIRCLE_H


class Circle {

double radius, ference, area;

public:
    Circle(double r);
    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);
    double getRadius();
    double getFerence();
    double getArea();
};


#endif //LAB_CIRCLE_H
