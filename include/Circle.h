#ifndef circleH
#define circleH


#include <cmath>

class Circle 
{
private:
	double radius,
		   ference,
		   area;
public:
	Circle(double ray);

	void setRadius(double ray);

	void setFerence(double circuit);

	void setArea(double square);

	double getRadius();

	double getFerence();

	double getArea();
};

#endif