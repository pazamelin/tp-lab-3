//
// Created by fiskirton on 11/5/19.
//

#include <iostream>
#include "DateTime.h"

using namespace std;

int main(){
    auto * dateTime = new DateTime();
    auto * dt = new DateTime(5, 11 , 2019);
    char *buf2 = dateTime->getTomorrow();
    char *buf = dateTime->getToday();
    char *buf3 = dateTime->getYesterday();
    char *buf4 = dateTime->getFuture(10);
    char *buf5 = dateTime->getPast(10);

    cout << buf << endl;
    cout << buf2 << endl;
    cout << buf3 << endl;
    cout << buf4 << endl;
    cout << buf5 << endl;
    cout << dateTime->getDifference(*dt) << endl;
    delete buf;
    delete buf2;
    delete buf3;
    delete buf4;
    delete buf5;

    return 0;
}
