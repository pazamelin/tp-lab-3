#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "DateTime.h"
#define pi 3.1415

using namespace std;

int main()
{
    DateTime t;
    cout<< t.getToday() ;
    DateTime u;
    DateTime h(1,10,2000);
    cout << '\n' << h.getToday() << t.getToday() << u.getToday();
    return 0;
}
