#ifndef _CIRCLE_H
#define _CIRCLE_H_

class Circle {
    private:
        double radius;
        double ference;
        double area;
    public:
        Circle(double radius);
        double getRadius();
        double getFerence();
        double getArea();
        void setRadius(double radius);
        void setArea(double area);
        void setFerence(double ference);
};

#endif
