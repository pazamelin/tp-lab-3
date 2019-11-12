//
// Created by Mikhail on 12.11.2019.
//
#include <iostream>
#include "Circle.h"
#include <iomanip>
#include "task1.h"

int main(){
    Circle newCircle(12);
    std::cout << std::fixed << std::setprecision(4) << calcDelta() << '\n';
    std::cout << "Information about Circle: " <<  newCircle.getRadius() << ' ' << newCircle.getFerence() << ' ' << newCircle.getArea();
    return 0;
}