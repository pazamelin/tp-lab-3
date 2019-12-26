#pragma once


class Circle {
private:
	double radius;
	double ference;
	double area;

public:
	Circle(double);
	void setRadius(double in_Rad);
	void setFerence(double in_Fer);
	void setArea(double in_Ar);
	double getRadius();
	double getFerence();
	double getArea();
};