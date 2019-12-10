#include "Circle.h"
#include "task1.h"

using namespace std;

double calcDelta()
{
	double Eradius = 6378100;
	double LChange = 1;
	Circle Earth(Eradius);
	double NewFerence = Earth.getFerence() + LChange;
	Earth.setFerence(NewFerence);
	return Earth.getRadius() - Eradius;

}

double calcCost()
{
	double RoadCost = 1000;
	double WallCost = 2000;
	Circle pool(3);
	Circle poolRoad(4);
	double road = RoadCost * (poolRoad.getArea() - pool.getArea());
	double wall = poolRoad.getFerence() * WallCost;
	return wall + road;
}