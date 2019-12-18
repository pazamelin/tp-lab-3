#include <iostream>
#include "Circle.h"
#include "task1.h"
#include "DateTime.h"


using namespace std;

int main(int argc, const char * argv[]) {
    cout << land_and_rope() << endl;
    cout << swimming_pool() << endl;
    DateTime data(18,01,2000);
    cout << "1 " << data.getTomorrow() << endl;
    cout << "2 " << data.getFuture(45) << endl;
    cout << "3 " << data.getYesterday() << endl;
    cout << "4 " << data.getPast(45) << endl;
    DateTime future(15,10,2078);
    cout << "5 " << data.getDifference(future) << endl;
    return 0;
}
