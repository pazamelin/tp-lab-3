//
// Created by Mikhail on 12.11.2019.
//

#include "task1.h"


double calcDelta(){
    double EarthRadius = 6378.1;
    Circle rope(EarthRadius);
    rope.setFerence(rope.getFerence() + 1.0);
    return rope.getRadius() - EarthRadius;
}

double calcCost(){
    double r = 3.0;
    double concreteCost = 1000.0; // per square
    double fenceCost = 2000.0;
    Circle pool(r);
    double area = pool.getArea();
    pool.setRadius(r + 1);
    double fullCost = fenceCost * pool.getFerence() + (pool.getArea() - area) * concreteCost;
    return fullCost;
}