#include"Circle.h"


double calcDelta() {
	double EarthRadius = 6378.1;
	double gap = 0.001;
	Circle EarthRope(EarthRadius);
	double newFerence = EarthRope.getFerence() + gap;
	EarthRope.setFerence(newFerence);
	double ans = (EarthRope.getRadius() - EarthRadius) * 1000.0;
	return ans;
}

double calcCost() {
	double PoolRadius = 3.0;
	double RoadWidth = 1.0;
	Circle Pool(PoolRadius);
	Circle Road(PoolRadius + RoadWidth);
	double RoadCost = (Road.getArea() - Pool.getArea()) * 1000.0;
	double BorderCost = Road.getFerence() * 2000.0;
	double ans = RoadCost + BorderCost;
	return ans;
}