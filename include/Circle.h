#ifndef _CIRCLE_H
#define _CIRCLE_H_


class Circle
{
private:
	double radius;
	double ference;
	double area;
public:
	Circle(double _radius);
	void setRadius(double _radius);
	void setFerence(double _ference);
	void setArea(double _area);
	double getRadius();
	double getFerence();
	double getArea();
};
#endif
