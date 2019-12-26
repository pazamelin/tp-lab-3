#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"
#include "task1.h"
#include <math.h>
#include <iostream>

#define PI 3.14159265

int main()
{


	Circle cir(10.0);
	cir.setRadius(2);
	std::cout << cir.getFerence() << "\n";
	cir.setFerence(3);
	std::cout << cir.getArea() << "\n";
	std::cout << "\n" << PI; 
	std::cout << "\n" << calcDelta();
 

	return 0;
}