#ifndef circle_h
#define circle_h

class Circle
{
private:
	double radius;

	double ference;
	
	double area;

public:
	Circle(double data);
	
	void setRadius(double data);
	
	void setFerence(double data);
	
	void setArea(double data);
	
	double getRadius();
	
	double getFerence();
	
	double getArea();
};
#endif