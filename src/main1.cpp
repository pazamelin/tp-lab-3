//
// Created by Mary on 04.11.2019.
//
#include "task1.h"
#include <iostream>
#include <Circle.h>

using namespace std;
int main(){
    Circle circle(10.0);
    cout << circle.getFerence()<<endl<<circle.getArea()<<endl;
    cout << endl;

    cout << calcDelta()<<endl<<calcCost()<<endl;
    Circle c(0.0);
    cout << c.getArea()<<endl;
}
