#pragma once

#ifndef CIRCLE_H

#define CIRCLE_H

class Circle {
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double newRad);
	void setRadius(double newRad);
	void setFerence(double newFer);
	void setArea(double newArea);
	double getRadius();
	double getFerence();
	double getArea();
};

#endif