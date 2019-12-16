//
//  task1.cpp
//  Third Shtanyuk's lab
//
//  Created by Коля on 16/12/2019.
//  Copyright © 2019 Коля. All rights reserved.
//

#include "task1.h"

#include "Circle.h"

double calcDelta()
{
    Circle earth(EARTHRAD);
    earth.setFerence(earth.getFerence() + 1);
    return earth.getRadius() - EARTHRAD;
}

double calcCost()
{
    Circle pool(3), track(4);
    return CONCTERECOST * (track.getArea() - pool.getArea()) + FENCECOST * track.getFerence();
}
