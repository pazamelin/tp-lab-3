#include <iostream>
#include "DateTime.h"

using namespace std;

// демонстрация использования класса DateTime

int main(int argc, const char * argv[]) {
    DateTime data(18,01,2000);
    cout << data.getTomorrow() << endl;
    cout << data.getFuture(45) << endl;
    cout << data.getYesterday() << endl;
    cout << data.getPast(45) << endl;
    DateTime future(15,10,2078);
    cout << data.getDifference(future) << endl;
    return 0;
}
