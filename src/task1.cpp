#include "Circle.h"

double calcDelta(){
	double const old_Rad = 6378.1 * 1000;
	Circle planet(old_Rad);
	planet.setFerence(planet.getFerence() + 1);
	double new_Rad = planet.getRadius();

	return (new_Rad - old_Rad);
}

double calcCost(){
	double pool_Rad = 3;
	Circle pool(pool_Rad);
	Circle fence(pool_Rad + 1);
	int const road_price_per_sqM = 1000;
	int const fence_price_per_pogM = 2000;
	double road_price = (fence.getArea() - pool.getArea()) * road_price_per_sqM;
	double fence_price = fence.getFerence() * fence_price_per_pogM;
 
	return road_price + fence_price;
}