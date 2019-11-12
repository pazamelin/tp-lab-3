#include <iostream>
#include "Circle.h"
#include "task1.h"
int main() {
    double rad = 6378.1;
    Circle earth(rad);
    Circle rope(0);
    rope.setFerence(earth.getFerence()+1);
    double res = rope.getRadius() - earth.getRadius();
    std::cout << floor(res*1000)/1000 << std::endl;

    std::cout << calcDelta();

    return 0;
}