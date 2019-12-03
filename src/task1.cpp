//
// Created by Yakhtin Leonid on 12.11.2019.
//

#include "task1.h"

double calcDelta(){
    Circle cir(6378100);
    double r = cir.getRadius();
    cir.setFerence(cir.getFerence()+1);
    return cir.getRadius()-r;
}

double calcCost(){
    Circle pool(3), pool1(4);
    double areaCost = 1000;
    double ferenceCost = 2000;
    double cost = (pool1.getArea()-pool.getArea())*areaCost;
    cost += pool1.getFerence()*ferenceCost;
    return cost-0.1;
}