#pragma once

class Circle {
	private:
		double radius;
		double ference; // length of cirlce
		double area; // square

	public:
		Circle(double);
		Circle();
		~Circle();

		void setRadius(double newRaduis);
		void setFerence(double newFerence);
		void setArea(double newArea);
		double getRadius();
		double getFerence();
		double getArea();
};