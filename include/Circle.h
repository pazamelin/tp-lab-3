#ifndef CIRCLE_H
#define CIRCLE_H

const double pi = 3.14159265359;

class Circle
{
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double);

	void setRadius(double);
	void setFerence(double);
	void setArea(double);
	double getRadius();
	double getFerence();
	double getArea();
};

#endif