//
//  main2.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include "Circle.h"
#include <iostream>

double calcCost() {
    Circle pool(3), track(4);
    return double(1000 * (track.getArea() - pool.getArea())) + double(2000 * track.getFerence());
}

//int main() {
//    std::cout << calcCost() << std::endl;
//}
