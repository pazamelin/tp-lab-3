//
//  main3.cpp
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include "DateTime.h"


int main() {
    DateTime today;
    std::cout << today.getToday() << std::endl;
    std::cout << today.getTomorrow() << std::endl;
    std::cout << today.getToday() << std::endl;
}
