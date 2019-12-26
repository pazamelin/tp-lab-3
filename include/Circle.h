#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double r=0);
	void setRadius(double r);
	void setFerence(double f);
	void setArea(double a);
	double getRadius()const;
	double getFerence()const;
	double getArea()const;
};

#endif
