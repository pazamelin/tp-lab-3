//
// Created by Илья on 005 05.11.19.
//
#include "task1.h"
#include "Circle.h"

double calcDelta(){
    double earthRadius = 6378.1;
    Circle ropeCircle = Circle(earthRadius);
    ropeCircle.setFerence(ropeCircle.getFerence() + 1);
    return ropeCircle.getRadius() - earthRadius;
}

double calcCost(){
    double concreteCostPerSquareMeter = 1000;  // in Russian rubles
    double  fenceCostPerMeter = 2000;
    double radius = 3;
    Circle pool = Circle(radius);
    double poolArea = pool.getArea();
    pool.setRadius(radius + 1);
    return fenceCostPerMeter * pool.getFerence() + (pool.getArea() - poolArea) * concreteCostPerSquareMeter;
}