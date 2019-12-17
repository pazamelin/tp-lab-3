#include "task1.h"
#include "Circle.h"

double calcDelta()
{
    double radius = 6378.1;
    Circle earth(radius);
    Circle rope(0);
    rope.setFerence(earth.getFerence()+1);
    return double(rope.getRadius() - earth.getRadius());
}

double calcCost()
{
    double radius = 3;
    double trail = 1;
    double pre_cost_concrete = 1000;
    double pre_cost_fence = 2000;
    Circle pool(radius);
    Circle trailAndPool(radius + trail);
    double cost_concrete = pre_cost_concrete * (trailAndPool.getArea() - pool.getArea());
    double cost_fence = pre_cost_fence * trailAndPool.getFerence();
    return double(cost_concrete + cost_fence);
}
