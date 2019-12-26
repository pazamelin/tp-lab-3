//
// Created by Mikhail on 12.11.2019.
//

#include "DateTime.h"
#include "iostream"


int main(){
    DateTime dt(22,2,2019);
    std::cout << dt.getTomorrow() << '\n' << dt.getToday() << '\n';
    DateTime newDt(23, 12, 2019);
    std::cout << dt.getDifference(newDt) << '\n';

}