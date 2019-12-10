//
// Created by aklen on 10.11.2019.
//
#include <iostream>
#include "circle.h"
#include "math.h"
#define math_pi 3.14
using namespace std;

double calcDelta(){
    int earthR=6378.1*1000;
    double  newFerence,newRadius;
    Circle earth(earthR);
    newFerence=earth.getFerence();
    newFerence=newFerence+1;
    earth.setFerence(newFerence);
    newRadius=earth.getRadius();
    return round((newRadius-earthR)*1000)/1000;
}

double calcCost(){
    Circle pool(3);
    Circle track(4);
    double fenceCost=track.getFerence()*2000;
    double trackCost=(track.getArea()-pool.getArea())*1000;
    return (fenceCost+trackCost);
}
