//
//  main1.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "Circle.h"
#include <iostream>

double calcDelta() {
    const double radius_before = 6378.1 * 1000;
    Circle earth(radius_before);
    double length_before = earth.getFerence();
    earth.setFerence(length_before + 1);
    return earth.getRadius() - radius_before;
    
}

int main() {
    std::cout << calcDelta() << std::endl;
}
