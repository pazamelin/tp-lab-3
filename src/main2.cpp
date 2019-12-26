#include "task1.h"
#include <iostream>
#include "Circle.h"
using namespace std;

int main() {
	Circle c(10.0);
	cout << c.getFerence() << endl;
	cout <<	c.getArea() << endl;
	double cost = calcCost();
	cout << cost << endl;
}