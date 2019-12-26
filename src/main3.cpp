#include <iostream>
#include <ctime>
#include <vector>

#include "DateTime.h"

int main() {

    DateTime dt(31,10,2018);
    std::cout << "\n01 november 2018, thursday\n" << dt.getTomorrow() << std::endl;

    DateTime dt1(1,11,2018);
    std::cout << "\n02 november 2018, friday\n" << dt1.getTomorrow() << std::endl;

    DateTime dt2(1,11,2018);
    std::cout << "\n01 november 2018, thursday\n" << dt2.getToday() << std::endl;

    DateTime dt3(20,11,2018);
    DateTime dt4(20,11,2018);
    std::cout << "\n0\n" << dt3.getDifference(dt4) << std::endl;

    DateTime dt5(20,11,2018);
    DateTime dt6(21,11,2018);
    std::cout << "\n1\n" << dt5.getDifference(dt6) << std::endl;

    return 0;
}