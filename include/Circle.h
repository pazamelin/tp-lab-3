#ifndef INC_1_CIRCLE_H
#define INC_1_CIRCLE_H

#include <cmath>

class Circle {
private:
    double radius,
           ference,
           area;
public:
    Circle(double rad);

    void setRadius(double rad);
    void setFerence(double fer);
    void setArea(double ar);
    double getRadius();
    double getFerence();
    double getArea();
};


#endif //INC_1_CIRCLE_H
