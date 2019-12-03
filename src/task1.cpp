//
// Created by Илья Соловьёв on 04.11.2019.
//

#include <Circle.h>
#include "task1.h"

double calcDelta() {
    Circle *earth = new Circle(6378.1);
    double radius = earth->getRadius();
    earth->setFerence(earth->getFerence() + 1);
    double res = int((earth->getRadius() - radius) * 1000) / 1000.0;
    return res;
}

double calcCost() {

    Circle* Pool = new Circle(3);
    Circle* PoolRoad = new Circle(Pool->getRadius()+1);
    double costRoad = (PoolRoad->getArea() - Pool->getArea())*1000.0;
    double costFence = PoolRoad->getFerence()*2000.0;
    return int((costFence+costRoad)*1000)/1000.0;
}