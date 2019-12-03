#ifndef __CIRCLE_H_
#define __CIRCLE_H_

class Circle
{
public:
	Circle();
	Circle(double r, double pi = 3.14);
	~Circle();

	void setRadius(double r);
	void setFerence(double f);
	void setArea(double a);

	double getRadius() { return radius; };
	double getFerence() { return ference; };
	double getArea() { return area; };

private:
	double radius;
	double ference;
	double area;

	double PI;

	void computeRadiusFromFerence();
	void computeRadiusFromArea();
	void computeFerence();
	void computeArea();
};

#endif

