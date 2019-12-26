//
// Created by Оксана on 18.11.2019.
//

#include "Circle.h"

double calcDelta(){
    double earth_radius = 6378100;
    Circle earth = Circle(earth_radius);
    earth.setFerence(earth.getFerence() + 1);
    return earth.getRadius()  - earth_radius;
}

double calcCost() {
    double concrete_cost = 1000.0;
    double ference_cost = 2000.0;
    double pool_radius = 3.0;
    double track_width = 1.0;
    Circle pool(pool_radius);
    double pool_area = pool.getArea();
    pool.setRadius(pool_radius + track_width);
    return (pool.getArea() - pool_area) * concrete_cost + pool.getFerence() * ference_cost;





}

