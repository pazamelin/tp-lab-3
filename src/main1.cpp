//
// Created by aklen on 10.11.2019.
//
#include <iostream>
#include "task1.h"
#include "Circle.h"
using namespace std;

int main(){
    double delta=calcDelta();
    cout<<"The gap between Earth and the rope is "<<delta<<" meters \n";
    double cost=calcCost();
    cout<<"Full cost is "<<cost<<" roubles "<<"\n";
    return 0;
}
