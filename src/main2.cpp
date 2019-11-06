//
// Created by fiskirton on 11/5/19.
//

#include <iostream>
#include "task1.h"
#include "Circle.h"

using  namespace std;

int main(){

    double cost = calcCost();

    cout << cost << endl;

    Circle *circle = new Circle(10.0);

    cout << circle->getFerence() << endl;

    cout << circle->getArea() << endl;

    return 0;
}

