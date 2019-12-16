#include"Circle.h"
#include <cmath>
#include "task1.h"
const double EARTH_RAD = 6378100;
const double swp_rad = 3.0;

double calcDelta() {
	Circle circle(EARTH_RAD);
	double new_ference = circle.getFerence() + 1;
	circle.setFerence(new_ference);
	double new_rad = circle.getRadius();
	double answer = new_rad - EARTH_RAD;
	return answer;
}

double calcCost() {
	
	Circle circle(swp_rad);
	double swp_area = circle.getArea();
	circle.setRadius(swp_rad + 1);
	double new_area = circle.getArea();// Area srimming pool + area trail
	double trail_area = new_area - swp_area;
	double trail_price = trail_area * 1000;
	double fence_price = circle.getFerence() * 2000;

	double answer = trail_price + fence_price;
	return answer;
}