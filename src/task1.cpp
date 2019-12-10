#include "task1.h"
#include "Circle.h"

double calcDelta(){
    Circle earth(6378100.0);
    double earthRad = 6378100.0;
    earth.setFerence(earth.getFerence() + 1);
    return earth.getRadius() - earthRad;
}

double calcCost() {
    Circle poolInside(3.0);
    Circle poolOutside(4.0);
    return (poolOutside.getArea() - poolInside.getArea()) * 1000.0 + poolOutside.getFerence() * 2000.0;
}
