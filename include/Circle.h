#ifndef _CIRCLE_H_
#define _CIRCLE_H_

constexpr double Pi = 3.1416;

class Circle
{
public:
	Circle(double radius);

	double getRadius();
	void setRadius(double radius);
	double getFerence();
	void setFerence(double ference);
	double getArea();
	void setArea(double area);

private:
	double radius;
	double ference;
	double area;
};

#endif _CIRCLE_H_
