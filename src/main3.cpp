//
//  main.cpp
//  Third Shtanyuk's lab
//
//  Created by Коля on 16/12/2019.
//  Copyright © 2019 Коля. All rights reserved.
//

#include <iostream>
#include "DateTime.h"

int main(int argc, const char * argv[]) {
    DateTime dt(16,12,2019);
    std::cout << dt.getTomorrow();
    return 0;
}
