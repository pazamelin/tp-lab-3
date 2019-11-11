//
// Created by Илья Соловьёв on 04.11.2019.
//

#include <iostream>
#include <math.h>
#include "Circle.h"
#include "DateTime.h"
#include <unistd.h>
#include <unistd.h>

using namespace std;

int main() {
    DateTime *date = new DateTime();
    cout << date->getToday() << endl;
    cout << date->getYesterday() << endl;
    cout << date->getTomorrow() << endl;
    cout << date->getFuture(3) << endl;
    cout << date->getFuture(24) << endl;
    cout << date->getPast(5) << endl;
    delete (date);
    cout << endl;

    date = new DateTime(10, 12, 2007);
    cout << date->getToday() << endl;
    cout << date->getYesterday() << endl;
    cout << date->getTomorrow() << endl;
    cout << date->getFuture(3) << endl;
    cout << date->getFuture(24) << endl;
    cout << date->getPast(5) << endl;
    delete (date);


    DateTime *date1 = new DateTime();
    sleep(1);
    DateTime *date2 = new DateTime();

    delete (date1);
    delete (date2);

    date1 = new DateTime(10, 12, 2008);
    date2 = new DateTime(10, 12, 2008);
    cout << date2->getDifference(*date1)<<endl;

    DateTime dt(31,10,2018);
    cout<<dt.getTomorrow();

    return 0;
}