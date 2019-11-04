//
// Created by Mary on 04.11.2019.
//
#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

double calcDelta(){
    Circle* Earth = new Circle(6378100);
    Circle* EarthDelta = new Circle(*Earth);
    EarthDelta->setFerence(Earth->getFerence()+1);
    return round((EarthDelta->getRadius() - Earth->getRadius())*1000)/1000;
}
double calcCost(){
    Circle* Pool = new Circle(3);
    Circle* PoolRoad = new Circle(Pool->getRadius()+1);
    double costRoad = (PoolRoad->getArea() - Pool->getArea())*1000;
    double costFence = PoolRoad->getFerence()*2000;
    return costFence+costRoad;
}
