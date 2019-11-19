//
// Created by Yakhtin Leonid on 12.11.2019.
//

#ifndef CIRCLE_H
#define CIRCLE_H


class Circle {

double radius, ference, area;

public:
    Circle(double r = 0);
    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);
    double getRadius()const;
    double getFerence()const;
    double getArea()const;
};


#endif //LAB_CIRCLE_H
