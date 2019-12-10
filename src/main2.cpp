#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "Circle.h"
#define pi 3.1415

using namespace std;

int main()
{
    Circle poolInside(3.0);
    Circle poolOutside(4.0);
    cout << "Pool task result is " << (poolOutside.getArea() - poolInside.getArea()) * 1000.0 + poolOutside.getFerence() * 2000.0 << " rub\n";
    return 0;
}
