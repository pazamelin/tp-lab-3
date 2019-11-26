#include "task1.h"
#include "Circle.h"

double calcDelta() 
{
	double earthRad = 6378100.0;
	double rope = 1.0;
	Circle Earth(earthRad);
	double	len = Earth.getFerence() + rope;
	Earth.setFerence(len);
	return Earth.getRadius() - earthRad;
}

double calcCost()
{
	double cementPrice = 1000.0;
	double wallPrice = 2000.0;
	Circle Swimpool(3.0);
	double sPool = Swimpool.getArea();
	//Swimpool.setRadius(3.0 + 1.0);
	Swimpool.setRadius(4.0);
	double cement = (Swimpool.getArea() - sPool) * cementPrice;
	double wall = Swimpool.getFerence() * wallPrice;
	return cement + wall;
}