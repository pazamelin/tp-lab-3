//
// Created by Илья Соловьёв on 04.11.2019.
//

#include <Circle.h>
#include "task1.h"

double calcDelta() {
    Circle *earth = new Circle(6378.1);
    double radius = earth->getRadius();
    earth->setFerence(earth->getFerence() + 1);
    return earth->getRadius() - radius;
}

double calcCost() {
    Circle *pool = new Circle(3);
    double area = pool->getArea();
    pool->setRadius(4);
    return ((pool->getArea() - area)*100)/100.0 * 1000 + ((pool->getFerence()*100)/100.0) * 2000;
}