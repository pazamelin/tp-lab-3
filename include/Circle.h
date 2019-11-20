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
	double setRadius(double _radius);
	double setFerence(double _ference);
	double setArea(double _area);
	double getRadius();
	double getFerence();
	double getArea();
};
#endif
