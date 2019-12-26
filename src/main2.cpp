//
// Created by Mikhail on 12.11.2019.
//
#include <iostream>
#include "Circle.h"
#include "task1.h"
#include <iomanip>

int main(){
    Circle newCircle(1);
    double cost = calcCost();
    double delta = calcDelta();
    std::cout << std::fixed << std::setprecision(4) << calcCost() << '\n';
    std::cout << "Information about Circle: " <<  newCircle.getRadius() << ' ' << newCircle.getFerence() << ' ' << newCircle.getArea();
    return 0;
}