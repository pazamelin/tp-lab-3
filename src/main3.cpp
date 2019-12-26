//
// Created by aklen on 10.11.2019.
//
#include "DateTime.h"
#include <iostream>
using namespace std;

int main(){
    DateTime new_date(20,11,2018);
    DateTime new_date1(20,11,2018);
    cout<<new_date.getDifference(new_date1)<<"\n";
    cout<<new_date.getTomorrow()<<"\n";
    cout<<new_date.getFuture(3)<<"\n";
    return 0;
}
