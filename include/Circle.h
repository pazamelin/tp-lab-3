#pragma once
class Circle {
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double rad);
	void setRadius(double rad);
	void setFerence(double fer);
	void setArea(double area);
	double getRadius();
	double getFerence();
	double getArea();

};
