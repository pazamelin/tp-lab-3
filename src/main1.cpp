#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "Circle.h"
#define pi 3.1415

using namespace std;

int main()
{
    Circle earth(6378100.0);
    double earthRad = 6378100.0;
    earth.setFerence(earth.getFerence() + 1);
    cout << "Earth task result is " << earth.getRadius() - earthRad << endl;
    return 0;
}
