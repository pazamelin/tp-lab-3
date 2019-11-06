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
    DateTime dt(31,10,2018);
    std::cout << dt.getTomorrow() << std::endl;
}
