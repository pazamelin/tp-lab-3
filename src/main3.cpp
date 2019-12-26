//
// Created by Илья on 005 05.11.19.
//
#include <iostream>
#include <string>
#include "DateTime.h"

using std::cout;
using std::endl;


int main(){
    DateTime t = DateTime(20, 11, 2019);
    DateTime t1 = DateTime();
    cout << t.getToday() << endl;
    cout << t1.getToday() << endl << endl;

    cout << t.getYesterday() << endl;
    cout << t1.getYesterday() << endl << endl;

    cout << t.getTomorrow() << endl;
    cout << t1.getTomorrow() << endl << endl;

    cout << t.getPast(5) << endl;
    cout << t1.getPast(30) << endl << endl;

    cout << t.getFuture(5) << endl;
    cout << t1.getFuture(30) << endl << endl;

    cout << t.getDifference(t1) << endl;
    cout << t1.getDifference(t) << endl << endl;

    cout << t.getToday() << endl;
    cout << t1.getToday() << endl << endl;

    return 0;
}
