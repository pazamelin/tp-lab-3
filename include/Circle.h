#ifndef _CIRCLE_H_
#define _CIRCLE_H_

constexpr double Pi = 3.1416;

class Circle
{
public:
	Circle(double radius);

	double getRadius() const;
	void setRadius(double radius);
	double getFerence() const;
	void setFerence(double ference);
	double getArea() const;
	void setArea(double area);

private:
	double radius;
	double ference;
	double area;
};

#endif _CIRCLE_H_
