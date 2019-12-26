#include <iostream>
#include "Circle.h"
#include "task1.h"
int main() {

    double radius = 3;
    double trail = 1;

    double costOfConcrete = 1000;
    double costOfFence = 2000;

    Circle pool(radius);
    Circle trailAndPool(radius + trail);

    double cost1 = costOfConcrete * (trailAndPool.getArea() - pool.getArea());
    double cost2 = costOfFence * trailAndPool.getFerence();
    std::cout << cost1 + cost2 << std::endl;

    std::cout << calcCost();

    return 0;
}