//
// Created by fiskirton on 11/5/19.
//
#include <cmath>
#include "Circle.h"

double calcDelta(){
    double radius = 6378.1;
    auto *rope =  new Circle(radius);
    rope->setFerence(rope->getFerence() + 1.0);
    double res = rope->getRadius() - radius;
    delete rope;
    return floor(res*pow(10, 3) + 0.5) / pow(10, 3);
}

double calcCost(){
    double pool_radius = 3.0;
    double path_width = 1.0;
    double path_cost = 1000.0;
    double fence_cost = 2000.0;
    auto *pool = new Circle(pool_radius);
    auto *full_pool = new Circle(pool_radius + path_width);
    double path_full_cost = path_cost * (full_pool->getNotFlooredArea() - pool->getNotFlooredArea());
    double fence_full_cost = fence_cost * (full_pool->getNotFlooredFerence());//50264
    delete pool;
    delete full_pool;
    return path_full_cost + fence_full_cost;
}