#include "Circle.h"

Circle::Circle(double radius_arg)
{
    this->setRadius(radius_arg);
}
void Circle::setRadius(double radius_arg)
{
    radius = radius_arg;
    ference = round(2 * M_PI * radius);
    area = round(M_PI * (radius * radius));
}
void Circle::setFerence(double ference_arg)
{
    ference = ference_arg;
    radius = ference / (2 * M_PI);
    area = M_PI * (radius * radius);
}
void Circle::setArea(double area_arg)
{
    area = area_arg;
    radius = sqrt(area / M_PI);
    ference = 2 * M_PI * radius;
}
double Circle::getRadius()
{
    return radius;
}
double Circle::getFerence()
{
    return ference;
}
double Circle::getArea()
{
    return area;
}
