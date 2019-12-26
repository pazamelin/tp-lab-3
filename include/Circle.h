//
// Created by Илья on 005 05.11.19.
//

#ifndef TP_LAB_3_CIRCLE_H
#define TP_LAB_3_CIRCLE_H

class Circle {
private:
    double radius;
    double ference;
    double area;
public:
    Circle(double);
    void setRadius(double);
    void setFerence(double);
    void setArea(double);
    double getRadius();
    double getFerence();
    double getArea();
};


#endif //TP_LAB_3_CIRCLE_H
