#include "Circle.h"
#include <iostream>
#include "task1.h"

double calcDelta() { //- расчет зазора между землей и веревкой
	double E_rad = 6378.1;
	Circle bef(E_rad);
	Circle aftr(E_rad);
	aftr.setFerence(aftr.getFerence() + 1);
	return aftr.getRadius()-bef.getRadius();
}
double calcCost() {// - расчет стоимости бассейна
	const int price1 = 1000;
	const int price2 = 2000;
	Circle pool(3);
	double tmp = pool.getArea();
	pool.setRadius(4);
	double sum1 = (pool.getArea()-tmp) * price1;
	double sum2 = (pool.getFerence()) * price2;
	return sum1 + sum2;
}