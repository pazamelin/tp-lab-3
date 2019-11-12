#pragma once

class Circle {
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double);
	void setRadius(double r);
	void setFerence(double f);
	void setArea(double a);
	double getRadius();
	double getFerence();
	double getArea();
};