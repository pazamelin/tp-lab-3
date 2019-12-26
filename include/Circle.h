#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
	double radius, ference, area;

public:
	Circle(double radius);
	~Circle();
	void setRadius(double radius);
	void setFerence(double ference);
	void setArea(double area);
	double getRadius();
	double getFerence();
	double getArea();
};

#endif 
