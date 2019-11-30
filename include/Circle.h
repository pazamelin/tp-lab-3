#pragma once

class Circle
{
public:
	Circle();
	Circle(double r);
	~Circle();

	void setRadius(double radius);
	void setFerence(double ference);
	void setArea(double area);

	double getRadius();
	double getFerence();
	double getArea();

private:
	double radius;
	double ference;
	double area;
};


