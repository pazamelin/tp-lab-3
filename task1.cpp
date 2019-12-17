#include <iostream>
#include "Circle.h"
#include "task1.h"

using namespace std;

double calcDelta(){
    double earthRad = 6378.1;
    Circle rope(earthRad);
    double newFerence = rope.getFerence() + 1;
    rope.setFerence(newFerence);
    double gap=rope.getRadius()-earthRad;
    return gap;


}
double calcCost(){
    Circle pool(3.0);
    double areaSmall=pool.getArea();
    pool.setRadius(pool.getRadius()+1);
    double areaBig=pool.getArea();
    double costTrack=(areaBig-areaSmall)*1000;
    double costFence=pool.getFerence()*2000;
    return costFence+costTrack;
}