#pragma once

class Circle
{
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double);
	void setRadius(double newrad);
	void setFerence(double newfer);
	void setArea(double newarea);
	double getRadius();
	double getFerence();
	double getArea() ;
};
