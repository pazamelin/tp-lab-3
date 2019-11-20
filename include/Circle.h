#pragma once

const double pi = 3.14;

class Circle
{
public:
	Circle(double R) {
		setRadius(R);
	}
	~Circle()
	{

	}
	void setRadius(double R);
	void setFerence(double F);
	void setArea(double A);
	double getRadius();
	double getFerence();
	double getArea();

private:
	double radius;
	double ference;
	double area;
	double round2(double R);

};
