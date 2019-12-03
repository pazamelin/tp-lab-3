//
// Created by Mary on 04.11.2019.
//
#include "DateTime.h"
#include <iostream>
using namespace std;
int main(){
    DateTime dateTime;

    cout << dateTime.getToday() << endl;
    cout << dateTime.getFuture(1) << endl;

    cout << endl;
    DateTime dt(31, 10, 2019);
    cout <<dt.getTomorrow()<<endl;
    cout <<dt.getToday() << endl;
    cout << dt.getYesterday()<<endl;
    cout << endl;

    DateTime date(20, 11, 2019);
    DateTime dif_date(30, 11, 2019);
    cout << date.getDifference(dif_date)<< endl;

    std::cout << std::endl;

    return 0;
}
