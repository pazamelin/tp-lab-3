#pragma once

class Circle {
	private:
		double radius;
		double ference; // length of cirlce
		double area; // square

	public:
		Circle(const double);
		Circle();
		~Circle();

		void setRadius(const double );
		void setFerence(const double );
		void setArea(const double );
		double getRadius();
		double getFerence();
		double getArea();
};