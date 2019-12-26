#pragma once

class Circle {
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double Radius);
	void setRadius(double Raduis);
	void setFerence(double Ference);
	void setArea(double Area);
	double getRadius();
	double getFerence();
	double getArea();
};
