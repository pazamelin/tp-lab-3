//
//  task1.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 06.11.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "task1.h"


double calcCost() {
    Circle pool(3), track(4);
    return double(1000 * (track.getArea() - pool.getArea())) + double(2000 * track.getFerence());
}

double calcDelta() {
    const double radius_before = 6378.1 * 1000;
    Circle earth(radius_before);
    double length_before = earth.getFerence();
    earth.setFerence(length_before + 1);
    return earth.getRadius() - radius_before;
    
}
