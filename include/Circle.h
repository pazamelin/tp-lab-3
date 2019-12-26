//
// Created by Оксана on 18.11.2019.
//

#ifndef TASK1_CIRCLE_H
#define TASK1_CIRCLE_H

class Circle{
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
        double r();
};

#endif //TASK1_CIRCLE_H
